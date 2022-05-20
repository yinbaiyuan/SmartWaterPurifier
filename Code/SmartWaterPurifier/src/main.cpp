// /Users/lawis/REPOSITORIES/esp/esp32-backtrace /Users/lawis/YCSPACE/11PROJECT/A016_SmartWaterPurifier/Code/SmartWaterPurifier/.pio/build/esp-wrover-kit/firmware.elf /Users/lawis/REPOSITORIES/esp/debug.txt
//*
#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#include <lvgl.h>
#include "ui.h"
#include <Wire.h>
#include "paj7620.h"
#include <DFRobot_PN532.h>

#include <SPIFFS.h>
#include "SPI.h"
#include "FS.h"

#include "AudioFileSourcePROGMEM.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2SNoDAC.h"
#include "viola.h"

AudioGeneratorWAV *wav;
AudioFileSourcePROGMEM *file;
AudioOutputI2SNoDAC *out;

#include <WiFi.h>
const char *ssid = "SSID";        //你的网络名称
const char *password = "password"; //你的网络密码

#define  PN532_IRQ      (2)
#define  POLLING        (0)

DFRobot_PN532_IIC  nfc(PN532_IRQ, POLLING);
uint32_t nfcCardUid = 0;

#define GES_REACTION_TIME		200				// You can adjust the reaction time according to the actual circumstance.
#define GES_ENTRY_TIME			300				// When you want to recognize the Forward/Backward gestures, your gestures' reaction time must less than GES_ENTRY_TIME(0.8s).
#define GES_QUIT_TIME			  1000

typedef struct{

  uint16_t waterIntake;
  uint16_t dateCode;
  uint8_t beginIndex;
  uint8_t endIndex;
  uint8_t intervalIndex;
  uint8_t planIndex;
  uint8_t tempIndex;
}person_info_t;

enum GestureType
{
    GT_NONE = 0,
    GT_UP = 1,
    GT_RIGHT,
    GT_DOWN,
    GT_LEFT,
    GT_FORWARD,
    GT_BACKWARD,
    GT_CLOCKWISE,
    GT_ANTI_CLOCKWISE,
    GT_WAVE,
};

GestureType GlobalGestureType = GT_NONE;

Arduino_DataBus *bus = new Arduino_ESP32SPI(27, 5, 18, 23, -1, HSPI);
Arduino_GFX *gfx = new Arduino_GC9A01(bus, 19, 0, true);

static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *disp_draw_buf;
static lv_disp_drv_t disp_drv;

static int8_t waterTemperature = 25;
static uint16_t waterTDS = 50;
static bool uvEnable = true;
static bool waterDirty = true;
static bool personalEnable = true;
person_info_t personInfo = {0};
person_info_t alarmPersonInfo = {0}; //TODO:只提醒最后一个接水的人，下次喝水时间，没有实现多人饮水情况
uint16_t alarmMinute = 0;
bool isAlarming = false;

#define PANEL_COUNT 6
int8_t panelPointer = 0;
lv_obj_t* panelArr[PANEL_COUNT];
lv_obj_t* rollerArr[PANEL_COUNT];

void gesturesDetect(void *pvParameters);
void controlTask(void *pvParameters);
void machineTask(void *pvParameters);
void waterPourOut(uint8_t temp,uint16_t flux);
void water_temperature_set(int8_t v);

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
  lv_disp_flush_ready(disp);
}

uint32_t intervalArr[10] = {30*60,60*60,90*60,120*60,150*60,180*60,210*60,240*60,300*60,360*60};
uint32_t getIntervalByIndex(uint8_t index)
{
  if (index <= 9)
  {
    return intervalArr[index];
  }
  return 0;
}

uint16_t planIntakeArr[12] = {250,500,750,1000,1250,1500,1750,2000,2250,2500,2750,3000};
uint16_t getPlanIntakeByIndex(uint8_t index)
{
  if (index < 12)
  {
    return planIntakeArr[index];
  }
  return 0;
}

