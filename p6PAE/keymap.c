#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

bool alpha_pressed = false; // variable for timer to disable arcane key functionality after no letter has been pressed for x amount of time
uint16_t arcane_timer = 0;     // timer 
uint16_t last_key_manual = 0; // for timer reset

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ARCANE_L,
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
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
  ST_MACRO_30,
  ST_MACRO_31,
  ST_MACRO_32,
  ST_MACRO_33,
  ST_MACRO_34,
  ST_MACRO_35,
  ST_MACRO_36,
  ST_MACRO_37,
  ST_MACRO_38,
  ST_MACRO_39,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(2),          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, TO(2),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    OSL(7),         KC_B,           KC_L,           KC_D,           KC_G,           KC_W,                                           KC_Y,           KC_P,           KC_O,           KC_U,           KC_Z,           KC_TRANSPARENT, 
    KC_ENTER,       KC_N,           KC_R,           KC_T,           KC_S,           KC_M,                                           KC_C,           KC_H,           KC_E,           KC_I,           KC_A,           RCTL(KC_BSPC),  
    TO(1),          KC_X,           KC_J,           OSL(5),         KC_F,           KC_V,                                           ST_MACRO_0,     KC_K,           OSL(5),         KC_COMMA,       KC_DOT,         KC_TRANSPARENT, 
                                                    ARCANE_L, OSL(3),                                         OSL(4),         KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_F11,         KC_F12,         KC_F5,          KC_F8,          
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,        
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_ENTER,       
    TD(DANCE_0),    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_LEFT_ALT,                                    OSL(4),         TO(0)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         TD(DANCE_1),    KC_F5,          KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_F5,          KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_E,           KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_E,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_P,           KC_N,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_P,           KC_N,           KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_LEFT_ALT,                                    TO(0),          KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(10),         TD(DANCE_2),    LCTL(KC_X),     LCTL(KC_C),     ST_MACRO_1,     LCTL(KC_V),                                     ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     KC_TRANSPARENT, 
    OSL(8),         OSM(MOD_LCTL),  OSM(MOD_LALT),  KC_TAB,         ST_MACRO_2,     KC_DELETE,                                      ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    US_EACU,        ST_MACRO_11,    ST_MACRO_12,    
    KC_TRANSPARENT, OSM(MOD_LGUI),  OSM(MOD_LSFT),  LSFT(KC_TAB),   TO(0),          OSL(4),                                         ST_MACRO_13,    ST_MACRO_14,    ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,    ST_MACRO_18,    
                                                    OSM(MOD_RALT),  OSL(9),                                         US_CCED,        ST_MACRO_19
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_20,    ST_MACRO_21,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_SLASH,       KC_TRANSPARENT, 
    KC_ENTER,       KC_4,           KC_3,           KC_2,           KC_1,           KC_DELETE,                                      QK_LLCK,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_BSPC,        
    KC_TRANSPARENT, KC_9,           KC_8,           KC_7,           KC_6,           KC_5,                                           KC_PGDN,        KC_COLN,        OSL(5),         KC_COMMA,       KC_DOT,         KC_TRANSPARENT, 
                                                    KC_0,           OSL(6),                                         KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_AT,          US_LABK,        KC_MINUS,       US_RABK,        KC_AMPR,                                        US_SECT,        KC_BSLS,        KC_LBRC,        KC_RBRC,        KC_SLASH,       KC_TRANSPARENT, 
    KC_EQUAL,       ST_MACRO_22,    KC_QUES,        KC_EXLM,        KC_TILD,        TD(DANCE_3),                                    RSFT(KC_6),     KC_PLUS,        KC_LPRN,        KC_RPRN,        KC_PERC,        KC_BSPC,        
    KC_TRANSPARENT, KC_UNDS,        TD(DANCE_4),    KC_HASH,        KC_TRANSPARENT, KC_ASTR,                                        TD(DANCE_5),    KC_COLN,        KC_LCBR,        KC_RCBR,        KC_SCLN,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_PIPE,                                        TO(0),          KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_6),    LCTL(KC_X),     LCTL(KC_C),     KC_TRANSPARENT, LCTL(KC_V),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    OSL(8),         OSM(MOD_LCTL),  OSM(MOD_LALT),  KC_TAB,         KC_TRANSPARENT, KC_DELETE,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LGUI),  OSM(MOD_LSFT),  LSFT(KC_TAB),   TO(0),          TO(4),                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    OSM(MOD_RALT),  TO(9),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_23,    KC_TRANSPARENT,                                 ST_MACRO_24,    ST_MACRO_25,    KC_TRANSPARENT, ST_MACRO_26,    ST_MACRO_27,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_7),    TD(DANCE_8),    TD(DANCE_9),    KC_TRANSPARENT,                                 ST_MACRO_28,    ST_MACRO_29,    ST_MACRO_30,    RSFT(US_EACU),  ST_MACRO_31,    ST_MACRO_32,    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 ST_MACRO_33,    ST_MACRO_34,    ST_MACRO_35,    ST_MACRO_36,    ST_MACRO_37,    ST_MACRO_38,    
                                                    KC_TRANSPARENT, TO(0),                                          LSFT(US_CCED),  ST_MACRO_39
  ),
  [8] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LGUI(KC_D),     LGUI(KC_TAB),   LGUI(KC_E),     KC_TRANSPARENT, LGUI(KC_V),                                     RGUI(KC_P),     LCTL(KC_P),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LALT(KC_ENTER), LCTL(KC_Z),     LCTL(KC_Y),     LCTL(KC_A),     LCTL(KC_S),     LGUI(LSFT(KC_S)),                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RCTL(KC_F),     KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_W),     LCTL(KC_T),     LCTL(LSFT(KC_K)),LCTL(LSFT(KC_F)),LCTL(LSFT(KC_U)),                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, TO(0),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,                                         KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_F1,          KC_F2,          KC_F3,          KC_F4,                                          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_RIGHT_GUI,   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F17,         KC_F18,         KC_F19,         KC_F20,                                         KC_F21,         KC_F22,         KC_F23,         KC_F24,         KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_LEFT_SHIFT,  TO(0),                                          TO(0),          KC_RIGHT_CTRL
  ),
  [10] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(0),          
                                                    KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {20,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,255,255}, {152,255,255}, {152,255,255}, {188,255,255}, {152,255,255}, {152,255,255}, {0,0,255}, {236,255,255}, {0,0,0}, {0,0,0}, {20,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,0,255}, {152,255,255}, {152,255,255}, {189,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {89,255,255}, {0,0,255} },

    [1] = { {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,245,245}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,245,245}, {0,245,245}, {0,245,245}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,0,0}, {0,0,79}, {0,0,79}, {0,0,79}, {0,0,79}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,0,255}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,0,255}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,255,118}, {0,0,0}, {74,255,255}, {152,255,255} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,255,255}, {20,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {20,255,255}, {20,255,255}, {20,255,255}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {20,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {20,255,255}, {20,255,255}, {20,255,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {0,0,0}, {152,255,255}, {0,0,255} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,34}, {0,0,255}, {0,255,255}, {0,255,255}, {152,255,255}, {0,255,255}, {0,73,255}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {74,255,255}, {0,0,255}, {116,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {236,255,255}, {152,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {236,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {20,255,255}, {0,0,255}, {95,255,255}, {0,0,0}, {152,255,255}, {20,255,255}, {20,255,255}, {20,255,255}, {0,255,255}, {0,0,255}, {0,0,255}, {95,255,255}, {188,255,255}, {95,255,255}, {95,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {181,255,255}, {188,255,255}, {188,255,255}, {181,255,255}, {181,255,255}, {181,255,255}, {0,0,0}, {181,255,255}, {181,255,255}, {181,255,255}, {181,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {181,255,255}, {188,255,255}, {181,255,255}, {0,0,0}, {181,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {181,255,255}, {181,255,255}, {181,255,255}, {0,0,0}, {181,255,255}, {181,255,255}, {181,255,255}, {181,255,255}, {181,255,255}, {0,0,255}, {181,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {152,255,255}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {152,255,255}, {74,255,255}, {0,0,255}, {116,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {0,0,0}, {236,255,255}, {152,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255} },

    [8] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,73,255}, {0,73,255}, {0,73,255}, {0,0,0}, {0,73,255}, {0,73,255}, {0,73,255}, {0,73,255}, {0,73,255}, {0,73,255}, {0,73,255}, {0,0,0}, {0,73,255}, {0,73,255}, {0,73,255}, {0,73,255}, {0,73,255}, {0,0,0}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,73,255}, {0,73,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,73,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [9] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {116,255,255}, {116,255,255}, {116,255,255}, {116,255,255}, {0,0,0}, {0,0,255}, {116,255,255}, {116,255,255}, {116,255,255}, {116,255,255}, {0,0,0}, {0,0,0}, {116,255,255}, {116,255,255}, {116,255,255}, {116,255,255}, {0,0,255}, {152,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {116,255,255}, {116,255,255}, {116,255,255}, {116,255,255}, {0,0,0}, {0,0,0}, {116,255,255}, {116,255,255}, {116,255,255}, {116,255,255}, {0,0,255}, {0,0,0}, {116,255,255}, {116,255,255}, {116,255,255}, {116,255,255}, {0,0,0}, {0,0,0}, {152,255,255}, {0,0,255} },

    [10] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,34}, {0,0,0}, {0,0,0} },

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
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
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
    case 10:
      set_layer_color(10);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case ARCANE_L:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_MINS:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case ARCANE_L:
            return false;  // Ignore ALTREP keys. If this is not here, only default action will be done, since the process stuff is apparently run after the remember last key stuff, so that the key is only ever trying to repeat itself.
    }

    return true;  // Other keys can be repeated.
}

static void process_arcane_l(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_A)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_A)));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_A));
          }
         break;        
        case KC_B:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("B");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("er");
          } else { //unshifted previous key
              send_string("b");
          }
         break;
        case KC_C:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("C");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("c");
          } else { //unshifted previous key
              send_string("c");
          }
         break;
        case KC_D:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("D");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("eutsch");
          } else { //unshifted previous key
              send_string("d");
          }
         break;
       case KC_E:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("E");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("e");
          } else { //unshifted previous key
              send_string("e");
          }
         break;
        case KC_F:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("F");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("rankfurt");
          } else { //unshifted previous key
              send_string("f");
          }
         break;
        case KC_G:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("G");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("g");
          } else { //unshifted previous key
              send_string("g");
          }
         break;
        case KC_H:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_C)) SS_RSFT(SS_TAP(X_H)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_C)) SS_TAP(X_H));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_C) SS_TAP(X_H));
          }
         break;
        case KC_I:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_O)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_O)));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_O));
          }
         break;
        case KC_J: //good candidate for more macro stuff, like w but without the j because j is useless lol
          if (is_caps_word_on()) { //checks for caps word status
              send_string("ED");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("ed");
          } else { //unshifted previous key
              send_string("ed");
          }
         break;
        case KC_K:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_C)) SS_RSFT(SS_TAP(X_K)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_C)) SS_TAP(X_K));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_C) SS_TAP(X_K));
          }
         break;
        case KC_L:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("L");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("icht");
          } else { //unshifted previous key
              send_string("l");
          }
         break;
        case KC_M:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("M");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("it");
          } else { //unshifted previous key
              send_string("m");
          }
         break;
        case KC_N:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("N");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("eu");
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
              send_string("ro");
          } else { //unshifted previous key
              send_string("p");
          }
         break;
        case KC_R:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("R");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("eg");
          } else { //unshifted previous key
              send_string("r");
          }
         break;
        case KC_S:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("S");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("ch");
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
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_U)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_RSFT(SS_TAP(X_U)));
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_RSFT(SS_TAP(X_QUOTE)) SS_TAP(X_U));
          }
         break;
        case KC_V:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RALT(SS_TAP(X_S)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("");
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_RALT(SS_TAP(X_S)));
          }
         break;
        case KC_W:
          if (is_caps_word_on()) { //checks for caps word status
             send_string("S");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
             send_string("s");
          } else { //unshifted previous key
             send_string("s");
          }
         break;
        case KC_X:
          if (is_caps_word_on()) { //checks for caps word status
              SEND_STRING(SS_TAP(X_BSPC) SS_RALT(SS_TAP(X_S)));
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("");
          } else { //unshifted previous key
              SEND_STRING(SS_TAP(X_BSPC) SS_RALT(SS_TAP(X_S)));
          }
         break;
        case KC_Y:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("P");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("p");
          } else { //unshifted previous key
              send_string("p");
          }
         break;
        case KC_Z:
          if (is_caps_word_on()) { //checks for caps word status
              send_string("EI");
          } else if (mods & MOD_MASK_SHIFT) { //checks for shift mod of previous key, which is also true of caps word shifted keys, but this is only run if is_caps_word_on() returned false
              send_string("ei");
          } else { //unshifted previous key
              send_string("ei");
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

void matrix_scan_user(void) { // The very important timer.
  if (alpha_pressed && timer_elapsed(arcane_timer) > 1000) { //triggers when timer elapsed
      alpha_pressed = false;
      set_last_keycode(KC_SPACE);
  } else { //timer update
    switch (get_last_keycode()) {
      case KC_A ... KC_Z:  
      case KC_SCLN:
      case KC_COMMA:
        if (last_key_manual != get_last_keycode()) {
          last_key_manual = get_last_keycode();
          alpha_pressed = true;
          arcane_timer = timer_read();
        }
      break; //these were all the keys that keep the timer going
      case KC_SPACE:
      case KC_ENTER:
      case KC_BSPC:
      case KC_DOT:
      case RCTL(KC_BSPC):
      last_key_manual = get_last_keycode();
      alpha_pressed = false;
      break; //these were all the keys that end the timer prematurely
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ARCANE_L: 
               if (record->event.pressed) {
                 if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                    caps_word_toggle(); //toggles on caps word if one shot shift is already active (e.g. through double-tapping the key
               } else {
                   if (alpha_pressed) {// letter was pressed within timer limits
                     arcane_timer = timer_read(); // reset timer
                     process_arcane_l(get_last_keycode(), get_last_mods()); // call arcane code
                   } else {//alpha timer timed out, so key functions just as a OSM shift
                      set_oneshot_mods(MOD_BIT(KC_LSFT));
                   }
                 }
               }
       break; 
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE)SS_DELAY(5)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S)SS_DELAY(10)  SS_TAP(X_G));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_W)SS_DELAY(10)  SS_TAP(X_S));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C)SS_DELAY(10)  SS_TAP(X_Y));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_P)SS_DELAY(100)  SS_TAP(X_Y));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_E)SS_DELAY(10)  SS_TAP(X_O));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_U));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_A)SS_DELAY(10)  SS_TAP(X_Z));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_H)SS_DELAY(10)  SS_TAP(X_Y));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Q)SS_DELAY(100)  SS_TAP(X_U));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_E));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_E));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_O));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_6) ));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_U));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_I));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_I));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_TAP(X_A));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_TAP(X_E));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_TAP(X_A));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_N)SS_DELAY(10)  SS_TAP(X_B));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_R)SS_DELAY(10)  SS_TAP(X_L));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE))SS_DELAY(5)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_M));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_P))SS_DELAY(100)  SS_TAP(X_H)SS_DELAY(100)  SS_TAP(X_Y));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_P))SS_DELAY(100)  SS_TAP(X_Y));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_RSFT(SS_TAP(X_U)));
    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_Z))SS_DELAY(100)  SS_TAP(X_A));
    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_P))SS_DELAY(100)  SS_TAP(X_F));
    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_Q))SS_DELAY(100)  SS_TAP(X_U));
    }
    break;
    case ST_MACRO_30:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_RSFT(SS_TAP(X_E)));
    }
    break;
    case ST_MACRO_31:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_E)));
    }
    break;
    case ST_MACRO_32:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_O)));
    }
    break;
    case ST_MACRO_33:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_34:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_U)));
    }
    break;
    case ST_MACRO_35:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_RSFT(SS_TAP(X_I)));
    }
    break;
    case ST_MACRO_36:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_I)));
    }
    break;
    case ST_MACRO_37:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_6))SS_DELAY(100)  SS_RSFT(SS_TAP(X_A)));
    }
    break;
    case ST_MACRO_38:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_QUOTE))SS_DELAY(100)  SS_RSFT(SS_TAP(X_E)));
    }
    break;
    case ST_MACRO_39:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE)SS_DELAY(100)  SS_RSFT(SS_TAP(X_A)));
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

