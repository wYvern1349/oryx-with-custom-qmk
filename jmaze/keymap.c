#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

bool alpha_pressed = false; // variable for timer to disable arcane key functionality after no letter has been pressed for x amount of time
uint16_t arcane_timer = 0;     // timer 
uint16_t last_key_manual = 0; // for timer reset and adaptive keys
uint16_t last_mod_manual = 0; // for timer reset and adaptive keys
bool shift_trigger = false; //was key shifted?
bool dot_trigger = false; //dot pressed previously?
bool b_trigger = false;
bool c_trigger = false;
bool g_trigger = false;
bool l_trigger = false;
bool s_trigger = false;
bool u_trigger = false;
bool y_trigger = false;
bool z_trigger = false;

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ARCANE_L,
  ARCANE_J,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_TAB,         KC_LEFT_GUI,                                    KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_LEFT_ALT,    KC_RIGHT_CTRL,  KC_RIGHT_SHIFT, KC_Q,           
    OSL(6),         OSL(1),         KC_F,           KC_C,           KC_D,           KC_K,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_DOT,         ST_MACRO_0,     
    KC_ENTER,       KC_N,           KC_S,           KC_T,           KC_H,           KC_G,                                           KC_Z,           KC_R,           KC_E,           KC_I,           KC_A,           RCTL(KC_BSPC),  
    TO(2),          KC_Y,           KC_M,           KC_B,           KC_W,           KC_P,                                           OSL(1),         ARCANE_J,       OSL(6),         KC_COMMA,       KC_V,           KC_BSPC,        
                                                    ARCANE_L,       OSL(5),                                         OSL(4),         KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_Q,           
    KC_TRANSPARENT, QK_LLCK,        KC_F,           KC_C,           KC_D,           KC_K,                                           KC_X,           KC_L,           KC_O,           KC_U,           KC_DOT,         KC_QUOTE,       
    KC_TRANSPARENT, KC_N,           KC_S,           KC_T,           KC_H,           KC_G,                                           KC_Z,           KC_R,           KC_E,           KC_I,           KC_A,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Y,           KC_M,           KC_B,           KC_W,           KC_P,                                           QK_LLCK,        KC_J,           KC_TRANSPARENT, KC_COMMA,       KC_V,           KC_TRANSPARENT, 
                                                    KC_LEFT_SHIFT,  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_F5,          
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_F2,          
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_MINUS,       KC_ENTER,       
    TD(DANCE_0),    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         TD(DANCE_1),    KC_F8,          
                                                    KC_SPACE,       KC_LEFT_ALT,                                    OSL(4),         TO(0)
  ),
  [3] = LAYOUT_voyager(
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         TD(DANCE_2),    KC_F5,          KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_F5,          KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_LEFT_ALT,                                    TO(0),          KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_CTRL,   KC_5,           KC_6,           KC_LEFT_SHIFT,                                  KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_COLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_DELETE,                                      QK_LLCK,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_BSPC,        
    KC_TRANSPARENT, KC_SLASH,       KC_7,           KC_8,           KC_9,           LCTL(KC_DELETE),                                KC_PGDN,        TO(0),          KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_TRANSPARENT, 
                                                    KC_0,           OSL(5),                                         KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    LALT(KC_F4),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(3),          LCTL(KC_X),     LCTL(KC_C),     KC_LEFT_CTRL,   LCTL(KC_V),     LGUI(KC_V),                                     LSFT(KC_QUOTE), ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     KC_TRANSPARENT, 
    LSFT(KC_ENTER), OSL(8),         LSFT(KC_TAB),   KC_LEFT_ALT,    KC_TAB,         KC_DELETE,                                      ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     US_EACU,        ST_MACRO_8,     KC_TRANSPARENT, 
    TO(9),          OSL(7),         KC_QUOTE,       KC_GRAVE,       KC_CIRC,        LSFT(KC_GRAVE),                                 ST_MACRO_9,     US_CCED,        ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    KC_NO,          
                                                    TO(0),          KC_TRANSPARENT,                                 TO(0),          KC_MINUS
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_3),    KC_PLUS,        KC_UNDS,        US_LABK,        US_RABK,                                        RSFT(KC_6),     KC_LCBR,        KC_LBRC,        KC_RBRC,        KC_RCBR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MINUS,       KC_QUES,        ST_MACRO_13,    KC_EXLM,        TD(DANCE_4),                                    KC_AMPR,        KC_SCLN,        KC_LPRN,        KC_RPRN,        US_SECT,        KC_BSPC,        
    KC_NO,          KC_AT,          ST_MACRO_14,    KC_HASH,        KC_ASTR,        KC_TILD,                                        TD(DANCE_5),    KC_COLN,        KC_TRANSPARENT, KC_BSLS,        KC_PERC,        KC_TRANSPARENT, 
                                                    KC_EQUAL,       KC_PIPE,                                        TO(0),          KC_SLASH
  ),
  [7] = LAYOUT_voyager(
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                                          KC_PSCR,        KC_NUM,         KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_NO,          
    KC_NO,          KC_NO,          KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_Y),     KC_TRANSPARENT,                                 KC_SCRL,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_KP_EQUAL,    
    KC_TRANSPARENT, KC_TRANSPARENT, RCTL(KC_F),     LCTL(KC_A),     LCTL(KC_S),     LGUI(LSFT(KC_S)),                                KC_APPLICATION, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_COMMA,    KC_KP_ENTER,    
    KC_NO,          KC_TRANSPARENT, LGUI(KC_D),     LCTL(KC_P),     LGUI(KC_E),     KC_TRANSPARENT,                                 KC_INSERT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_DOT,      KC_NO,          
                                                    KC_TRANSPARENT, TO(0),                                          KC_TRANSPARENT, KC_KP_0
  ),
  [8] = LAYOUT_voyager(
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,                                          KC_TRANSPARENT, ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,    ST_MACRO_18,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,                                          ST_MACRO_19,    ST_MACRO_20,    ST_MACRO_21,    RSFT(US_EACU),  ST_MACRO_22,    KC_BSPC,        
    KC_NO,          KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,                                         ST_MACRO_23,    LSFT(US_CCED),  ST_MACRO_24,    ST_MACRO_25,    ST_MACRO_26,    KC_NO,          
                                                    KC_TRANSPARENT, TO(0),                                          TO(0),          KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(0),          
                                                    KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  ),
};





extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,255}, {41,131,255}, {41,255,255}, {41,255,166}, {0,0,255}, {40,189,183}, {188,255,255}, {124,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,255}, {236,255,255}, {40,189,183}, {41,255,166}, {41,255,166}, {41,255,255}, {41,131,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,255}, {124,255,255}, {152,255,255}, {189,255,255}, {152,255,255}, {152,255,255}, {41,138,120}, {89,255,255}, {0,0,255} },

    [1] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {188,255,255}, {152,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {0,0,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {0,245,245}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {0,0,255}, {236,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {124,255,255}, {0,0,255}, {152,255,255}, {124,255,255}, {188,255,255}, {124,255,255}, {124,255,255}, {0,0,255}, {74,255,255}, {0,0,255} },

    [2] = { {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,245,245}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,245,245}, {0,245,245}, {0,245,245}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {116,255,255}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {116,255,255}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,0,255}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {116,255,255}, {74,255,255}, {152,255,255} },

    [3] = { {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,255,255}, {20,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {20,255,255}, {20,255,255}, {20,255,255}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {20,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {20,255,255}, {20,255,255}, {20,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,255} },

    [4] = { {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {188,255,255}, {41,255,255}, {74,255,255}, {74,255,255}, {41,131,255}, {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {0,255,255}, {95,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {74,255,255}, {236,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {20,255,255}, {0,0,255}, {95,255,255}, {0,0,0}, {152,255,255}, {20,255,255}, {20,255,255}, {20,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {152,255,255}, {188,255,255}, {95,255,255}, {95,255,255}, {0,0,0}, {0,0,0}, {0,0,255} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {20,255,255}, {0,255,255}, {0,255,255}, {41,255,255}, {0,255,255}, {0,255,255}, {41,138,120}, {116,255,255}, {0,0,255}, {41,255,166}, {0,0,255}, {0,0,255}, {134,255,34}, {0,73,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {0,0,0}, {236,255,255}, {152,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {0,0,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {0,0,0}, {152,255,255}, {181,255,255} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {181,255,255}, {188,255,255}, {188,255,255}, {181,255,255}, {0,0,0}, {188,255,255}, {181,255,255}, {0,0,0}, {181,255,255}, {181,255,255}, {0,0,0}, {181,255,255}, {188,255,255}, {181,255,255}, {181,255,255}, {181,255,255}, {181,255,255}, {181,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {181,255,255}, {188,255,255}, {181,255,255}, {181,255,255}, {188,255,255}, {0,0,0}, {181,255,255}, {188,255,255}, {181,255,255}, {181,255,255}, {188,255,255}, {0,0,255}, {181,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {181,255,255}, {0,0,0}, {152,255,255}, {181,255,255} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,73,255}, {0,73,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,73,255}, {0,73,255}, {0,73,255}, {0,73,255}, {0,0,0}, {0,0,0}, {0,73,255}, {0,73,255}, {0,73,255}, {0,0,0}, {0,0,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {95,255,255}, {0,0,0} },

    [8] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {116,255,255}, {116,255,255}, {116,255,255}, {116,255,255}, {0,0,0}, {0,0,0}, {116,255,255}, {116,255,255}, {116,255,255}, {116,255,255}, {0,0,0}, {0,0,0}, {116,255,255}, {116,255,255}, {116,255,255}, {116,255,255}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {0,0,0}, {236,255,255}, {152,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {0,0,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {0,0,0}, {152,255,255}, {0,0,0} },

    [9] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,34}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
        break;
      case 5:
        set_layer_color(5);
        break;
      case 6:
        set_layer_color(6);
        break;
      case 7:
        set_layer_color(7);
        break;
      case 8:
        set_layer_color(8);
        break;
      case 9:
        set_layer_color(9);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}



typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[6];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_I); break;
        case DOUBLE_HOLD: register_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_I); break;
        case DOUBLE_HOLD: unregister_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case DOUBLE_TAP: register_code16(KC_BSLS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_LDAQ);
        tap_code16(US_LDAQ);
        tap_code16(US_LDAQ);
    }
    if(state->count > 3) {
        tap_code16(US_LDAQ);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_LDAQ); break;
        case DOUBLE_TAP: register_code16(US_RDAQ); break;
        case DOUBLE_SINGLE_TAP: tap_code16(US_LDAQ); register_code16(US_LDAQ);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_LDAQ); break;
        case DOUBLE_TAP: unregister_code16(US_RDAQ); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(US_LDAQ); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DLR);
        tap_code16(KC_DLR);
        tap_code16(KC_DLR);
    }
    if(state->count > 3) {
        tap_code16(KC_DLR);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_DLR); break;
        case DOUBLE_TAP: register_code16(US_EURO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DLR); register_code16(KC_DLR);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_DLR); break;
        case DOUBLE_TAP: unregister_code16(US_EURO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DLR); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_DEG);
        tap_code16(US_DEG);
        tap_code16(US_DEG);
    }
    if(state->count > 3) {
        tap_code16(US_DEG);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(US_DEG); break;
        case DOUBLE_TAP: register_code16(US_MICR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(US_DEG); register_code16(US_DEG);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(US_DEG); break;
        case DOUBLE_TAP: unregister_code16(US_MICR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(US_DEG); break;
    }
    dance_state[5].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case ARCANE_L:
        case ARCANE_J:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_MINS:
        case KC_DEL:
        case KC_UNDS:
        case KC_COMMA:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case ARCANE_L:
        case ARCANE_J:
            return false;  // Ignore ALTREP keys. If this is not here, only default action will be done, since the process stuff is apparently run after the remember last key stuff, so that the key is only ever trying to repeat itself.
    }

    return true;  // Other keys can be repeated.
}

static void process_arcane_l(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_RSFT(SS_TAP(X_V)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_RSFT(SS_TAP(X_V)));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_V));
          }
          break;        
        case KC_B:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("EC");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("ec");
          } else { //unshifted previous key
              send_string("ec");
          }
         break;
        case KC_C:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("C");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("ommunity");
          } else { //unshifted previous key
              send_string("c");
          }
         break;
        case KC_D:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("D");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("ank");
          } else { //unshifted previous key
              send_string("d");
          }
         break;
       case KC_E:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("E");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("-Mail");
          } else { //unshifted previous key
              send_string("e");
          }
         break;
        case KC_F:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("F");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("rau");
           } else { //unshifted previous key
              send_string("f");
          }
         break;
        case KC_G:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("H");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_R) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_U) SS_RALT(SS_TAP(X_S)) SS_TAP(X_E));
          } else { //unshifted previous key
              send_string("h");
          }
         break;
        case KC_H:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_LSFT(SS_TAP(X_T)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_LSFT(SS_TAP(X_T)));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_T));
          }
         break;
        case KC_I:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_LSFT(SS_TAP(X_E)) SS_LSFT(SS_TAP(X_O)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_LSFT(SS_TAP(X_E)) SS_TAP(X_O));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_E) SS_TAP(X_O));
          }
         break;
        case KC_J: 
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_R)) SS_RSFT(SS_TAP(X_R)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_R) SS_TAP(X_R));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_R) SS_TAP(X_R));
          }
         break;
        case KC_K:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_K)) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_O)) SS_RSFT(SS_TAP(X_N)) SS_RSFT(SS_TAP(X_N)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_K)) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_O) SS_TAP(X_N) SS_TAP(X_N));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_K) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_O) SS_TAP(X_N) SS_TAP(X_N));
          }
         break;
        case KC_L:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("Z");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("iebe");
          } else { //unshifted previous key
              send_string("z");
          }
         break;
        case KC_M:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("M");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("itglied");
          } else { //unshifted previous key
              send_string("m");
          }
         break;
        case KC_N:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("N");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("UM");
          } else { //unshifted previous key
              send_string("n");
          }
         break;
        case KC_O:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("O");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("ber");
          } else { //unshifted previous key
              send_string("o");
          }
         break;
        case KC_P:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("P");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("rof.");
              //set_oneshot_mods(MOD_BIT(KC_LSFT));
          } else { //unshifted previous key
              send_string("p");
          }
         break;
        case KC_R:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("L");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("l");
          } else { //unshifted previous key
              send_string("l");
          }
         break;
        case KC_S:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("S");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_LSFT(SS_TAP(X_H)) SS_TAP(X_E) SS_TAP(X_R) SS_TAP(X_R));
          } else { //unshifted previous key
              send_string("s");
          }
         break;
        case KC_T:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("T");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("ag");
          } else { //unshifted previous key
              send_string("t");
          }
         break;
        case KC_U:
             if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_RSFT(SS_TAP(X_I)));
            } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_RSFT(SS_TAP(X_I)));
            } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_I));
            }
          break;
        case KC_V:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_RSFT(SS_TAP(X_A)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_A));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_A));
          }
         break;
        case KC_W:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_LSFT(SS_TAP(X_H)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_H));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_H));
          }
        break;
        case KC_X:
           if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_LSFT(SS_TAP(X_D)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_X) SS_LSFT(SS_TAP(X_D)));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_D));
          }
         break;
          case KC_Y:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_RSFT(SS_TAP(X_N)));
            } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_RSFT(SS_TAP(X_N)));
            } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_N));
            }
          break;
        case KC_Z:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_LSFT(SS_TAP(X_L)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_L));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_L));
          }
         break;        
        case KC_COMMA: //I'm using this as a "get one-shot shift to trigger within a word" key for abbreviations and the like... could wait for the timer to run out, but I lack the patience.
            if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC)); //erases comma since I don't actually want it, just using it as a trigger for the two lines following
              alpha_pressed = false; //basically ends the timer for the arcane functionality prematurely
              set_oneshot_mods(MOD_BIT(KC_LSFT)); //activates one-shot shift
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC));
              alpha_pressed = false;
              set_oneshot_mods(MOD_BIT(KC_LSFT));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC));
              alpha_pressed = false;
              set_oneshot_mods(MOD_BIT(KC_LSFT));
          }
        break;
      default: set_oneshot_mods(MOD_BIT(KC_LSFT));
    }
}

