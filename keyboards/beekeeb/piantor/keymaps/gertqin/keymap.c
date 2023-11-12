// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// Compile on MacOS:
// > brew tap ArmMbed/homebrew-formulae
// > brew install arm-none-eabi-gcc

#include QMK_KEYBOARD_H

#define L_DEF 0
#define L_NAV 1
#define L_SYM 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */

    [0] = LAYOUT_split_3x6_3(
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
        KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,
        OSM(MOD_LGUI),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
                                            OSM(MOD_LALT), TO(L_NAV),  OSM(MOD_LSFT),          OSL(L_SYM),  KC_SPC,  OSM(MOD_LCTL)
    ),
    [1] = LAYOUT_split_3x6_3(
        KC_TAB,         KC_F1,      KC_F2,     KC_F3,      KC_F4,     KC_F5,                     A(KC_LEFT),  KC_PGDN,     KC_PGUP,    A(KC_RGHT),  G(KC_LBRC),  XXXXXXX,
        KC_ESC,         G(KC_1),    G(KC_2),   G(KC_3),    G(KC_4),   G(KC_5),                   KC_LEFT,     KC_DOWN,     KC_UP,      KC_RGHT,     G(KC_RBRC),  XXXXXXX,
        OSM(MOD_LGUI),  G(KC_Z),    G(KC_X),   G(KC_C),    G(KC_V),   XXXXXXX,                   G(KC_LEFT),  G(KC_LBRC),  G(KC_RBRC), G(KC_RGHT),  XXXXXXX,  XXXXXXX,
                                            OSM(MOD_LALT), XXXXXXX,  OSM(MOD_LSFT),          OSL(L_SYM),  KC_SPC,  OSM(MOD_LCTL)
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_GRV,         S(KC_1),     S(KC_2),  S(KC_3),     S(KC_4),  S(KC_5),                   S(KC_EQL),   KC_7,  KC_8,  KC_9,  KC_LBRC,  KC_ENT,
        S(KC_GRV),      S(KC_MINS),  KC_MINS,  S(KC_QUOT),  KC_QUOT,  S(KC_LBRC),                S(KC_RBRC),  KC_4,  KC_5,  KC_6,  KC_RBRC,  KC_BSPC,
        OSM(MOD_LGUI),  S(KC_6),     S(KC_7),  S(KC_8),     S(KC_9),  S(KC_0),                   S(KC_BSLS),  KC_1,  KC_2,  KC_3,  KC_BSLS,  S(KC_QUOT),
                                            OSM(MOD_LALT), TO(L_NAV),  KC_EQL,          OSL(L_SYM),  KC_0,  OSM(MOD_LCTL)
    ),
};