uint16_t temperatureArr[9] = {25,25,35,45,55,65,75,85,95};
uint8_t getTemperatureByIndex(uint8_t index)
{
  if (index < 9)
  {
    return temperatureArr[index];
  }
  return 0;
}

void calcNextAlarmMinute()
{
  uint16_t tempMinute = 0;
  uint16_t beginMinute = alarmPersonInfo.beginIndex * 60;
  uint16_t endMinute = alarmPersonInfo.endIndex * 60;
  uint16_t intervalMinute = getIntervalByIndex(alarmPersonInfo.intervalIndex);
  for (tempMinute = beginMinute; tempMinute < endMinute; tempMinute+=intervalMinute)
  {
    if (tempMinute > alarmMinute)
    {
      alarmMinute = tempMinute;
      return;
    }
  }
  alarmMinute = beginMinute;
}

void lv_panel_slide_left_value(lv_obj_t * obj, int16_t value)
{
  lv_obj_t *scrObj = panelArr[panelPointer-1];
  lv_obj_t *desObj = panelArr[panelPointer];
  lv_obj_set_x(scrObj,-value);
  lv_obj_set_x(desObj,240-value);
  // Serial.printf("value :%d\n",value);
}

void left_slide_ani()
{
  if (panelPointer < PANEL_COUNT-1)
  {
    lv_obj_t *scrObj = panelArr[panelPointer];
    lv_obj_t *desObj = panelArr[panelPointer+1];
    if (!scrObj)
    {
      Serial.printf("scrObj is Null\n");
      return;
    }
    if (!desObj)
    {
      Serial.printf("desObj is Null\n");
      return;
    }
    
    lv_obj_clear_flag(scrObj,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(desObj,LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_x(scrObj,0);
    lv_obj_set_x(desObj,240);
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, panelArr[panelPointer++]);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_panel_slide_left_value);
    lv_anim_set_values(&a, 0, 240);
    lv_anim_set_time(&a, 500);
    lv_anim_start(&a);
  }
}

void lv_panel_slide_right_value(lv_obj_t * obj, int16_t value)
{
  lv_obj_t *scrObj = panelArr[panelPointer+1];
  lv_obj_t *desObj = panelArr[panelPointer];
  lv_obj_set_x(scrObj,value);
  lv_obj_set_x(desObj,value-240);
  // Serial.printf("value :%d\n",value);
}

void right_slide_ani()
{
  if (panelPointer > 0)
  {
    lv_obj_t *scrObj = panelArr[panelPointer];
    lv_obj_t *desObj = panelArr[panelPointer-1];
    if (!scrObj)
    {
      Serial.printf("scrObj is Null\n");
      return;
    }
    if (!desObj)
    {
      Serial.printf("desObj is Null\n");
      return;
    }
    
    lv_obj_clear_flag(scrObj,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(desObj,LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_x(scrObj,0);
    lv_obj_set_x(desObj,-240);
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, panelArr[panelPointer--]);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_panel_slide_right_value);
    lv_anim_set_values(&a, 0, 240);
    lv_anim_set_time(&a, 500);
    lv_anim_start(&a);
  }
}

void uv_light_show(bool e)
{
  if (e)
  {
    lv_obj_clear_flag(ui_imgUV,LV_OBJ_FLAG_HIDDEN);
  }else
  {
    lv_obj_add_flag(ui_imgUV,LV_OBJ_FLAG_HIDDEN);
  }
  uvEnable = e;
}

void waterdrop_light_show(bool e)
{
  if (e)
  {
    lv_obj_clear_flag(ui_imgWaterdrop,LV_OBJ_FLAG_HIDDEN);
  }else
  {
    lv_obj_add_flag(ui_imgWaterdrop,LV_OBJ_FLAG_HIDDEN);
  }
  waterDirty = e;
}

void arc_set_value_with_anim(int8_t v,uint16_t s = 500)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, ui_arcDrinkProgress);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_arc_set_value);
    lv_anim_set_values(&a, lv_arc_get_value(ui_arcDrinkProgress), v);
    lv_anim_set_time(&a, s);
    // lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
    lv_anim_start(&a);
}

