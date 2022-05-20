// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: waterPurifierUI

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_scrMain;
lv_obj_t * ui_panelMain;
lv_obj_t * ui_arcDrinkProgress;
lv_obj_t * ui_panelCenter;
lv_obj_t * ui_panelNormal;
lv_obj_t * ui_lbTemperature;
lv_obj_t * ui_lbTempSymbol;
lv_obj_t * ui_lbTDSValue;
lv_obj_t * ui_lbTDSSymbol;
lv_obj_t * ui_imgUV;
lv_obj_t * ui_imgWaterdrop;
lv_obj_t * ui_lbTotal;
lv_obj_t * ui_lbTotalSymbol;
lv_obj_t * ui_panelSetting1;
lv_obj_t * ui_imgTitle1;
lv_obj_t * ui_roller1;
lv_obj_t * ui_panelSetting2;
lv_obj_t * ui_imgTitle2;
lv_obj_t * ui_roller2;
lv_obj_t * ui_panelSetting3;
lv_obj_t * ui_imgTitle3;
lv_obj_t * ui_roller3;
lv_obj_t * ui_panelSetting4;
lv_obj_t * ui_imgTitle4;
lv_obj_t * ui_roller4;
lv_obj_t * ui_panelSetting5;
lv_obj_t * ui_imgTitle5;
lv_obj_t * ui_roller5;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "#error LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_scrMain_screen_init(void)
{

    // ui_scrMain

    ui_scrMain = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_scrMain, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_scrMain, lv_color_hex(0x464B55), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_scrMain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_scrMain, lv_color_hex(0x2D323C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_scrMain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_panelMain

    ui_panelMain = lv_obj_create(ui_scrMain);

    lv_obj_set_width(ui_panelMain, 240);
    lv_obj_set_height(ui_panelMain, 240);

    lv_obj_set_x(ui_panelMain, 0);
    lv_obj_set_y(ui_panelMain, 0);

    lv_obj_set_align(ui_panelMain, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_panelMain, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_panelMain, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panelMain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_panelMain, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_arcDrinkProgress

    ui_arcDrinkProgress = lv_arc_create(ui_panelMain);

    lv_obj_set_width(ui_arcDrinkProgress, 240);
    lv_obj_set_height(ui_arcDrinkProgress, 240);

    lv_obj_set_x(ui_arcDrinkProgress, 0);
    lv_obj_set_y(ui_arcDrinkProgress, 0);

    lv_obj_set_align(ui_arcDrinkProgress, LV_ALIGN_CENTER);

    lv_arc_set_range(ui_arcDrinkProgress, 0, 100);
    lv_arc_set_value(ui_arcDrinkProgress, 50);
    lv_arc_set_bg_angles(ui_arcDrinkProgress, 120, 60);

    lv_obj_set_style_radius(ui_arcDrinkProgress, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_arcDrinkProgress, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_arcDrinkProgress, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_arcDrinkProgress, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_arcDrinkProgress, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_arcDrinkProgress, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_arcDrinkProgress, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_arcDrinkProgress, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_arcDrinkProgress, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_arcDrinkProgress, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_arcDrinkProgress, lv_color_hex(0x36B9F6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_arcDrinkProgress, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_arcDrinkProgress, 7, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_arcDrinkProgress, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_arcDrinkProgress, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_panelCenter

    ui_panelCenter = lv_obj_create(ui_scrMain);

    lv_obj_set_width(ui_panelCenter, 210);
    lv_obj_set_height(ui_panelCenter, 210);

    lv_obj_set_x(ui_panelCenter, 0);
    lv_obj_set_y(ui_panelCenter, 0);

    lv_obj_set_align(ui_panelCenter, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_panelCenter, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_panelCenter, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_panelCenter, lv_color_hex(0x3C414B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panelCenter, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_panelCenter, lv_color_hex(0x323232), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_panelCenter, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_panelCenter, lv_color_hex(0x2D323C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_panelCenter, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_panelCenter, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_panelCenter, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_panelCenter, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_panelCenter, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_panelCenter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_panelNormal

    ui_panelNormal = lv_obj_create(ui_panelCenter);

    lv_obj_set_width(ui_panelNormal, 210);
    lv_obj_set_height(ui_panelNormal, 210);

    lv_obj_set_x(ui_panelNormal, 0);
    lv_obj_set_y(ui_panelNormal, 0);

    lv_obj_set_align(ui_panelNormal, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_panelNormal, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_panelNormal, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_panelNormal, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_panelNormal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panelNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_panelNormal, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_lbTemperature

    ui_lbTemperature = lv_label_create(ui_panelNormal);

    lv_obj_set_width(ui_lbTemperature, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_lbTemperature, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_lbTemperature, 0);
    lv_obj_set_y(ui_lbTemperature, 5);

    lv_obj_set_align(ui_lbTemperature, LV_ALIGN_CENTER);

    lv_label_set_text(ui_lbTemperature, "88");

    lv_obj_set_style_text_color(ui_lbTemperature, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lbTemperature, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lbTemperature, &ui_font_LESLIE135, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_lbTemperature, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_lbTemperature, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_lbTemperature, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_lbTemperature, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_lbTempSymbol

    ui_lbTempSymbol = lv_label_create(ui_panelNormal);

    lv_obj_set_width(ui_lbTempSymbol, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_lbTempSymbol, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_lbTempSymbol, 76);
    lv_obj_set_y(ui_lbTempSymbol, 42);

    lv_obj_set_align(ui_lbTempSymbol, LV_ALIGN_CENTER);

    lv_label_set_text(ui_lbTempSymbol, "°C");

    lv_obj_set_style_text_color(ui_lbTempSymbol, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lbTempSymbol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lbTempSymbol, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_lbTempSymbol, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_lbTempSymbol, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_lbTDSValue

    ui_lbTDSValue = lv_label_create(ui_panelNormal);

    lv_obj_set_width(ui_lbTDSValue, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_lbTDSValue, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_lbTDSValue, 0);
    lv_obj_set_y(ui_lbTDSValue, 70);

    lv_obj_set_align(ui_lbTDSValue, LV_ALIGN_CENTER);

    lv_label_set_text(ui_lbTDSValue, "18");

    lv_obj_set_style_text_color(ui_lbTDSValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lbTDSValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lbTDSValue, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_lbTDSSymbol

    ui_lbTDSSymbol = lv_label_create(ui_panelNormal);

    lv_obj_set_width(ui_lbTDSSymbol, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_lbTDSSymbol, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_lbTDSSymbol, 0);
    lv_obj_set_y(ui_lbTDSSymbol, 92);

    lv_obj_set_align(ui_lbTDSSymbol, LV_ALIGN_CENTER);

    lv_label_set_text(ui_lbTDSSymbol, "TDS");

    lv_obj_set_style_text_color(ui_lbTDSSymbol, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lbTDSSymbol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lbTDSSymbol, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_imgUV

    ui_imgUV = lv_img_create(ui_panelNormal);
    lv_img_set_src(ui_imgUV, &ui_img_uvlight_png);

    lv_obj_set_width(ui_imgUV, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgUV, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgUV, -45);
    lv_obj_set_y(ui_imgUV, 70);

    lv_obj_set_align(ui_imgUV, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_imgUV, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_imgUV, LV_OBJ_FLAG_SCROLLABLE);

    // ui_imgWaterdrop

    ui_imgWaterdrop = lv_img_create(ui_panelNormal);
    lv_img_set_src(ui_imgWaterdrop, &ui_img_waterdrop_png);

    lv_obj_set_width(ui_imgWaterdrop, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgWaterdrop, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgWaterdrop, 45);
    lv_obj_set_y(ui_imgWaterdrop, 70);

    lv_obj_set_align(ui_imgWaterdrop, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_imgWaterdrop, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_imgWaterdrop, LV_OBJ_FLAG_SCROLLABLE);

    // ui_lbTotal

    ui_lbTotal = lv_label_create(ui_panelNormal);

    lv_obj_set_width(ui_lbTotal, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_lbTotal, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_lbTotal, 0);
    lv_obj_set_y(ui_lbTotal, -84);

    lv_obj_set_align(ui_lbTotal, LV_ALIGN_CENTER);

    lv_label_set_text(ui_lbTotal, "5020");

    lv_obj_set_style_text_color(ui_lbTotal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lbTotal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lbTotal, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_lbTotalSymbol

    ui_lbTotalSymbol = lv_label_create(ui_panelNormal);

    lv_obj_set_width(ui_lbTotalSymbol, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_lbTotalSymbol, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_lbTotalSymbol, 0);
    lv_obj_set_y(ui_lbTotalSymbol, -64);

    lv_obj_set_align(ui_lbTotalSymbol, LV_ALIGN_CENTER);

    lv_label_set_text(ui_lbTotalSymbol, "ml");

    lv_obj_set_style_text_color(ui_lbTotalSymbol, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lbTotalSymbol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lbTotalSymbol, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_panelSetting1

    ui_panelSetting1 = lv_obj_create(ui_panelCenter);

    lv_obj_set_width(ui_panelSetting1, 210);
    lv_obj_set_height(ui_panelSetting1, 210);

    lv_obj_set_x(ui_panelSetting1, 0);
    lv_obj_set_y(ui_panelSetting1, 0);

    lv_obj_set_align(ui_panelSetting1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_panelSetting1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_panelSetting1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_panelSetting1, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_panelSetting1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panelSetting1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_panelSetting1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_imgTitle1

    ui_imgTitle1 = lv_img_create(ui_panelSetting1);
    lv_img_set_src(ui_imgTitle1, &ui_img_img_begin_png);

    lv_obj_set_width(ui_imgTitle1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgTitle1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgTitle1, 0);
    lv_obj_set_y(ui_imgTitle1, -77);

    lv_obj_set_align(ui_imgTitle1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_imgTitle1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_imgTitle1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_roller1

    ui_roller1 = lv_roller_create(ui_panelSetting1);
    lv_roller_set_options(ui_roller1,
                          "00:00\n01:00\n02:00\n03:00\n04:00\n05:00\n06:00\n07:00\n08:00\n09:00\n10:00\n11:00\n12:00\n13:00\n14:00\n15:00\n16:00\n17:00\n18:00\n19:00\n20:00\n21:00\n22:00\n23:00",
                          LV_ROLLER_MODE_INFINITE);

    lv_obj_set_height(ui_roller1, 120);
    lv_obj_set_width(ui_roller1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_roller1, 0);
    lv_obj_set_y(ui_roller1, 0);

    lv_obj_set_align(ui_roller1, LV_ALIGN_CENTER);

    lv_obj_set_style_text_color(ui_roller1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_roller1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_roller1, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_roller1, &lv_font_montserrat_40, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller1, lv_color_hex(0x0DBFD2), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller1, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_roller1, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_roller1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_roller1, true, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_roller1, lv_color_hex(0x37E5F5), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_roller1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller1, 3, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_roller1, LV_BORDER_SIDE_BOTTOM, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // ui_panelSetting2

    ui_panelSetting2 = lv_obj_create(ui_panelCenter);

    lv_obj_set_width(ui_panelSetting2, 210);
    lv_obj_set_height(ui_panelSetting2, 210);

    lv_obj_set_x(ui_panelSetting2, 0);
    lv_obj_set_y(ui_panelSetting2, 0);

    lv_obj_set_align(ui_panelSetting2, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_panelSetting2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_panelSetting2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_panelSetting2, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_panelSetting2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panelSetting2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_panelSetting2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_imgTitle2

    ui_imgTitle2 = lv_img_create(ui_panelSetting2);
    lv_img_set_src(ui_imgTitle2, &ui_img_img_end_png);

    lv_obj_set_width(ui_imgTitle2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgTitle2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgTitle2, 0);
    lv_obj_set_y(ui_imgTitle2, -77);

    lv_obj_set_align(ui_imgTitle2, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_imgTitle2, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_imgTitle2, LV_OBJ_FLAG_SCROLLABLE);

    // ui_roller2

    ui_roller2 = lv_roller_create(ui_panelSetting2);
    lv_roller_set_options(ui_roller2,
                          "00:00\n01:00\n02:00\n03:00\n04:00\n05:00\n06:00\n07:00\n08:00\n09:00\n10:00\n11:00\n12:00\n13:00\n14:00\n15:00\n16:00\n17:00\n18:00\n19:00\n20:00\n21:00\n22:00\n23:00",
                          LV_ROLLER_MODE_INFINITE);

    lv_obj_set_height(ui_roller2, 120);
    lv_obj_set_width(ui_roller2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_roller2, 0);
    lv_obj_set_y(ui_roller2, 0);

    lv_obj_set_align(ui_roller2, LV_ALIGN_CENTER);

    lv_obj_set_style_text_color(ui_roller2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_roller2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_roller2, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_roller2, &lv_font_montserrat_40, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller2, lv_color_hex(0x0DBFD2), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller2, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_roller2, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_roller2, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_roller2, true, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_roller2, lv_color_hex(0x37E5F5), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_roller2, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller2, 3, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_roller2, LV_BORDER_SIDE_BOTTOM, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // ui_panelSetting3

    ui_panelSetting3 = lv_obj_create(ui_panelCenter);

    lv_obj_set_width(ui_panelSetting3, 210);
    lv_obj_set_height(ui_panelSetting3, 210);

    lv_obj_set_x(ui_panelSetting3, 0);
    lv_obj_set_y(ui_panelSetting3, 0);

    lv_obj_set_align(ui_panelSetting3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_panelSetting3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_panelSetting3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_panelSetting3, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_panelSetting3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panelSetting3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_panelSetting3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_imgTitle3

    ui_imgTitle3 = lv_img_create(ui_panelSetting3);
    lv_img_set_src(ui_imgTitle3, &ui_img_img_interval_png);

    lv_obj_set_width(ui_imgTitle3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgTitle3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgTitle3, 0);
    lv_obj_set_y(ui_imgTitle3, -77);

    lv_obj_set_align(ui_imgTitle3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_imgTitle3, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_imgTitle3, LV_OBJ_FLAG_SCROLLABLE);

    // ui_roller3

    ui_roller3 = lv_roller_create(ui_panelSetting3);
    lv_roller_set_options(ui_roller3,
                          "30 min\n1 Hour\n90 min\n2 Hours\n150 min\n3 Hours\n210 min\n4 Hours\n5 Hours\n6 Hours", LV_ROLLER_MODE_INFINITE);

    lv_obj_set_height(ui_roller3, 120);
    lv_obj_set_width(ui_roller3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_roller3, 0);
    lv_obj_set_y(ui_roller3, 0);

    lv_obj_set_align(ui_roller3, LV_ALIGN_CENTER);

    lv_obj_set_style_text_color(ui_roller3, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_roller3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_roller3, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_roller3, &lv_font_montserrat_40, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller3, lv_color_hex(0x0DBFD2), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller3, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_roller3, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_roller3, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_roller3, true, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_roller3, lv_color_hex(0x37E5F5), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_roller3, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller3, 3, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_roller3, LV_BORDER_SIDE_BOTTOM, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // ui_panelSetting4

    ui_panelSetting4 = lv_obj_create(ui_panelCenter);

    lv_obj_set_width(ui_panelSetting4, 210);
    lv_obj_set_height(ui_panelSetting4, 210);

    lv_obj_set_x(ui_panelSetting4, 0);
    lv_obj_set_y(ui_panelSetting4, 0);

    lv_obj_set_align(ui_panelSetting4, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_panelSetting4, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_panelSetting4, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_panelSetting4, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_panelSetting4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panelSetting4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_panelSetting4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_imgTitle4

    ui_imgTitle4 = lv_img_create(ui_panelSetting4);
    lv_img_set_src(ui_imgTitle4, &ui_img_img_plan_png);

    lv_obj_set_width(ui_imgTitle4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgTitle4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgTitle4, 0);
    lv_obj_set_y(ui_imgTitle4, -77);

    lv_obj_set_align(ui_imgTitle4, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_imgTitle4, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_imgTitle4, LV_OBJ_FLAG_SCROLLABLE);

    // ui_roller4

    ui_roller4 = lv_roller_create(ui_panelSetting4);
    lv_roller_set_options(ui_roller4,
                          "250ml\n500ml\n750ml\n1000ml\n1250ml\n1500ml\n1750ml\n2000ml\n2250ml\n2500ml\n2750ml\n3000ml", LV_ROLLER_MODE_INFINITE);

    lv_obj_set_height(ui_roller4, 120);
    lv_obj_set_width(ui_roller4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_roller4, 0);
    lv_obj_set_y(ui_roller4, 0);

    lv_obj_set_align(ui_roller4, LV_ALIGN_CENTER);

    lv_obj_set_style_text_color(ui_roller4, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_roller4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_roller4, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_roller4, &lv_font_montserrat_40, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller4, lv_color_hex(0x0DBFD2), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller4, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_roller4, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_roller4, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_roller4, true, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_roller4, lv_color_hex(0x37E5F5), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_roller4, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller4, 3, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_roller4, LV_BORDER_SIDE_BOTTOM, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // ui_panelSetting5

    ui_panelSetting5 = lv_obj_create(ui_panelCenter);

    lv_obj_set_width(ui_panelSetting5, 210);
    lv_obj_set_height(ui_panelSetting5, 210);

    lv_obj_set_x(ui_panelSetting5, 0);
    lv_obj_set_y(ui_panelSetting5, 0);

    lv_obj_set_align(ui_panelSetting5, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_panelSetting5, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_panelSetting5, 105, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_panelSetting5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_panelSetting5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_panelSetting5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_imgTitle5

    ui_imgTitle5 = lv_img_create(ui_panelSetting5);
    lv_img_set_src(ui_imgTitle5, &ui_img_img_temp_png);

    lv_obj_set_width(ui_imgTitle5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_imgTitle5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_imgTitle5, 0);
    lv_obj_set_y(ui_imgTitle5, -77);

    lv_obj_set_align(ui_imgTitle5, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_imgTitle5, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_imgTitle5, LV_OBJ_FLAG_SCROLLABLE);

    // ui_roller5

    ui_roller5 = lv_roller_create(ui_panelSetting5);
    lv_roller_set_options(ui_roller5, "Default\n25\n35\n45\n55\n65\n75\n85\n95", LV_ROLLER_MODE_INFINITE);

    lv_obj_set_height(ui_roller5, 120);
    lv_obj_set_width(ui_roller5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_roller5, 0);
    lv_obj_set_y(ui_roller5, 0);

    lv_obj_set_align(ui_roller5, LV_ALIGN_CENTER);

    lv_obj_set_style_text_color(ui_roller5, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_roller5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_roller5, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_roller5, &lv_font_montserrat_40, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_roller5, lv_color_hex(0x0DBFD2), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_roller5, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_roller5, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_roller5, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_roller5, true, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_roller5, lv_color_hex(0x37E5F5), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_roller5, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_roller5, 3, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_roller5, LV_BORDER_SIDE_BOTTOM, LV_PART_SELECTED | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_scrMain_screen_init();
    lv_disp_load_scr(ui_scrMain);
}

