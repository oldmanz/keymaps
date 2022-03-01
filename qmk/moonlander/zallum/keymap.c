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
    NAV,
    NUM,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, RGB_TOG,            _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______,
        _______, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,           _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______,
        _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN, _______,           _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
        _______, MO(SYM), _______, _______, _______, _______,                             _______, _______, _______, _______, MO(NAV), _______,
        KC_LSFT, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______,  KC_SPC,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [SYM] = LAYOUT_moonlander(
        _______, KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,  _______,           _______, KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD, _______,
        _______,KC_HASH,OSM(MOD_RGUI),OSM(MOD_RALT),OSM(MOD_RCTL),OSM(MOD_RSFT),_______,     _______, KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  _______,
        _______, _______, KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM, _______,           _______, KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, MO(NUM), _______,
        KC_LSFT,  _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______,  KC_SPC,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [NAV] = LAYOUT_moonlander(
        _______, KC_TAB,  KC_HOME, KC_UP,   KC_END,   KC_DEL,  _______,           _______, KC_ESC,  KC_TAB, _______, _______, KC_VOLU,  _______,
        _______, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT,  KC_BSPC, _______,           _______,OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_LALT),OSM(MOD_LGUI),KC_VOLD,_______,
        _______, _______, KC_PGDN, KC_INS,  KC_PGUP,  KC_ENT,  _______,           _______, _______, _______, KC_MPRV, KC_MNXT,KC_MPLY,  _______,
        _______, MO(NUM), _______, _______, _______, _______,                             _______, _______, _______, _______, _______,   _______,
        KC_LSFT,  _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______,  KC_SPC,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [NUM] = LAYOUT_moonlander(
        _______,  KC_6, KC_7, KC_8, KC_9, KC_0, _______,           _______, KC_1, KC_2, KC_3, KC_4, KC_5, _______,
       _______,KC_F12,OSM(MOD_RGUI),OSM(MOD_RALT),OSM(MOD_RCTL),OSM(MOD_RSFT),_______, _______,OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_LALT),OSM(MOD_LGUI),KC_F11,_______,
        _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,           _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        KC_LSFT,  _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______,  KC_SPC,
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