void water_total_set(uint16_t v)
{
  personInfo.waterIntake = v;
  lv_label_set_text_fmt(ui_lbTotal,"%02d",personInfo.waterIntake);
}

void water_total_add(uint16_t v)
{
  water_total_set(personInfo.waterIntake+v);
  lv_arc_set_value(ui_arcDrinkProgress,personInfo.waterIntake * 100 / getPlanIntakeByIndex(personInfo.planIndex));
}

void total_light_show(bool e)
{
  if (e)
  {
    lv_obj_clear_flag(ui_lbTotal,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_lbTotalSymbol,LV_OBJ_FLAG_HIDDEN);
    water_total_set(personInfo.waterIntake);
    water_temperature_set(getTemperatureByIndex(personInfo.tempIndex));
    arc_set_value_with_anim(personInfo.waterIntake * 100 / getPlanIntakeByIndex(personInfo.planIndex));
    
  }else
  {
    lv_obj_add_flag(ui_lbTotal,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_lbTotalSymbol,LV_OBJ_FLAG_HIDDEN);
    water_temperature_set(25);
    arc_set_value_with_anim(100);
  }
  personalEnable = e;
}

void water_temperature_set(int8_t v)
{
  lv_label_set_text_fmt(ui_lbTemperature,"%02d",v);
  waterTemperature = v;
}

void water_tds_set(int16_t v)
{
  lv_label_set_text_fmt(ui_lbTDSValue,"%02d",v);
  waterTDS = v;
}

void readPersonInfo(uint32_t uid,person_info_t *info)
{
  info->waterIntake = 0;
  info->dateCode = 0;
  info->beginIndex = 8;
  info->endIndex = 20;
  info->intervalIndex = 3;
  info->planIndex = 7;
  info->tempIndex = 0;

  String path = "/" + String(uid);
  File file = SPIFFS.open(path.c_str(), FILE_READ);
  if(!file){ return;}

  size_t len = file.size();
  if (len<9){return;}
  
  uint8_t* buffer = (uint8_t* )malloc(len);
  size_t readLen = file.readBytes((char *)buffer,len);
  file.close();
  if (readLen < len)
  {
      delete buffer;
      return ;
  }
  info->waterIntake = buffer[0];
  info->waterIntake = info->waterIntake << 8;
  info->waterIntake += buffer[1];
  info->dateCode = buffer[2];
  info->dateCode = info->dateCode << 8;
  info->dateCode += buffer[3];
  info->beginIndex = buffer[4];
  info->endIndex = buffer[5];
  info->intervalIndex = buffer[6];
  info->planIndex = buffer[7];
  info->tempIndex = buffer[8];
  delete buffer;
}

void writePersonInfo(uint32_t uid,person_info_t info)
{
  uint8_t buffer[9];
  buffer[0] = info.waterIntake >> 8 & 0xFF;
  buffer[1] = info.waterIntake & 0xFF;
  buffer[2] = info.dateCode >> 8 & 0xFF;
  buffer[3] = info.dateCode & 0xFF;
  buffer[4] = info.beginIndex & 0xFF;
  buffer[5] = info.endIndex & 0xFF;
  buffer[6] = info.intervalIndex & 0xFF;
  buffer[7] = info.planIndex & 0xFF;
  buffer[8] = info.tempIndex & 0xFF;

  String path = "/" + String(uid);
  File file = SPIFFS.open(path.c_str(), FILE_WRITE);
  if(!file){return;}
  file.write(buffer,9);
  file.close();
}

void normalPanelShow()
{
  for (size_t i = 1; i < PANEL_COUNT; i++)
  {
      lv_obj_t *obj = panelArr[i];
      lv_obj_add_flag(obj,LV_OBJ_FLAG_HIDDEN);
      lv_obj_set_x(obj,240);
  }
  lv_obj_t *obj = panelArr[0];
  lv_obj_clear_flag(obj,LV_OBJ_FLAG_HIDDEN);
  lv_obj_set_x(obj,0);
  panelPointer = 0;
}