static tap dance_state[10];

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
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
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
        tap_code16(KC_DLR);
        tap_code16(KC_DLR);
        tap_code16(KC_DLR);
    }
    if(state->count > 3) {
        tap_code16(KC_DLR);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_DLR); break;
        case DOUBLE_TAP: register_code16(US_EURO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DLR); register_code16(KC_DLR);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_DLR); break;
        case DOUBLE_TAP: unregister_code16(US_EURO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DLR); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_LDAQ);
        tap_code16(US_LDAQ);
        tap_code16(US_LDAQ);
    }
    if(state->count > 3) {
        tap_code16(US_LDAQ);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(US_LDAQ); break;
        case DOUBLE_TAP: register_code16(US_RDAQ); break;
        case DOUBLE_SINGLE_TAP: tap_code16(US_LDAQ); register_code16(US_LDAQ);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(US_LDAQ); break;
        case DOUBLE_TAP: unregister_code16(US_RDAQ); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(US_LDAQ); break;
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
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case DOUBLE_TAP: register_code16(RSFT(KC_QUOTE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case DOUBLE_TAP: unregister_code16(RSFT(KC_QUOTE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
    }
    if(state->count > 3) {
        tap_code16(KC_GRAVE);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_TAP: register_code16(RSFT(KC_GRAVE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_GRAVE); register_code16(KC_GRAVE);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_TAP: unregister_code16(RSFT(KC_GRAVE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_GRAVE); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(KC_QUOTE));
        tap_code16(RALT(KC_QUOTE));
        tap_code16(RALT(KC_QUOTE));
    }
    if(state->count > 3) {
        tap_code16(RALT(KC_QUOTE));
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(RALT(KC_QUOTE)); break;
        case DOUBLE_TAP: register_code16(RALT(RSFT(KC_QUOTE))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(KC_QUOTE)); register_code16(RALT(KC_QUOTE));
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(RALT(KC_QUOTE)); break;
        case DOUBLE_TAP: unregister_code16(RALT(RSFT(KC_QUOTE))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(KC_QUOTE)); break;
    }
    dance_state[9].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
};