static void process_arcane_j(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_RSFT(SS_TAP(X_A)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_A));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_A));
          }
          break;        
        case KC_B:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("B");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("b");
          } else { //unshifted previous key
              send_string("b");
          }
         break;
        case KC_C:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("Y");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("y");
          } else { //unshifted previous key
              send_string("y");
          }
         break;
        case KC_D:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("W");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("w");
          } else { //unshifted previous key
              send_string("w");
          }
         break;
        case KC_F:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("Y");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("y");
           } else { //unshifted previous key
              send_string("y");
          }
         break;
        case KC_G:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("K");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_R) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_U) SS_RALT(SS_TAP(X_S)) SS_TAP(X_E));
          } else { //unshifted previous key
              send_string("k");
          }
         break;
        case KC_H:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_LSFT(SS_TAP(X_W)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_LSFT(SS_TAP(X_H)) SS_TAP(X_E) SS_TAP(X_R) SS_TAP(X_R));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_W));
          }
         break;
        case KC_K:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_K)) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_O)) SS_RSFT(SS_TAP(X_N)) SS_RSFT(SS_TAP(X_N)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_K)) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_O) SS_TAP(X_N) SS_TAP(X_N));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_K) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_O) SS_TAP(X_N) SS_TAP(X_N));
          }
         break;
        case KC_M:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("S");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("itglied");
          } else { //unshifted previous key
              send_string("s");
          }
         break;
        case KC_N:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("Y");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("UM");
          } else { //unshifted previous key
              send_string("y");
          }
         break;
        case KC_P:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("F");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("rof.");
              //set_oneshot_mods(MOD_BIT(KC_LSFT));
          } else { //unshifted previous key
              send_string("f");
          }
         break;
        case KC_T:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("C");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("ag");
          } else { //unshifted previous key
              send_string("c");
          }
         break;
        case KC_U:
             if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_RSFT(SS_TAP(X_V)));
            } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_RSFT(SS_TAP(X_V)));
            } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_V));
            }
          break;
        case KC_V:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_RSFT(SS_TAP(X_U)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_U));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_U));
          }
         break;  
       default: 
         if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_RSFT(SS_TAP(X_J)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_J));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_J));        
          }
         set_last_keycode(KC_J);
         break; 
      }
  }