// void gauge_anim(lv_obj_t *arc, int16_t value)
// {
//   Serial.println("called gauge_anim!!!");
// }
// static void my_timer(lv_timer_t *timer)
// {
//   //   lv_arc_set_value(ui_Arc1,20);



//   Serial.println("called my_timer!!!");
// }

void personInfoSetByRoller(uint8_t panelIndex,uint8_t rollerIndex)
{
  switch (panelIndex)
  {
  case 1:
    personInfo.beginIndex = rollerIndex;
    break;
  case 2:
    personInfo.endIndex = rollerIndex;
    break;
  case 3:
    personInfo.intervalIndex = rollerIndex;
    break;
  case 4:
    personInfo.planIndex = rollerIndex;
    break;
  case 5:
    personInfo.tempIndex = rollerIndex;
    break;
  default:
    break;
  }
}


void setup()
{
  Serial.begin(115200);

  SPIFFS.begin(true);

  gfx->begin();
  gfx->fillScreen(BLACK);

  pinMode(15, OUTPUT);//临时给手势传感器供电
  digitalWrite(15, HIGH);

  pinMode(17, OUTPUT);
  digitalWrite(17, HIGH);

  lv_init();

  screenWidth = gfx->width();
  screenHeight = gfx->height();
  disp_draw_buf = (lv_color_t *)malloc(sizeof(lv_color_t) * screenWidth * 150);
  if (!disp_draw_buf)
  {
    Serial.println("LVGL disp_draw_buf allocate failed!");
    return;
  }

  lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * 150);
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  lv_indev_drv_register(&indev_drv);

  ui_init();

  panelArr[0] = ui_panelNormal;
  panelArr[1] = ui_panelSetting1;
  panelArr[2] = ui_panelSetting2;
  panelArr[3] = ui_panelSetting3;
  panelArr[4] = ui_panelSetting4;
  panelArr[5] = ui_panelSetting5;

  rollerArr[0] = nullptr;
  rollerArr[1] = ui_roller1;
  rollerArr[2] = ui_roller2;
  rollerArr[3] = ui_roller3;
  rollerArr[4] = ui_roller4;
  rollerArr[5] = ui_roller5;

  // uv_light_show(false);
  lv_obj_add_flag(ui_lbTotal,LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(ui_lbTotalSymbol,LV_OBJ_FLAG_HIDDEN);
  arc_set_value_with_anim(100,2000);
  waterdrop_light_show(false);
  lv_arc_set_value(ui_arcDrinkProgress,0);

  water_temperature_set(25);
  water_tds_set(18);
  water_total_set(0);
  normalPanelShow();

  delay(500);
  
  total_light_show(false);

  xTaskCreatePinnedToCore(gesturesDetect,"gesturesDetect",8192,NULL,1,NULL,0);
  xTaskCreatePinnedToCore(controlTask,"controlTask",8192,NULL,1,NULL,0);  //16384      
  xTaskCreatePinnedToCore(machineTask,"machineTask",8192,NULL,1,NULL,0);         
}

void loop()
{
  // Serial.printf("loop\n");
  if (GlobalGestureType != GT_NONE)
  {
    Serial.printf("GestureType:%d\n",GlobalGestureType);
    //进行操作逻辑
    switch (GlobalGestureType)
    {
    case GT_LEFT:
      if (personalEnable)
      {
        left_slide_ani();
      }
      break;
    case GT_RIGHT:
      if (personalEnable)
      {
        right_slide_ani();
      }
      break;
    case GT_UP:
    {
      if (panelPointer>0 && panelPointer<PANEL_COUNT)
      {
        lv_obj_t *roller = rollerArr[panelPointer];
        uint16_t index = lv_roller_get_selected(roller);
        uint16_t count = lv_roller_get_option_cnt(roller);
        if (++index == count)
        {
          index = 0;
        }
        personInfoSetByRoller(panelPointer,index);
        lv_roller_set_selected(roller,index,LV_ANIM_ON);
      }else
      {
        if (nfcCardUid != 0)
        {
          water_total_set(0);
          water_total_add(0);
        }
      }
    }
      break;
    case GT_DOWN:
    {
      if (panelPointer>0 && panelPointer<PANEL_COUNT)
      {
        lv_obj_t *roller = rollerArr[panelPointer];
        uint16_t index = lv_roller_get_selected(roller);
        uint16_t count = lv_roller_get_option_cnt(roller);
        if (index-- == 0)
        {
          index = count - 1;
        }
        personInfoSetByRoller(panelPointer,index);
        lv_roller_set_selected(roller,index,LV_ANIM_ON);
      }else
      {
        if (nfcCardUid != 0)
        {
          waterPourOut(25,240);  
        }
      }
    }
      break;
    default:
      break;
    }
    GlobalGestureType = GT_NONE;
    // lv_label_set_text_fmt(ui_lbTemperature,"%02d",waterTemperature);
  }
  // lv_arc_set_value(ui_arcDrinkProgress,waterTemperature);
  lv_timer_handler();
  vTaskDelay(5);
}

