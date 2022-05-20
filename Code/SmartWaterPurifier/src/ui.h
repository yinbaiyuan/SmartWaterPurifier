// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: waterPurifierUI

#ifndef _WATERPURIFIERUI_UI_H
#define _WATERPURIFIERUI_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

extern lv_obj_t * ui_scrMain;
extern lv_obj_t * ui_panelMain;
extern lv_obj_t * ui_arcDrinkProgress;
extern lv_obj_t * ui_panelCenter;
extern lv_obj_t * ui_panelNormal;
extern lv_obj_t * ui_lbTemperature;
extern lv_obj_t * ui_lbTempSymbol;
extern lv_obj_t * ui_lbTDSValue;
extern lv_obj_t * ui_lbTDSSymbol;
extern lv_obj_t * ui_imgUV;
extern lv_obj_t * ui_imgWaterdrop;
extern lv_obj_t * ui_lbTotal;
extern lv_obj_t * ui_lbTotalSymbol;
extern lv_obj_t * ui_panelSetting1;
extern lv_obj_t * ui_imgTitle1;
extern lv_obj_t * ui_roller1;
extern lv_obj_t * ui_panelSetting2;
extern lv_obj_t * ui_imgTitle2;
extern lv_obj_t * ui_roller2;
extern lv_obj_t * ui_panelSetting3;
extern lv_obj_t * ui_imgTitle3;
extern lv_obj_t * ui_roller3;
extern lv_obj_t * ui_panelSetting4;
extern lv_obj_t * ui_imgTitle4;
extern lv_obj_t * ui_roller4;
extern lv_obj_t * ui_panelSetting5;
extern lv_obj_t * ui_imgTitle5;
extern lv_obj_t * ui_roller5;


LV_IMG_DECLARE(ui_img_uvlight_png);    // assets/uvlight.png
LV_IMG_DECLARE(ui_img_waterdrop_png);    // assets/waterdrop.png
LV_IMG_DECLARE(ui_img_img_begin_png);    // assets/img_begin.png
LV_IMG_DECLARE(ui_img_img_end_png);    // assets/img_end.png
LV_IMG_DECLARE(ui_img_img_interval_png);    // assets/img_interval.png
LV_IMG_DECLARE(ui_img_img_plan_png);    // assets/img_plan.png
LV_IMG_DECLARE(ui_img_img_temp_png);    // assets/img_temp.png


LV_FONT_DECLARE(ui_font_LESLIE135);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
