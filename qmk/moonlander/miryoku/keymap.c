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
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
    FUN,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
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

// Thumbs
#define T_ESC LT(MEDIA, KC_ESC)
#define T_SPACE LT(NAV, KC_SPC)
#define T_TAB  LT(MOUSE, KC_TAB)

#define T_DEL LT(SYM, KC_DEL)
#define T_BSPC LT(NUM, KC_BSPC)
#define T_ENT LT(FUN, KC_ENT)



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, RGB_TOG,           _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______,
        _______, KC_H,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  _______,           _______, HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_D,    _______,
        _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,           _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
        _______, T_BSPC,  T_DEL,   _______, _______, _______,                             _______, _______, _______, T_ESC,   T_SPACE, _______,
        T_ENT,   _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, T_TAB,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [NAV] = LAYOUT_moonlander(
        _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,           _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,
        _______, _______, KC_PGDN, KC_INS,  KC_PGUP, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______,  T_BSPC,  T_DEL,  _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        T_ENT,   _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    
    [MOUSE] = LAYOUT_moonlander(
        _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,
        _______, _______, KC_WH_D, _______, KC_WH_U, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_BTN3, KC_BTN2, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        KC_BTN1, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    
    [MEDIA] = LAYOUT_moonlander(
        _______, _______, KC_BRID, KC_VOLU, KC_BRIU, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______,           _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MPLY, KC_MUTE, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        KC_MSTP, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [NUM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______,
        _______, _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,           _______, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, KC_DOT,   KC_0,   _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, KC_MINS,
                                            _______, _______, _______,           _______, _______, _______
    ),
    
    [SYM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,
        _______, _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,           _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, KC_UNDS,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [FUN] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______,
        _______, _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,           _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, KC_SPC,  _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, KC_TAB,
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