void gesturesDetect(void *pvParameters)
{
  uint8_t error = paj7620Init();			// initialize Paj7620 registers
	if (error)
	{
		Serial.print("INIT ERROR,CODE:");
		Serial.println(error);
	}
	else
	{
		Serial.println("INIT OK");
	}

  while (!nfc.begin()) {
    Serial.println("initial failure");
    delay (1000);
  }

  while (1)
  {
    uint8_t data = 0, data1 = 0, error;
    GestureType gestureType = GT_NONE;
    error = paj7620ReadReg(0x43, 1, &data);				// Read Bank_0_Reg_0x43/0x44 for gesture result.
    if (!error)
    {
      switch (data) 									// When different gestures be detected, the variable 'data' will be set to different values by paj7620ReadReg(0x43, 1, &data).
      {
        case GES_RIGHT_FLAG:
          vTaskDelay(GES_ENTRY_TIME);
          paj7620ReadReg(0x43, 1, &data);
          if(data == GES_FORWARD_FLAG)
          {
            gestureType = GT_FORWARD;
            vTaskDelay(GES_QUIT_TIME);
          }
          else if(data == GES_BACKWARD_FLAG)
          {
            gestureType = GT_BACKWARD;
            vTaskDelay(GES_QUIT_TIME);
          }
          else
          {
            gestureType = GT_RIGHT;
          }
          break;
        case GES_LEFT_FLAG:
          vTaskDelay(GES_ENTRY_TIME);
          paj7620ReadReg(0x43, 1, &data);
          if(data == GES_FORWARD_FLAG)
          {
            gestureType = GT_FORWARD;
            vTaskDelay(GES_QUIT_TIME);
          }
          else if(data == GES_BACKWARD_FLAG)
          {
            gestureType = GT_BACKWARD;
            vTaskDelay(GES_QUIT_TIME);
          }
          else
          {
            gestureType = GT_LEFT;
          }
          break;
        case GES_UP_FLAG:
          vTaskDelay(GES_ENTRY_TIME);
          paj7620ReadReg(0x43, 1, &data);
          if(data == GES_FORWARD_FLAG)
          {
            gestureType = GT_FORWARD;
            vTaskDelay(GES_QUIT_TIME);
          }
          else if(data == GES_BACKWARD_FLAG)
          {
            gestureType = GT_BACKWARD;
            vTaskDelay(GES_QUIT_TIME);
          }
          else
          {
            gestureType = GT_UP;
          }
          break;
        case GES_DOWN_FLAG:
          vTaskDelay(GES_ENTRY_TIME);
          paj7620ReadReg(0x43, 1, &data);
          if(data == GES_FORWARD_FLAG)
          {
            gestureType = GT_FORWARD;
            vTaskDelay(GES_QUIT_TIME);
          }
          else if(data == GES_BACKWARD_FLAG)
          {
            gestureType = GT_BACKWARD;
            vTaskDelay(GES_QUIT_TIME);
          }
          else
          {
            gestureType = GT_DOWN;
          }
          break;
        case GES_FORWARD_FLAG:
          gestureType = GT_FORWARD;
          vTaskDelay(GES_QUIT_TIME);
          break;
        case GES_BACKWARD_FLAG:
          gestureType = GT_BACKWARD;
          vTaskDelay(GES_QUIT_TIME);
          break;
        case GES_CLOCKWISE_FLAG:
          gestureType = GT_CLOCKWISE;
          break;
        case GES_COUNT_CLOCKWISE_FLAG:
          gestureType = GT_ANTI_CLOCKWISE;
          break;
        default:
          paj7620ReadReg(0x44, 1, &data1);
          if (data1 == GES_WAVE_FLAG)
          {
            gestureType = GT_WAVE;
          }
          break;
      }
    }
    GlobalGestureType = gestureType;

    if (nfc.scan()) {
      uint32_t tUid = nfc.getUid();
      if (tUid != UINT32_MAX && (nfcCardUid != tUid || nfcCardUid == 0))
      {
        nfcCardUid = tUid;
        total_light_show(true);
        readPersonInfo(nfcCardUid,&personInfo);
        lv_roller_set_selected(ui_roller1,personInfo.beginIndex,LV_ANIM_OFF);
        lv_roller_set_selected(ui_roller2,personInfo.endIndex,LV_ANIM_OFF);
        lv_roller_set_selected(ui_roller3,personInfo.intervalIndex,LV_ANIM_OFF);
        lv_roller_set_selected(ui_roller4,personInfo.planIndex,LV_ANIM_OFF);
        lv_roller_set_selected(ui_roller4,personInfo.tempIndex,LV_ANIM_OFF);
        Serial.printf("UID: %08x\n",nfcCardUid);
      }
    }else
    {
      if (nfcCardUid != 0)
      {
        total_light_show(false);
        writePersonInfo(nfcCardUid,personInfo);
        alarmPersonInfo = personInfo;
        writePersonInfo(UINT32_MAX,alarmPersonInfo);

        normalPanelShow();
        
        Serial.printf("UID: %08x Left\n",nfcCardUid);
        nfcCardUid = 0;
      }
    }
    vTaskDelay(10);
  }
  vTaskDelete(NULL);
}
#define NTP1 "ntp1.aliyun.com"
#define NTP2 "ntp2.aliyun.com"
#define NTP3 "ntp3.aliyun.com"

