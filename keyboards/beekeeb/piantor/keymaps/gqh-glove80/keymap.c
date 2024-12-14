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

enum LAYERS {
    _MAIN,
    _NAV,
    _SYM,
};
  
#define LT_SYM_ESC LT(_SYM, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        KC_SCLN,     KC_V,   KC_L,   KC_N,   KC_D,     KC_K,                                   KC_J,   KC_W,   KC_O,     KC_U,      KC_QUOT,     KC_EQL,
        LT_SYM_ESC,  KC_T,   KC_S,   KC_R,   KC_H,     KC_F,                                   KC_G,   KC_C,   KC_A,     KC_I,      KC_E,        A(KC_BSPC),
        S(KC_SCLN),  KC_Z,   KC_Q,   KC_X,   KC_P,     KC_B,                                   KC_M,   KC_Y,   KC_DOT,   KC_COMM,   S(KC_QUOT),  KC_MINS,
                                              OSM_LGUI,  MO(_NAV),  OSM_LSFT,           KC_ENT,  KC_SPC,  S(KC_MINS)
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_F12,    KC_1,       KC_2,      KC_3,      KC_4,      KC_5,                          KC_6,     KC_7,     KC_8,     KC_9,     KC_0,        KC_TRNS,
        KC_TRNS,   OSM_LCTL,   OSM_LALT,  OSM_LGUI,  OSM_LSFT,  A(KC_ENT),                     S(KC_7),  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,    KC_BSPC,
        KC_BSLS,   S(KC_TAB),  KC_LBRC,   KC_RBRC,   KC_TAB,    G(KC_C),                       KC_GRV,   KC_TAB,   A(KC_A),  A(KC_O),  A(KC_QUOT),  KC_TRNS,
                                              KC_TRNS,  KC_TRNS, KC_TRNS,               KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TRNS,   XXXXXXX,    S(KC_2),  S(KC_3),  S(KC_4),    S(KC_5),                        S(KC_BSLS), KC_SCLN,    KC_LBRC,     KC_RBRC,   S(KC_LBRC), S(KC_RBRC),
        KC_TRNS,   XXXXXXX,    S(KC_8),  KC_SLSH,  KC_MINS,    S(KC_EQL),                      S(KC_7),    KC_EQL,     S(KC_9),     S(KC_0),   S(KC_1),    KC_BSPC,
        KC_TRNS,   XXXXXXX,    XXXXXXX,  KC_QUOT,  KC_GRV,     S(KC_6),                        KC_BSLS,    S(KC_SCLN), S(KC_COMM),  S(KC_DOT), S(KC_QUOT), KC_MINS,
                                              KC_TRNS,  KC_TRNS, KC_TRNS,               KC_TRNS,  KC_TRNS,  KC_TRNS
    )
};

const key_override_t alt_bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, A(KC_BSPC), KC_BSPC);
const key_override_t bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, S(KC_1));
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, S(KC_SLSH));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&alt_bspc_key_override,
	&dot_key_override,
	&comma_key_override,
};

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if (!mods) {
        switch (keycode) {
            case KC_R: return KC_N;
            case KC_L: return KC_S;
        }
    }

    return KC_H;  // Default to H
}
