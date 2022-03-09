#include QMK_KEYBOARD_H
#include "caps_word.h"

enum layers {
    BASE,
    QWERTY,
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

#define HOME_S2 LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_QU RGUI_T(KC_QUOT)

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

  [QWERTY] = LAYOUT_3x5_3(
     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
     HOME_A,  HOME_S2, HOME_D,  HOME_F,  KC_G,           KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_QU,
     KC_Z,    ALT_X,   KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, ALT_DO,  KC_SLSH,
                      T_ESC,   T_SPACE,        T_BSPC,  T_DEL,
                               T_TAB,          T_ENT
  ),

  [NAV] = LAYOUT_3x5_3(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,        KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
     XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,        KC_CAPS, KC_PGDN, XXXXXXX, KC_PGUP, KC_INS,
                        	XXXXXXX, XXXXXXX,        KC_BSPC, KC_DEL,
					 XXXXXXX,	 KC_ENT  
  ),
  
  [MOUSE] = LAYOUT_3x5_3(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,        KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
     XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,        KC_CAPS, KC_WH_D, XXXXXXX, KC_WH_U, XXXXXXX,
                        	XXXXXXX, XXXXXXX,        KC_BTN3, KC_BTN2,
					 XXXXXXX,	 KC_BTN1  
  ),
  
  [MEDIA] = LAYOUT_3x5_3(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,        XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX,
     XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, KC_BRID, XXXXXXX, KC_BRIU, XXXXXXX,
                        	XXXXXXX, XXXXXXX,        KC_MPLY, KC_MUTE,
					 XXXXXXX,	 KC_MSTP  
  ),
  
  [NUM] = LAYOUT_3x5_3(
     KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,         XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,        XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
                                KC_DOT,  KC_0,           XXXXXXX, XXXXXXX,
					 KC_MINS,	 XXXXXXX  
  ),
  
  [SYM] = LAYOUT_3x5_3(
     KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,        XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,        XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
                                KC_LPRN, KC_RPRN,        XXXXXXX, XXXXXXX,
					 KC_UNDS,	 XXXXXXX  
  ),
 
  [FUN] = LAYOUT_3x5_3(
     KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,        XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
     KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,        XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
                                XXXXXXX, KC_SPC,         XXXXXXX, XXXXXXX,
					 KC_TAB,	 XXXXXXX  
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
    return true;
}

enum combo_events {
  CAPS_COMBO,
  QWERTY_COMBO,
  COLEMAK_COMBO,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM caps_combo[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM qwerty_combo[] = {HOME_A, T_SPACE, T_BSPC, HOME_O, COMBO_END};
const uint16_t PROGMEM colemak_combo[] = {HOME_A, T_SPACE, T_BSPC, HOME_QU, COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO_ACTION(caps_combo),
    [QWERTY_COMBO] = COMBO_ACTION(qwerty_combo),
    [COLEMAK_COMBO] = COMBO_ACTION(colemak_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {

    case CAPS_COMBO:
      if (pressed) {
        caps_word_set(true);
      }
      break;

    case QWERTY_COMBO:
      if (pressed) {
        layer_off(BASE);
        layer_on(QWERTY);
      }
      break; 

    case COLEMAK_COMBO:
      if (pressed) {
        layer_off(QWERTY);
        layer_on(BASE);
      }
      break;    
  }
}
