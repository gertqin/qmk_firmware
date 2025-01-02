// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// Compile on MacOS:
// > brew tap ArmMbed/homebrew-formulae
// > brew install arm-none-eabi-gcc

#include QMK_KEYBOARD_H

#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.

#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)

enum LAYERS {
    _MAIN,
    _SYM,
};

#define LT_SYM_ESC LT(_SYM, KC_ESC)

#define CTL_ENT LCTL_T(KC_ENT)
#define GUI_TAB LGUI_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        KC_SCLN,     KC_V,   KC_M,   KC_L,   KC_P,     KC_B,                                   KC_J,   QK_REP,  KC_O,     KC_U,      KC_QUOT,   KC_MINS,
        LT_SYM_ESC,  KC_S,   KC_T,   KC_R,   KC_H,     KC_F,                                   KC_Y,   KC_C,    KC_A,     KC_I,      KC_E,      A(KC_BSPC),
        KC_GRV,      KC_Z,   KC_Q,   KC_X,   KC_D,     KC_K,                                   KC_G,   KC_W,    KC_DOT,   KC_COMM,   KC_DQUO,   OSM_RSFT,
                                              GUI_TAB,  KC_N,  OSM_LSFT,            CTL_ENT,  KC_SPC,  OSM_LALT
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_F12,    KC_EXLM,  KC_3,   KC_2,   KC_1,   KC_PLUS,                                 KC_PIPE,  KC_LBRC,   KC_LPRN,  KC_RPRN,  KC_RBRC,   KC_SCLN,
        QK_LLCK,   KC_DOT,   KC_6,   KC_5,   KC_4,   KC_0,                                    KC_AMPR,  KC_LEFT,   KC_DOWN,  KC_UP,    KC_RIGHT,  KC_BSPC,
        KC_LCTL,   KC_BSLS,  KC_9,   KC_8,   KC_7,   KC_MINS,                                 KC_ASTR,  KC_EQL,    KC_LT,    KC_GT,    KC_SLSH,   OSM_RSFT,
                                              GUI_TAB,  QK_LLCK, OSM_LSFT,          CTL_ENT,  KC_SPC,  OSM_LALT
    ),
};

const uint16_t PROGMEM lcbr_combo[] = {KC_LBRC, KC_LPRN, COMBO_END};
const uint16_t PROGMEM rcbr_combo[] = {KC_RPRN, KC_RBRC, COMBO_END};
combo_t key_combos[] = {
    COMBO(lcbr_combo, KC_LCBR),
    COMBO(rcbr_combo, KC_RCBR),
};

const key_override_t bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_GRV);

const key_override_t alt_i_key_override = ko_make_basic(MOD_MASK_ALT, KC_I, A(KC_QUOT));

const key_override_t cmd_x_key_override = ko_make_basic(MOD_MASK_GUI, KC_X, G(KC_C));
const key_override_t cmd_h_key_override = ko_make_basic(MOD_MASK_GUI, KC_H, G(KC_TAB));
const key_override_t cmd_m_key_override = ko_make_basic(MOD_MASK_GUI, KC_M, G(KC_N));


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&bspc_key_override,
	&dot_key_override,
	&comma_key_override,
	&quot_key_override,
	&alt_i_key_override,
	&cmd_x_key_override,
	&cmd_h_key_override,
	&cmd_m_key_override
};

