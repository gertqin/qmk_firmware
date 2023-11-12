// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// Compile on MacOS:
// > brew tap ArmMbed/homebrew-formulae
// > brew install arm-none-eabi-gcc

#include QMK_KEYBOARD_H

#define L_DEF TO(0)
#define L_NAV TO(1)
#define L_SYM TO(2)
#define L_SFT TO(3)
#define L_CTL TO(4)
#define L_ALT TO(5)
#define L_FUN TO(6)

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
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
        KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,
        LGUI_T(KC_MINS),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
                                            L_CTL, L_NAV,  L_SYM,          L_SFT,  KC_SPC,  L_ALT
    ),
    [1] = LAYOUT_split_3x6_3(
        KC_TAB,   KC_F1,      KC_F2,     KC_F3,      KC_F4,     KC_F5,                     A(KC_LEFT),  KC_PGDN,     KC_PGUP,    A(KC_RGHT),  XXXXXXX,  XXXXXXX,
        L_DEF,    G(KC_1),    G(KC_2),   G(KC_3),    G(KC_4),   G(KC_5),                   KC_LEFT,     KC_DOWN,     KC_UP,      KC_RGHT,     XXXXXXX,  XXXXXXX,
        KC_GRV,  G(KC_Z),    G(KC_X),   G(KC_C),    G(KC_V),   XXXXXXX,                   G(KC_LEFT),  G(KC_LBRC),  G(KC_RBRC), G(KC_RGHT),  XXXXXXX,  XXXXXXX,
                                            KC_LCTL, KC_LGUI,   L_SYM,               L_SFT,  KC_SPC,  KC_LALT
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_TAB,      KC_1,      KC_2,     KC_3,      KC_4,     KC_5,                         KC_6,     KC_7,        KC_8,     KC_9,     KC_0,       KC_ENT,
        L_DEF,       S(KC_1),   S(KC_2),  S(KC_3),   S(KC_4),  S(KC_5),                      S(KC_6),  S(KC_7),     S(KC_8),  S(KC_9),  S(KC_0),    KC_BSPC,
        S(KC_MINS),  S(KC_GRV), KC_GRV,   S(KC_EQL), KC_EQL,   S(KC_BSLS),                   KC_BSLS,  S(KC_LBRC),  KC_LBRC,  KC_RBRC,  S(KC_RBRC), S(KC_QUOT),
                                            KC_LCTL, KC_LGUI,  L_DEF,             KC_LSFT,  KC_SPC,  KC_LALT
    ),
    [3] = LAYOUT_split_3x6_3(
        KC_TAB,      S(KC_Q),    S(KC_W),    S(KC_E),    S(KC_R),    S(KC_T),             S(KC_Y),    S(KC_U),    S(KC_I),    S(KC_O),    S(KC_P),    S(KC_ENT),
        L_DEF,       S(KC_A),    S(KC_S),    S(KC_D),    S(KC_F),    S(KC_G),             S(KC_H),    S(KC_J),    S(KC_K),    S(KC_L),    S(KC_SCLN), S(KC_BSPC),
        S(KC_MINS),  S(KC_Z),    S(KC_X),    S(KC_C),    S(KC_V),    S(KC_B),             S(KC_N),    S(KC_M),    S(KC_COMM), S(KC_DOT),  S(KC_SLSH), S(KC_QUOT),
                                            KC_LCTL, KC_LGUI,  L_SYM,               L_DEF,  KC_SPC,  KC_LALT
    ),
    [4] = LAYOUT_split_3x6_3(
        KC_TAB,      C(KC_Q),    C(KC_W),    C(KC_E),    C(KC_R),    C(KC_T),             C(KC_Y),    C(KC_U),    C(KC_I),    C(KC_O),    C(KC_P),    C(KC_ENT),
        L_DEF,       C(KC_A),    C(KC_S),    C(KC_D),    C(KC_F),    C(KC_G),             C(KC_H),    C(KC_J),    C(KC_K),    C(KC_L),    C(KC_SCLN), C(KC_BSPC),
        C(KC_MINS),  C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    C(KC_B),             C(KC_N),    C(KC_M),    C(KC_COMM), C(KC_DOT),  C(KC_SLSH), C(KC_QUOT),
                                            L_DEF, KC_LGUI,  L_SYM,               KC_LSFT,  KC_SPC,  KC_LALT
    ),
    [5] = LAYOUT_split_3x6_3(
        KC_TAB,      A(KC_Q),    A(KC_W),    A(KC_E),    A(KC_R),    A(KC_T),             A(KC_Y),    A(KC_U),    A(KC_I),    A(KC_O),    A(KC_P),    A(KC_ENT),
        L_DEF,       A(KC_A),    A(KC_S),    A(KC_D),    A(KC_F),    A(KC_G),             A(KC_H),    A(KC_J),    A(KC_K),    A(KC_L),    A(KC_SCLN), A(KC_BSPC),
        A(KC_MINS),  A(KC_Z),    A(KC_X),    A(KC_C),    A(KC_V),    A(KC_B),             A(KC_N),    A(KC_M),    A(KC_COMM), A(KC_DOT),  A(KC_SLSH), A(KC_QUOT),
                                            KC_LCTL, KC_LGUI,  L_SYM,               KC_LSFT,  KC_SPC,  L_DEF
    )
};