uint16_t getNowMinute()
{
  struct tm timeInfo; //声明一个结构体
  if (!getLocalTime(&timeInfo))
  {
    Serial.println("Failed to obtain time");
    return UINT16_MAX;
  }
  return timeInfo.tm_hour * 60 + timeInfo.tm_min;
}

void controlTask(void *pvParameters)
{
	WiFi.begin(ssid, password); //连接网络
  while (WiFi.status() != WL_CONNECTED) //等待网络连接成功
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");
  configTime(8 * 3600, 0, NTP1, NTP2, NTP3);
  readPersonInfo(UINT32_MAX,&alarmPersonInfo);
  calcNextAlarmMinute();

  out = new AudioOutputI2SNoDAC();//目前实际音质很差，噪音太大，如果为了更好的音质，可以增加独立DAC芯片，走I2S数值输出通道
  out->SetPinout(26,25,16);
  wav = new AudioGeneratorWAV();
  while (1)
  {
    if (!isAlarming)
    {
       if (1)//getNowMinute() == alarmMinute
       {
          file = new AudioFileSourcePROGMEM( viola, sizeof(viola) );
          wav->begin(file, out);
          
          // if (wav->isRunning()) {
          //   if (!wav->loop()) wav->stop();
          // } else {
          //   Serial.printf("WAV done\n");
          //   delay(1000);
          // }

          isAlarming = true;
       }else
       {
         vTaskDelay(1000);
       }
    }else{
      while (wav->isRunning())
      {
        if(!wav->loop())
        {
          wav->stop();
        }
        vTaskDelay(1);
      }
      delete file;
      isAlarming = false;
    }
  }
  vTaskDelete(NULL);
}

#include <SoftwareSerial.h>
SoftwareSerial CBSerial;//工控板串口
SoftwareSerial OBSerial;//操作板串口

