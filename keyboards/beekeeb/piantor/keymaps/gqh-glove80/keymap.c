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
    // _NAV,
    _SYM,
};
  
// #define LT_SYM_ESC LT(_SYM, KC_ESC)
// #define LT_NAV_ENT LT(_NAV, KC_ENT)
// #define LCTL_ENT LCTL_T(KC_ENT)

#define ALT_ENT LALT_T(KC_ENT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_COLN RCTL_T(KC_COLN)
#define GUI_TAB LGUI_T(KC_TAB)
#define CTL_LCK LCTL_T(KC_0)
#define ALT_4 LALT_T(KC_4)
#define GUI_5 LGUI_T(KC_5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        KC_SCLN,     KC_V,   KC_L,   KC_N,   KC_D,     KC_K,                                   KC_J,   KC_W,   KC_O,     KC_U,      KC_QUOT,   KC_MINS,
        OSL(_SYM),   KC_T,   KC_S,   KC_R,   KC_H,     KC_F,                                   KC_G,   KC_C,   KC_A,     KC_I,      KC_E,      A(KC_BSPC),
        CTL_ESC,     KC_Z,   KC_Q,   KC_X,   KC_P,     KC_B,                                   KC_M,   KC_Y,   KC_DOT,   KC_COMM,   KC_DQUO,   CTL_COLN,
                                              GUI_TAB,  KC_SPC,  ALT_ENT,            OSM_LSFT,  QK_REP,  QK_AREP
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_F12,    KC_EXLM,   KC_1,   KC_2,   KC_3,   KC_PLUS,                                 KC_PIPE,  KC_LBRC,   KC_LPRN,  KC_RPRN,  KC_RBRC,   KC_SCLN,
        KC_TRNS,   CTL_LCK,   ALT_4,  GUI_5,  KC_6,   KC_0,                                    KC_AMPR,  KC_LEFT,   KC_DOWN,  KC_UP,    KC_RIGHT,  KC_BSPC,
        QK_LLCK,   KC_BSLS,   KC_7,   KC_8,   KC_9,   KC_MINS,                                 KC_ASTR,  KC_EQL,    KC_LT,    KC_GT,    KC_SLSH,   KC_TILD,
                                              KC_TRNS,  KC_TRNS, KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    // [_NAV] = LAYOUT_split_3x6_3(
    //     KC_F12,    KC_1,       KC_2,      KC_3,      KC_4,      KC_5,                          KC_6,     KC_7,      KC_8,     KC_9,      KC_0,      KC_TRNS,
    //     KC_TRNS,   OSM_LCTL,   OSM_LALT,  OSM_LGUI,  OSM_LSFT,  XXXXXXX,                       XXXXXXX,  KC_LEFT,   KC_DOWN,  KC_UP,     KC_RIGHT,  KC_BSPC,
    //     KC_TRNS,   S(KC_TAB),  KC_LBRC,   KC_RBRC,   KC_TAB,    KC_GRV,                        KC_GRV,   KC_TAB,    KC_DOT,   KC_COMM,   KC_SLSH,   KC_TRNS,
    //                                           KC_TRNS,  KC_TRNS, KC_ENT,              KC_TRNS,  KC_TRNS,  KC_TRNS
    // ),
    // [_SYM] = LAYOUT_split_3x6_3(
    //     KC_TRNS,   XXXXXXX,    S(KC_2),  S(KC_3),  S(KC_4),    S(KC_5),                        KC_PIPE,   KC_SCLN,  KC_LBRC,  KC_RBRC,   KC_LCBR,  KC_RCBR,
    //     KC_TRNS,   XXXXXXX,    KC_ASTR,  KC_SLSH,  KC_MINS,    KC_PLUS,                        KC_AMPR,   KC_EQL,   KC_LPRN,  KC_RPRN,   KC_EXLM,  KC_BSPC,
    //     KC_TRNS,   XXXXXXX,    KC_2,     KC_1,     KC_0,       KC_TILD,                        KC_GRV,    KC_COLN,  KC_LT,    KC_GT,     KC_DQUO,  KC_BSLS,
    //                                           KC_TRNS,  KC_TRNS, KC_ENT,              KC_TRNS,  KC_TRNS,   KC_TRNS
    // )
};

const uint16_t PROGMEM cmd_spc_combo[] = {KC_SPC, QK_AREP, COMBO_END};
const uint16_t PROGMEM cmd_ent_combo[] = {ALT_ENT, QK_AREP, COMBO_END};
combo_t key_combos[] = {
    COMBO(cmd_spc_combo, G(KC_SPC)),
    COMBO(cmd_ent_combo, G(KC_ENT)),
};

const key_override_t alt_bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, A(KC_BSPC), KC_BSPC);
const key_override_t bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, S(KC_SLSH));
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_GRV);
const key_override_t x_cmd_key_override = ko_make_basic(MOD_MASK_GUI, KC_X, G(KC_C));
const key_override_t scln_cmd_key_override = ko_make_basic(MOD_MASK_GUI, KC_SCLN, G(KC_TAB));
const key_override_t i_alt_key_override = ko_make_basic(MOD_MASK_ALT, KC_I, A(KC_QUOT));
const key_override_t alt_slash_key_override = ko_make_basic(MOD_MASK_ALT, KC_SLSH, KC_BSLS);


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&alt_bspc_key_override,
	&bspc_key_override,
	&dot_key_override,
	&comma_key_override,
	&quot_key_override,
	&x_cmd_key_override,
	&scln_cmd_key_override,
	&i_alt_key_override,
	&alt_slash_key_override
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_COLN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN);
                return false;
            }
            break;
        case CTL_LCK:
            if (record->tap.count) {
                if (record->event.pressed) {
                    // Toggle the lock on the highest layer.
                    layer_lock_invert(get_highest_layer(layer_state));
                }
                return false;
            }
            break;
    }
    return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if (!mods) {
        switch (keycode) {
            case KC_T: return KC_V;
            case KC_V: return KC_T;
            case KC_S: return KC_L;
            case KC_L: return KC_S;
            case KC_R: return KC_N;
            case KC_N: return KC_R;
            case KC_P: return KC_H;
            case KC_C: return KC_Y;
            case KC_U: return KC_I;
            case KC_I: return KC_U;
            case KC_O: return KC_A;
            case KC_A: return KC_O;
            case KC_E: return KC_QUOT;
            case KC_QUOT: return KC_E;
        }
    }

    return KC_TRNS;
}
