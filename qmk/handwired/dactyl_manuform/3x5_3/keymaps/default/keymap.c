#include QMK_KEYBOARD_H
#include "caps_word.h"

enum layers {
    BASE,
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
    FUN,
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

// Alts
#define ALT_X RALT_T(KC_X)
#define ALT_DO RALT_T(KC_DOT)

// Thumbs
#define T_ESC LT(MEDIA, KC_ESC)
#define T_SPACE LT(NAV, KC_SPC)
#define T_TAB  LT(MOUSE, KC_TAB)

#define T_DEL LT(FUN, KC_DEL)
#define T_BSPC LT(NUM, KC_BSPC)
#define T_ENT LT(SYM, KC_ENT)

// Macros
#define Z_REDO LCTL(KC_Y)
#define Z_PASTE LCTL(KC_V)
#define Z_COPY LCTL(KC_C)
#define Z_CUT LCTL(KC_X)
#define Z_UNDO LCTL(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_3x5_3(
     KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
     HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_D,           KC_H,    HOME_N,  HOME_E,  HOME_I,  HOME_O,
     KC_Z,    ALT_X,   KC_C,    KC_V,    KC_B,           KC_K,    KC_M,    KC_COMM, ALT_DO,  KC_SLSH,
          		        T_ESC,   T_SPACE,        T_BSPC,  T_DEL,
          		                 T_TAB,          T_ENT
  ),

  [NAV] = LAYOUT_3x5_3(
     _______, _______, _______, _______, _______,        _______, _______, KC_UP,   _______, _______,
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,        KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
     _______, KC_RALT, _______, _______, _______,        KC_CAPS, KC_PGDN, _______, KC_PGUP, KC_INS,
                        	_______, _______,        KC_BSPC, KC_DEL,
					 _______,	 KC_ENT  
  ),
  
  [MOUSE] = LAYOUT_3x5_3(
     _______, _______, _______, _______, _______,        _______, _______, KC_MS_U, _______, _______,
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,        KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
     _______, KC_RALT, _______, _______, _______,        KC_CAPS, KC_WH_D, _______, KC_WH_U, _______,
                        	_______, _______,        KC_BTN3, KC_BTN2,
					 _______,	 KC_BTN1  
  ),
  
  [MEDIA] = LAYOUT_3x5_3(
     _______, _______, _______, _______, _______,        _______, _______, KC_VOLU, _______, _______,
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,        _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,
     _______, KC_RALT, _______, _______, _______,        _______, KC_BRID, _______, KC_BRIU, _______,
                        	_______, _______,        KC_MPLY, KC_MUTE,
					 _______,	 KC_MSTP  
  ),
  
  [NUM] = LAYOUT_3x5_3(
     KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,        _______, _______, _______, _______, _______,
     KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,         _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,        _______, _______, _______, KC_RALT, _______,
                                KC_DOT,  KC_0,           _______, _______,
					 KC_MINS,	 _______  
  ),
  
  [SYM] = LAYOUT_3x5_3(
     KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,        _______, _______, _______, _______, _______,
     KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,        _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,        _______, _______, _______, KC_RALT, _______,
                                KC_LPRN, KC_RPRN,        _______, _______,
					 KC_UNDS,	 _______  
  ),
 
  [FUN] = LAYOUT_3x5_3(
     KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,        _______, _______, _______, _______, _______,
     KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,        _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
     KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,        _______, _______, _______, KC_RALT, _______,
                                _______, KC_SPC,         _______, _______,
					 KC_TAB,	 _______  
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
    return true;
}

enum combo_events {
  CAPS_COMBO,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM caps_combo[] = {KC_D, KC_H, COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO_ACTION(caps_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {

    case CAPS_COMBO:
      if (pressed) {
        caps_word_set(true);
      }
      break;
  }
}