#define OB_PB_SIZE    24
uint8_t OBProtoBuffer[OB_PB_SIZE];


void obpb_init()
{
  memset(OBProtoBuffer,0,OB_PB_SIZE);
  // TODO 未公开协议，请自行分析
}

void setWaterTemp(uint8_t v)
{
  uint16_t v10 = v * 10;
  OBProtoBuffer[9] = v10 >> 8 & 0xFF; //出水温度
  OBProtoBuffer[10] = v10 & 0xFF;
}

void setMachineEnable(bool e)
{
  OBProtoBuffer[16] = e?0x01:0x00;
}

void sendOBPB()
{
  obpb_init();
  uint8_t verify = 0;
  for (size_t i = 0; i < OB_PB_SIZE-1; i++)
  {
    verify += OBProtoBuffer[i];
  }
  // Serial.printf("%02x\n",verify);
  OBProtoBuffer[OB_PB_SIZE-1] = verify;

  for (size_t i = 0; i < OB_PB_SIZE; i++)
  {
    CBSerial.write(OBProtoBuffer[i]);//
    //  Serial.write(OBProtoBuffer[i]);
  }
}

bool pouroutStart = false;
uint8_t pouroutTemp = 0;
uint16_t pouroutFlux = 0;
uint32_t beginTime = 0;
uint32_t pouroutTime = 0;

void waterPourOutAction()
{
  if (millis() - beginTime < pouroutTime)
  {
    setWaterTemp(pouroutTemp);
    setMachineEnable(true);
    sendOBPB();
    if (personalEnable)
    {
      // personInfo.waterIntake += 2;
      water_total_add(2);
    }
  }else
  {
    setMachineEnable(false);
    sendOBPB();
    pouroutStart = false;
  } 
}

void waterPourOut(uint8_t temp,uint16_t flux)
{
  if (pouroutStart)
  {
    return;
  }
  pouroutStart = true;
  pouroutTemp = temp;
  pouroutFlux = flux;
  pouroutTime = flux / (228 / 60.0) * 1000 / 4;//2为流量校正参数
  beginTime = millis();
}

std::vector<String> commandParse(String command)
{
  std::vector<String> result;
  int indexof; //找查的位置
  String temps;//临时字符串
  do
  {
      indexof = command.indexOf(',');//找到位置
      if(indexof != -1)//如果位置不为空
      {
          temps=command.substring(0,indexof);//打印取第一个字符
          command = command.substring(indexof+1, command.length());
          //分隔后只取后面一段内容 以方便后面找查
      }
      else
      {  //上面实在找不到了就把最后的 一个分割值赋值出来以免遗漏
         if(command.length() > 0)
          temps=command;
      }
      result.push_back(temps);
      // Serial.println(temps);//在这里执行分割出来的字符下面不然又清空了
      temps="";
   }
   while(indexof >=0);
   return result;
}

void machineTask(void *pvParameters)
{
  CBSerial.begin(19200 , SWSERIAL_8N1 , 33, 32 , false , 256);
  OBSerial.begin(19200 , SWSERIAL_8N1 , 12, 14 , false , 256);

  while (1)
  {

    if (!pouroutStart)
    {
      while (OBSerial.available() > 0) {
        byte d = OBSerial.read();
        CBSerial.write(d);
        // Serial.write(d);
      }
    }else
    {
      // waterPourOut(pouroutTemp,pouroutFlux);  
      waterPourOutAction();
    }

    delay(100);
    
    while (CBSerial.available() > 0) {
      byte d = CBSerial.read();
      OBSerial.write(d);
      // Serial.write(d);
    }
    // if (Serial.available() > 0)
    // {
    //   String command = "";
    //   while (Serial.available() > 0) {
    //     byte d = Serial.read();
    //     command += String((char)d);
    //   }
    //   std::vector<String> result = commandParse(command);
    //   // Serial.println(result[0]);
    //   if (String("PourOut").equals(result[0]))
    //   {
    //     waterPourOut(result[1].toInt(),result[2].toInt());
    //   }
    // }
    delay(40);
  }
  vTaskDelete(NULL);
}

//*/