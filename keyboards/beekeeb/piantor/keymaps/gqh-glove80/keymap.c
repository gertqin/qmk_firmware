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

enum LAYERS {
    _MAIN,
    _NAV,
    _SYM,
};
  
#define LT_SYM_ESC LT(_SYM, KC_ESC)
#define LT_NAV_ENT LT(_NAV, KC_ENT)
#define LCTL_ENT LCTL_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        KC_SCLN,     KC_V,   KC_L,   KC_N,   KC_D,     KC_K,                                   KC_J,   KC_W,   KC_O,     KC_U,      KC_QUOT,   KC_MINS,
        LT_SYM_ESC,  KC_T,   KC_S,   KC_R,   KC_H,     KC_F,                                   KC_G,   KC_C,   KC_A,     KC_I,      KC_E,      A(KC_BSPC),
        OSM_LSFT,    KC_Z,   KC_Q,   KC_X,   KC_P,     KC_B,                                   KC_M,   KC_Y,   KC_DOT,   KC_COMM,   KC_DQUO,   OSM_RSFT,
                                              OSM_LGUI,  KC_SPC,  LCTL_ENT,         MO(_NAV),  QK_REP,  OSM_LALT
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_F12,    KC_1,       KC_2,      KC_3,      KC_4,      KC_5,                          KC_6,     KC_7,      KC_8,     KC_9,      KC_0,      KC_TRNS,
        KC_TRNS,   OSM_LCTL,   OSM_LALT,  OSM_LGUI,  OSM_LSFT,  XXXXXXX,                       XXXXXXX,  KC_LEFT,   KC_DOWN,  KC_UP,     KC_RIGHT,  KC_BSPC,
        KC_TRNS,   S(KC_TAB),  KC_LBRC,   KC_RBRC,   KC_TAB,    KC_GRV,                        KC_GRV,   KC_TAB,    KC_DOT,   KC_COMM,   KC_SLSH,   KC_TRNS,
                                              KC_TRNS,  KC_TRNS, KC_ENT,              KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TRNS,   XXXXXXX,    S(KC_2),  S(KC_3),  S(KC_4),    S(KC_5),                        KC_PIPE,   KC_SCLN,  KC_LBRC,  KC_RBRC,   KC_LCBR,  KC_RCBR,
        KC_TRNS,   XXXXXXX,    KC_ASTR,  KC_SLSH,  KC_MINS,    KC_PLUS,                        KC_AMPR,   KC_EQL,   KC_LPRN,  KC_RPRN,   KC_EXLM,  KC_BSPC,
        KC_TRNS,   XXXXXXX,    KC_2,     KC_1,     KC_0,       KC_TILD,                        KC_GRV,    KC_COLN,  KC_LT,    KC_GT,     KC_DQUO,  KC_BSLS,
                                              KC_TRNS,  KC_TRNS, KC_ENT,              KC_TRNS,  KC_TRNS,   KC_TRNS
    )
};

const uint16_t PROGMEM ent_combo[] = {KC_G, KC_C, COMBO_END};
combo_t key_combos[] = {
    COMBO(ent_combo, KC_ENT),
};

const key_override_t spc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_UNDS);
const key_override_t alt_bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, A(KC_BSPC), KC_BSPC);
const key_override_t bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, S(KC_SLSH));
const key_override_t quote_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_GRV);
const key_override_t x_cmd_key_override = ko_make_basic(MOD_MASK_GUI, KC_X, G(KC_C));
const key_override_t scln_cmd_key_override = ko_make_basic(MOD_MASK_GUI, KC_SCLN, G(KC_TAB));
const key_override_t i_alt_key_override = ko_make_basic(MOD_MASK_ALT, KC_I, A(KC_QUOT));


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&spc_key_override,
	&alt_bspc_key_override,
	&bspc_key_override,
	&dot_key_override,
	&comma_key_override,
	&quote_key_override,
	&x_cmd_key_override,
	&scln_cmd_key_override,
	&i_alt_key_override
};

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
     if (!mods) {
        switch (keycode) {
            case KC_SPC:
                return OSM_LSFT;
        }
    }

    return QK_REP;
}
