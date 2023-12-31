// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// Compile on MacOS:
// > brew tap ArmMbed/homebrew-formulae
// > brew install arm-none-eabi-gcc

#include QMK_KEYBOARD_H


enum LAYERS {
    _DEF,
    _SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [_DEF] = LAYOUT_split_3x6_3(
    //     KC_EQL,          KC_Q,          KC_W,          KC_E,          KC_R,    KC_T,                KC_Y,  KC_U,  KC_I,            KC_O,            KC_P,             KC_MINS,
    //     LGUI_T(KC_ESC),  KC_A,          KC_S,          KC_D,          KC_F,    KC_G,                KC_H,  KC_J,  KC_K,            KC_L,            KC_SCLN,          RGUI_T(KC_QUOT),
    //     KC_GRV,          LCTL_T(KC_Z),  LALT_T(KC_X),  LGUI_T(KC_C),  KC_V,    KC_B,                KC_N,  KC_M,  RGUI_T(KC_COMM), LALT_T(KC_DOT),  RCTL_T(KC_SLSH),  OSM(MOD_LALT),
    //                                            OSM(MOD_LSFT),  KC_BSPC,  LT(_SYM, KC_TAB),      LT(_SYM, KC_ENT),  KC_SPC,  OSM(MOD_RSFT)
    // ),
    [_DEF] = LAYOUT_split_3x6_3(
        KC_EQL,          KC_Q,          KC_W,          KC_F,          KC_P,  KC_G,                KC_J,  KC_L,  KC_U,            KC_Y,            KC_SCLN,          KC_MINS,
        LGUI_T(KC_ESC),  KC_A,          KC_R,          KC_S,          KC_T,  KC_D,                KC_H,  KC_N,  KC_E,            KC_I,            KC_O,             RGUI_T(KC_QUOT),
        KC_GRV,          LCTL_T(KC_Z),  LALT_T(KC_X),  LGUI_T(KC_C),  KC_V,  KC_B,                KC_K,  KC_M,  RGUI_T(KC_COMM), LALT_T(KC_DOT),  RCTL_T(KC_SLSH),  OSM(MOD_LALT),
                                               OSM(MOD_LSFT),  KC_BSPC,  LT(_SYM, KC_TAB),      LT(_SYM, KC_ENT),  KC_SPC,  OSM(MOD_RSFT)
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TRNS,  S(KC_1),       S(KC_2),       S(KC_3),       S(KC_4),  S(KC_5),                   S(KC_6),     S(KC_7),  S(KC_8),       S(KC_9),       S(KC_0),       KC_TRNS,
        KC_TRNS,  LCTL_T(KC_1),  LALT_T(KC_2),  LGUI_T(KC_3),  KC_4,     KC_5,                      KC_6,        KC_7,     RGUI_T(KC_8),  LALT_T(KC_9),  RCTL_T(KC_0),  KC_TRNS,
        KC_TRNS,  KC_LBRC,       KC_RBRC,       KC_LEFT,       KC_RGHT,  KC_BSLS,                   S(KC_BSLS),  KC_DOWN,  KC_UP,         S(KC_LBRC),    S(KC_RBRC),    KC_TRNS,
                                               OSM(MOD_LSFT),  KC_BSPC,  LT(_SYM, KC_TAB),      LT(_SYM, KC_ENT),  KC_SPC,  OSM(MOD_RSFT)
    )
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SYM, KC_TAB):
        case LT(_SYM, KC_ENT):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
