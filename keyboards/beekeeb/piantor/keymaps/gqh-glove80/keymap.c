// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// Compile on MacOS:
// > brew tap ArmMbed/homebrew-formulae
// > brew install arm-none-eabi-gcc

#include QMK_KEYBOARD_H


enum LAYERS {
    _COLEMAK,
    _COLEMAK_DK,
    _SYM_LEFT,
    _SYM_RIGHT,
};

enum custom_keycodes {
    KC_COLEMAK = SAFE_RANGE,
    KC_COLE_DK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [_DEF] = LAYOUT_split_3x6_3(
    //     KC_EQL,          KC_Q,          KC_W,          KC_E,          KC_R,    KC_T,                KC_Y,  KC_U,  KC_I,            KC_O,            KC_P,             KC_MINS,
    //     LGUI_T(KC_ESC),  KC_A,          KC_S,          KC_D,          KC_F,    KC_G,                KC_H,  KC_J,  KC_K,            KC_L,            KC_SCLN,          RGUI_T(KC_QUOT),
    //     KC_GRV,          LCTL_T(KC_Z),  LALT_T(KC_X),  LGUI_T(KC_C),  KC_V,    KC_B,                KC_N,  KC_M,  RGUI_T(KC_COMM), LALT_T(KC_DOT),  RCTL_T(KC_SLSH),  OSM(MOD_LALT),
    //                                            OSM(MOD_LSFT),  KC_BSPC,  LT(_SYM, KC_TAB),      LT(_SYM, KC_ENT),  KC_SPC,  OSM(MOD_RSFT)
    // ),
    [_COLEMAK] = LAYOUT_split_3x6_3(
        KC_EQL,                 KC_Q,          KC_W,          KC_F,          KC_P,  KC_B,                KC_J,  KC_L,  KC_U,            KC_Y,            KC_SCLN,          KC_MINS,
        KC_ESC,                 KC_A,          KC_R,          KC_S,          KC_T,  KC_G,                KC_H,  KC_N,  KC_E,            KC_I,            KC_O,             KC_QUOT,
        LT(_SYM_LEFT, KC_GRV),  LCTL_T(KC_Z),  LALT_T(KC_X),  LGUI_T(KC_C),  KC_D,  KC_V,                KC_K,  KC_M,  RGUI_T(KC_COMM), LALT_T(KC_DOT),  RCTL_T(KC_SLSH),  KC_BSLS,
                                             OSM(MOD_LSFT),  KC_BSPC,  LT(_SYM_RIGHT, KC_TAB),      LT(_SYM_LEFT, KC_ENT),  KC_SPC,  OSM(MOD_RSFT)
    ),
    [_COLEMAK_DK] = LAYOUT_split_3x6_3(
        KC_EQL,                 KC_Q,          KC_W,          KC_F,          KC_P,  KC_B,                KC_J,  KC_L,  KC_U,            KC_Y,            A(KC_O),          A(KC_A),
        KC_ESC,                 KC_A,          KC_R,          KC_S,          KC_T,  KC_G,                KC_H,  KC_N,  KC_E,            KC_I,            KC_O,             A(KC_QUOT),
        LT(_SYM_LEFT, KC_GRV),  LCTL_T(KC_Z),  LALT_T(KC_X),  LGUI_T(KC_C),  KC_D,  KC_V,                KC_K,  KC_M,  RGUI_T(KC_COMM), LALT_T(KC_DOT),  RCTL_T(KC_SLSH),  KC_QUOT,
                                            OSM(MOD_LSFT),  KC_BSPC,  LT(_SYM_RIGHT, KC_TAB),      LT(_SYM_LEFT, KC_ENT),  KC_SPC,  OSM(MOD_RSFT)
    ),
    [_SYM_LEFT] = LAYOUT_split_3x6_3(
        S(KC_EQL),  S(KC_1),       S(KC_2),       S(KC_3),  S(KC_4),   S(KC_5),              KC_F6,     KC_F7,    KC_F8,    KC_F9,           KC_F10,          KC_MINS,
        KC_TRNS,    KC_1,          KC_2,          KC_3,     KC_4,      KC_5,                 S(KC_6),   KC_MINS,  S(KC_8),  XXXXXXX,         KC_RGUI,         KC_QUOT,
        S(KC_GRV),  LCTL_T(KC_6),  LALT_T(KC_7),  KC_8,     KC_9,      KC_0,                 XXXXXXX,   KC_F11,   KC_F12,   DF(KC_COLEMAK),  DF(KC_COLE_DK),  KC_BSLS,
                                           OSM(MOD_LSFT),  A(KC_BSPC),  KC_TAB,      KC_ENT,  KC_SPC,  OSM(MOD_RSFT)
    ),
    [_SYM_RIGHT] = LAYOUT_split_3x6_3(
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                          S(KC_7),     S(KC_LBRC),  S(KC_9),     S(KC_0),    S(KC_SCLN),  S(KC_MINS),
        KC_TRNS,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  XXXXXXX,                        KC_LEFT,     KC_DOWN,     KC_UP,       KC_RGHT,    S(KC_RBRC),  S(KC_QUOT),
        KC_TRNS,  G(KC_Z),  G(KC_X),  G(KC_C),  G(KC_V),  SGUI(KC_Z),                     KC_LBRC,     KC_RBRC,     S(KC_COMM),  S(KC_DOT),  S(KC_SLSH),  S(KC_BSLS),
                                           OSM(MOD_LSFT),  A(KC_BSPC),  KC_TAB,      KC_ENT,  KC_SPC,  OSM(MOD_RSFT)
    )
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SYM_RIGHT, KC_TAB):
        case LT(_SYM_LEFT, KC_ENT):
        case LT(_SYM_LEFT, KC_GRV):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
