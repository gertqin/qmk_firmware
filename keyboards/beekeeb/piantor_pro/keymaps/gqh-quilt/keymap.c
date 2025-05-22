// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// Compile on MacOS:
// > brew tap ArmMbed/homebrew-formulae
// > brew install arm-none-eabi-gcc

#include QMK_KEYBOARD_H

#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)

#define SYM_ENT LT(_SYM, KC_ENT)
#define SYM_BSP LT(_SYM, KC_0)

#define FN_BSLS LT(_FN, KC_BSLS)
#define GUI_ESC LGUI_T(KC_ESC)

enum LAYERS {
    _MAIN,
    _SYM,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        KC_MINS,   KC_V,   KC_B,   KC_L,   KC_F,     KC_Q,                                   KC_QUOT,  KC_W,   KC_O,     KC_U,     KC_SCLN,  KC_EQL,
        OSM_LSFT,  KC_S,   KC_N,   KC_T,   KC_H,     KC_M,                                   KC_Y,     KC_C,   KC_A,     KC_I,     KC_E,     OSM_RSFT,
        OSM_LCTL,  KC_Z,   KC_X,   KC_J,   KC_D,     KC_K,                                   KC_G,     KC_P,   KC_DOT,   KC_COMM,  KC_SLSH,  FN_BSLS,
                                              GUI_ESC,  KC_R,  SYM_BSP,            SYM_ENT,  KC_SPC,  OSM_LALT
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_MINS,   KC_LT,    KC_6,   KC_5,   KC_4,   KC_GT,                                   KC_DQUO,  KC_LBRC,   KC_LPRN,  KC_RPRN,  KC_SCLN,   KC_EQL,
        KC_TRNS,   KC_0,     KC_3,   KC_2,   KC_1,   KC_UNDS,                                 KC_LEFT,  KC_DOWN,   KC_UP,    KC_RIGHT, KC_RBRC,   KC_TRNS,
        KC_TRNS,   KC_PIPE,  KC_9,   KC_8,   KC_7,   KC_PLUS,                                 KC_GRV,   KC_TAB,    KC_DOT,   KC_COMM,  KC_SLSH,   KC_BSLS,
                                              OSM_LGUI,  OSM_LALT, KC_BSPC,        KC_ENT,  KC_SPC,  OSM_LALT
    ),
    [_FN] = LAYOUT_split_3x6_3(
        XXXXXXX,   KC_F11,  KC_F6,  KC_F5,  KC_F4,  XXXXXXX,                           XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        OSM_LSFT,  KC_F10,  KC_F3,  KC_F2,  KC_F1,  XXXXXXX,                           XXXXXXX,  KC_LSFT,   KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        OSM_LCTL,  KC_F12,  KC_F9,  KC_F8,  KC_F7,  XXXXXXX,                           XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                              KC_TRNS,  KC_TRNS, KC_DEL,          KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
};

const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t cmd_j_key_override = ko_make_basic(MOD_MASK_GUI, KC_J, G(KC_C));
const key_override_t cmd_c_key_override = ko_make_basic(MOD_MASK_GUI, KC_C, G(KC_J));
const key_override_t alt_i_key_override = ko_make_basic(MOD_MASK_ALT, KC_I, A(KC_QUOT));
const key_override_t alt_quot_key_override = ko_make_basic(MOD_MASK_ALT, KC_QUOT, A(KC_I));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &dot_key_override,
    &comma_key_override,
    &cmd_j_key_override,
    &cmd_c_key_override,
    &alt_i_key_override,
    &alt_quot_key_override
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case SYM_BSP:
        if (record->tap.count) {
            if (record->event.pressed) {
                uint8_t mod_state = get_mods();
                uint8_t os_mod_state = get_oneshot_mods();

                if (mod_state & MOD_MASK_GUI) {
                    tap_code16(KC_BSPC);
                } else if (mod_state & MOD_MASK_CTRL) {
                    tap_code16(KC_DEL);
                } else if (mod_state & MOD_MASK_SHIFT) {
                    tap_code16(KC_BSPC);
                } else if (os_mod_state & MOD_MASK_SHIFT) {
                    tap_code16(KC_BSPC);
                } else {
                    tap_code16(A(KC_BSPC));
                }
            }
            return false;  // Skip default handling.
        }
        break;
    }

    return true;  // Continue default handling.
}