void matrix_scan_user(void) { // The very important timer.
  if (alpha_pressed && timer_elapsed(arcane_timer) > 1000) { //triggers when timer elapsed
      alpha_pressed = false;
      shift_trigger = false; 
      dot_trigger = false;
      b_trigger = false;
      c_trigger = false;
      g_trigger = false;
      l_trigger = false;
      s_trigger = false;
      u_trigger = false;
      y_trigger = false;
      z_trigger = false;
      set_last_keycode(KC_SPACE);
  } else { //timer update
    switch (get_last_keycode()) {
      case KC_A ... KC_Z:
      case KC_SCLN:
      case KC_COMMA:
      case KC_DOT:
        if (last_key_manual != get_last_keycode()) {
          last_key_manual = get_last_keycode();
          last_mod_manual = get_last_mods();
          alpha_pressed = true;
          arcane_timer = timer_read();
        }
      break; //these were all the keys that keep the timer going
      case KC_SPACE:
      case KC_ENTER:
      case KC_BSPC:
      case RCTL(KC_BSPC):
      last_key_manual = get_last_keycode();
      alpha_pressed = false;
      shift_trigger = false; 
      dot_trigger = false;
      b_trigger = false;
      c_trigger = false;
      g_trigger = false;
      l_trigger = false;
      s_trigger = false;
      u_trigger = false;
      y_trigger = false;
      z_trigger = false;
      break; //these were all the keys that end the timer prematurely
    }
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_DOT:
      if (record->event.pressed && layer_state_is(0)) {
        shift_trigger = false;
        dot_trigger = true;
        b_trigger = false;
        c_trigger = false;
        g_trigger = false;
        l_trigger = false;
        s_trigger = false;
        u_trigger = false;
        y_trigger = false;
        z_trigger = false;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          shift_trigger = true;
        }
      }
    break; 
    case KC_B:
      if (record->event.pressed && layer_state_is(0)) {
        shift_trigger = false;
        dot_trigger = false;
        b_trigger = true;
        c_trigger = false;
        g_trigger = false;
        l_trigger = false;
        s_trigger = false;
        u_trigger = false;
        y_trigger = false;
        z_trigger = false;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          shift_trigger = true;
        }
      }
    break; 
    case KC_C:
      if (record->event.pressed && layer_state_is(0)) {
        shift_trigger = false;
        dot_trigger = false;
        b_trigger = false;
        c_trigger = true;
        g_trigger = false;
        l_trigger = false;
        s_trigger = false;
        u_trigger = false;
        y_trigger = false;
        z_trigger = false;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          shift_trigger = true;
        }
      }
    break; 
    case KC_D:
      if (record->event.pressed && layer_state_is(0)) {
        switch (last_key_manual){
          case KC_C:
          if (is_caps_word_on()){
            SEND_STRING(SS_LSFT(SS_TAP(X_T)));
          } else if (last_mod_manual & MOD_MASK_SHIFT){
            SEND_STRING(SS_TAP(X_D));
          } else {
            SEND_STRING(SS_TAP(X_T));
          }
            c_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_T);
            return false;
          break;
          case KC_F:
          if (is_caps_word_on()){
            SEND_STRING(SS_LSFT(SS_TAP(X_S)));
          } else if (last_mod_manual & MOD_MASK_SHIFT){
            SEND_STRING(SS_TAP(X_S));
          } else {
            SEND_STRING(SS_TAP(X_S));
          }
            c_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_S);
            return false;
          break;
          default:
          shift_trigger = false;
          dot_trigger = false;
          b_trigger = false;
          c_trigger = false;
          g_trigger = false;
          l_trigger = false;
          s_trigger = false;
          u_trigger = false;
          y_trigger = false;
          z_trigger = false;
          if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            shift_trigger = true;
          }
          break;
        }
      }
    break; 
    case KC_F:
      if (record->event.pressed && layer_state_is(0)) {
        if (g_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_LSFT(SS_TAP(X_G)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_G));
          } else {
            SEND_STRING(SS_TAP(X_G));
          }
            g_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_G);
            return false;
        } else {
          shift_trigger = false;
          dot_trigger = false;
          b_trigger = false;
          c_trigger = false;
          g_trigger = false;
          l_trigger = false;
          s_trigger = false;
          u_trigger = false;
          y_trigger = false;
          z_trigger = false;
          if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            shift_trigger = true;
          }
        }
      }
    break; 
    case KC_G:
      if (record->event.pressed && layer_state_is(0)) {
        if (s_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_LSFT(SS_TAP(X_M)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_M));
          } else {
            SEND_STRING(SS_TAP(X_M));
          }
            s_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_M);
            return false;
        } else {
          shift_trigger = false;
          dot_trigger = false;
          b_trigger = false;
          c_trigger = false;
          g_trigger = true;
          l_trigger = false;
          s_trigger = false;
          u_trigger = false;
          y_trigger = false;
          z_trigger = false;
          if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            shift_trigger = true;
          }
        }
      }
    break; 
    case KC_H:
      if (record->event.pressed && layer_state_is(0)) {
        if (l_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_LSFT(SS_TAP(X_L)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_L));
          } else {
            SEND_STRING(SS_TAP(X_L));
          }
            l_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_L);
            return false;
        } else if (y_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_TAP(X_BSPC) SS_RALT(SS_TAP(X_S)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_BSPC) SS_RALT(SS_TAP(X_S)));
          } else {
            SEND_STRING(SS_TAP(X_BSPC) SS_RALT(SS_TAP(X_S)));
          }
            y_trigger = false;
            shift_trigger = false;
            return false;
        } else {
          shift_trigger = false;
          dot_trigger = false;
          b_trigger = false;
          c_trigger = false;
          g_trigger = false;
          l_trigger = false;
          s_trigger = false;
          u_trigger = false;
          y_trigger = false;
          z_trigger = false;
          if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            shift_trigger = true;
          }
        }
      }
    break; 
     case KC_I:
      if (record->event.pressed && layer_state_is(0)) {
        if (dot_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_O)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_O)));
          } else {
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_O));
          }
            dot_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_I);
            return false;
        } else {
          shift_trigger = false;
          dot_trigger = false;
          b_trigger = false;
          c_trigger = false;
          g_trigger = false;
          l_trigger = false;
          s_trigger = false;
          u_trigger = false;
          y_trigger = false;
          z_trigger = false;
          if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            shift_trigger = true;
          }
        }
      }
    break; 
    case KC_L:
      if (record->event.pressed && layer_state_is(0)) {
        shift_trigger = false;
        dot_trigger = false;
        b_trigger = false;
        c_trigger = false;
        g_trigger = false;
        l_trigger = true;
        s_trigger = false;
        u_trigger = false;
        y_trigger = false;
        z_trigger = false;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          shift_trigger = true;
        }
      }
    break; 
    case KC_O:
      if (record->event.pressed && layer_state_is(0)) {
        if (u_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_E)) SS_RSFT(SS_TAP(X_A)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_E)) SS_TAP(X_A));
          } else {
            SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_E) SS_TAP(X_A));
          }
            u_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_A);
            return false;
        } else if (dot_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_A)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_A)));
          } else {
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_A));
          }
            dot_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_O);
            return false;
        } else {
          shift_trigger = false;
          dot_trigger = false;
          b_trigger = false;
          c_trigger = false;
          g_trigger = false;
          l_trigger = false;
          s_trigger = false;
          u_trigger = false;
          y_trigger = false;
          z_trigger = false;
          if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            shift_trigger = true;
          }
        }
      }
    break; 
    case KC_S:
      if (record->event.pressed && layer_state_is(0)) {
        if (z_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_R)) SS_RSFT(SS_TAP(X_Z)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_R)) SS_TAP(X_Z));
          } else {
            SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_R) SS_TAP(X_Z));
          }
            z_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_Z);
            return false;
        } else {
          shift_trigger = false;
          dot_trigger = false;
          b_trigger = false;
          c_trigger = false;
          g_trigger = false;
          l_trigger = false;
          s_trigger = true;
          u_trigger = false;
          y_trigger = false;
          z_trigger = false;
          if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            shift_trigger = true;
          }
        }
      }
    break; 
    case KC_U:
      if (record->event.pressed && layer_state_is(0)) {
        if (dot_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_U)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_U)));
          } else {
            SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_U));
          }
            dot_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_Z);
            return false;
        } else {
          shift_trigger = false;
          dot_trigger = false;
          b_trigger = false;
          c_trigger = false;
          g_trigger = false;
          l_trigger = false;
          s_trigger = false;
          u_trigger = true;
          y_trigger = false;
          z_trigger = false;
          if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            shift_trigger = true;
          }
        }
      }
    break; 
    case KC_W:
      if (record->event.pressed && layer_state_is(0)) {
        if (b_trigger){
          if (is_caps_word_on()){
            SEND_STRING(SS_LSFT(SS_TAP(X_T)));
          } else if (shift_trigger){
            SEND_STRING(SS_TAP(X_T));
          } else {
            SEND_STRING(SS_TAP(X_T));
          }
            b_trigger = false;
            shift_trigger = false;
            set_last_keycode(KC_T);
            return false;
        } else {
          shift_trigger = false;
          dot_trigger = false;
          b_trigger = false;
          c_trigger = false;
          g_trigger = false;
          l_trigger = false;
          s_trigger = false;
          u_trigger = false;
          y_trigger = false;
          z_trigger = false;
          if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            shift_trigger = true;
          }
        }
      }
    break; 
    case KC_Y:
      if (record->event.pressed && layer_state_is(0)) {
        shift_trigger = false;
        dot_trigger = false;
        b_trigger = false;
        c_trigger = false;
        g_trigger = false;
        l_trigger = false;
        s_trigger = false;
        u_trigger = false;
        y_trigger = true;
        z_trigger = false;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          shift_trigger = true;
        }
      }
    break; 
    case KC_Z:
      if (record->event.pressed && layer_state_is(0)) {
        shift_trigger = false;
        dot_trigger = false;
        b_trigger = false;
        c_trigger = false;
        g_trigger = false;
        l_trigger = false;
        s_trigger = false;
        u_trigger = false;
        y_trigger = false;
        z_trigger = true;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          shift_trigger = true;
        }
      }
    break; 
    case ARCANE_L: 
               if (record->event.pressed && layer_state_is(0)) {
                 if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                    caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
               } else {
                   if (alpha_pressed) {// letter was pressed within timer limits
                     arcane_timer = timer_read(); // reset timer
                     process_arcane_l(get_last_keycode(), get_last_mods()); // call arcane code
                     shift_trigger = false;
                     dot_trigger = false;
                     b_trigger = false;
                     c_trigger = false;
                     g_trigger = false;
                     l_trigger = false;
                     s_trigger = false;
                     u_trigger = false;
                     y_trigger = false;
                     z_trigger = false;
                   } else {//alpha timer timed out, so key functions just as a OSM shift
                      set_oneshot_mods(MOD_BIT(KC_LSFT));
                   }
                 }
               }
             break; 
        case ARCANE_J: 
               if (record->event.pressed && layer_state_is(0)) {
                   if (alpha_pressed) {// letter was pressed within timer limits
                     arcane_timer = timer_read(); // reset timer
                     process_arcane_j(get_last_keycode(), get_last_mods()); // call arcane code
                     shift_trigger = false;
                     dot_trigger = false;
                     b_trigger = false;
                     c_trigger = false;
                     g_trigger = false;
                     l_trigger = false;
                     s_trigger = false;
                     u_trigger = false;
                     y_trigger = false;
                     z_trigger = false;
                   } else {//alpha timer timed out, so key functions just as a J
                     SEND_STRING(SS_TAP(X_J));
                     set_last_keycode(KC_J);
                   }
                 }
              break; 
    case KC_A:
    case KC_E:
    case KC_J:  
    case KC_K:
    case KC_M:
    case KC_N:
    case KC_P:
    case KC_Q:
    case KC_R:
    case KC_T:
    case KC_V:
    case KC_X:      
      if (record->event.pressed && layer_state_is(0)) {
        shift_trigger = false;
        dot_trigger = false;
        b_trigger = false;
        c_trigger = false;
        g_trigger = false;
        l_trigger = false;
        s_trigger = false;
        u_trigger = false;
        y_trigger = false;
        z_trigger = false;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) {
          shift_trigger = true;
        }
      }
    break; 
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE)SS_DELAY(10)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_U));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_E));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_U));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_E));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_I));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Q)SS_DELAY(100)  SS_TAP(X_U));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_E));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_A));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_6) ));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_O));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_I));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_A));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(5)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(10)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_RSFT(SS_TAP(X_U)));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_E)));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_U)));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_RSFT(SS_TAP(X_E)));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_I)));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_Q))SS_DELAY(100)  SS_TAP(X_U));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_RSFT(SS_TAP(X_E)));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_RSFT(SS_TAP(X_A)));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_O)));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_RSFT(SS_TAP(X_I)));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_A)));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
