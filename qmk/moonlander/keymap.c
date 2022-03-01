/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"
#include "caps_word.h"

enum layers {
    BASE,
    SYM,
    NUM,
    FUN,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC, RGB_TOG,            _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    _______,
        _______, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______,           _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    _______,
        _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  MO(FUN), _______,           _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,
        _______, MO(NUM), _______, _______, _______, _______,                             _______, _______, _______, _______, MO(SYM), _______,
        KC_ENT,  _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______,  KC_SPC,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [SYM] = LAYOUT_moonlander(
        _______, _______, KC_CIRC, KC_LCBR, KC_RCBR, KC_BSPC, _______,           _______, _______, KC_BSLS, KC_PERC, KC_DLR,  _______, _______,
        _______, _______, KC_DQUO, KC_LBRC, KC_RBRC, KC_SCLN, _______,           _______, KC_ASTR, KC_LPRN, KC_RPRN, KC_COLN, _______, _______,
        _______, _______, KC_HASH, KC_LABK, KC_RABK, _______, _______,           _______, _______, KC_GRV,  KC_AT,   KC_AMPR, _______, _______,
        _______, KC_ESC,  _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        KC_ENT,  _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______,  KC_SPC,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [NUM] = LAYOUT_moonlander(
        _______, _______, KC_PIPE, KC_MINS, KC_SLSH, KC_BSPC, _______,           _______, _______, KC_4,    KC_5,    KC_6,    _______,  _______,
        _______, _______, KC_QUOT, KC_UNDS, KC_EQL,  _______, _______,           _______, KC_DOT,  KC_1,    KC_2,    KC_3,    _______,  _______,
        _______, _______, KC_PLUS, KC_QUES, KC_EXLM, MO(FUN), _______,           _______, KC_TILD, KC_7,    KC_8,    KC_9,    _______,  _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, KC_0,    _______,
        KC_ENT,  _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______,  KC_SPC,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [FUN] = LAYOUT_moonlander(
        _______, _______, KC_PGDN, _______, KC_PGUP, KC_BSPC, _______,           _______, KC_VOLU, KC_F4,   KC_F5,   KC_F6,    KC_F10, _______,
        _______, _______, KC_HOME, KC_UP,    KC_END, _______, _______,           _______, KC_VOLD,  KC_F1,   KC_F2,   KC_F3,   KC_F11, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,           _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F12, _______,
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, KC_LGUI,
        KC_ENT,  _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______,  KC_SPC,
                                            _______, _______, _______,           _______, _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}


enum combo_events {
  TAB_COMBO,
  CTRL_COMBO,
  SHIFT_COMBO,
  DELETE_COMBO,
  MOD_COMBO,
  ALT_COMBO,
  CAPS_COMBO,
  WBSPC_COMBO,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM tab_combo[]   = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM ctrl_combo[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM shift_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM delete_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM mod_combo[] = {MO(SYM), KC_SPC, COMBO_END};
const uint16_t PROGMEM alt_combo[] = {MO(NUM), KC_ENT, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM wbspc_combo[] = {KC_Y, KC_BSPC, COMBO_END};

combo_t key_combos[] = {
    [TAB_COMBO] = COMBO_ACTION(tab_combo),
    [CTRL_COMBO] = COMBO_ACTION(ctrl_combo),
    [SHIFT_COMBO] = COMBO_ACTION(shift_combo),
    [DELETE_COMBO] = COMBO_ACTION(delete_combo),
    [MOD_COMBO] = COMBO_ACTION(mod_combo),
    [ALT_COMBO] = COMBO_ACTION(alt_combo),
    [CAPS_COMBO] = COMBO_ACTION(caps_combo),
    [WBSPC_COMBO] = COMBO_ACTION(wbspc_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        caps_word_set(true);
      }
      break;
    case TAB_COMBO:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;
    case CTRL_COMBO:
      if (pressed) {
        set_oneshot_mods(MOD_BIT(KC_LCTL));
      }
      break;
    case SHIFT_COMBO:
      if (pressed) {
        set_oneshot_mods(MOD_BIT(KC_LSFT));
      }
      break;
    case DELETE_COMBO:
      if (pressed) {
        tap_code16(KC_DEL);
      }
      break;
    case MOD_COMBO:
      if (pressed) {
        set_oneshot_mods(MOD_BIT(KC_LGUI));
      }
      break;
    case ALT_COMBO:
      if (pressed) {
        set_oneshot_mods(MOD_BIT(KC_LALT));
      }
      break;
    case WBSPC_COMBO:
      if (pressed) {
        set_oneshot_mods(MOD_BIT(KC_LCTL));
        tap_code16(KC_BSPC);
      }
      break;
  }
}
