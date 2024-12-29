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

enum custom_keycodes {
    CKC_RN = SAFE_RANGE,
    CKC_PH,
};
// #define LT_SYM_ESC LT(_SYM, KC_ESC)
// #define LT_NAV_ENT LT(_NAV, KC_ENT)
// #define LCTL_ENT LCTL_T(KC_ENT)

#define LT_SYM_ESC LT(_SYM, KC_ESC)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_GRV LCTL_T(KC_GRV)

#define ALT_ENT LALT_T(KC_ENT)
#define CTL_COLN RCTL_T(KC_COLN)
#define GUI_TAB LGUI_T(KC_TAB)
#define GUI_ESC LGUI_T(KC_ESC)
#define CTL_DOT LCTL_T(KC_DOT)
#define ALT_6 LALT_T(KC_6)
#define GUI_5 LGUI_T(KC_5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        KC_SCLN,     KC_V,   KC_L,   KC_N,   KC_D,     KC_K,                                   KC_J,   KC_C,   KC_O,     KC_U,      KC_QUOT,   KC_MINS,
        LT_SYM_ESC,  KC_T,   KC_S,   KC_R,   KC_H,     KC_F,                                   KC_Y,   KC_M,   KC_A,     KC_I,      KC_E,      A(KC_BSPC),
        CTL_COLN,    KC_Z,   KC_Q,   KC_X,   KC_P,     KC_B,                                   KC_W,   KC_G,   KC_DOT,   KC_COMM,   KC_DQUO,   CTL_GRV,
                                              GUI_TAB,  KC_SPC,  OSM_LSFT,            ALT_ENT,  QK_REP,  QK_AREP
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_F12,    KC_EXLM,   KC_9,   KC_8,   KC_7,   KC_PLUS,                                 KC_PIPE,  KC_LBRC,   KC_LPRN,  KC_RPRN,  KC_RBRC,   KC_SCLN,
        QK_LLCK,   CTL_DOT,   ALT_6,  GUI_5,  KC_4,   KC_0,                                    KC_AMPR,  KC_LEFT,   KC_DOWN,  KC_UP,    KC_RIGHT,  KC_BSPC,
        KC_TAB,    KC_BSLS,   KC_3,   KC_2,   KC_1,   KC_MINS,                                 KC_ASTR,  KC_EQL,    KC_LT,    KC_GT,    KC_SLSH,   KC_TILD,
                                              KC_TRNS,   KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS,  QK_LLCK
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

const uint16_t PROGMEM r_n_combo[] = {KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM p_h_combo[] = {KC_P, KC_H, COMBO_END};
const uint16_t PROGMEM cmd_spc_combo[] = {KC_SPC, QK_AREP, COMBO_END};
const uint16_t PROGMEM cmd_ent_combo[] = {ALT_ENT, QK_AREP, COMBO_END};
combo_t key_combos[] = {
    COMBO(r_n_combo, CKC_RN),
    COMBO(p_h_combo, CKC_PH),
    COMBO(cmd_spc_combo, G(KC_SPC)),
    COMBO(cmd_ent_combo, G(KC_ENT)),
};

const key_override_t bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_GRV);
const key_override_t eql_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);

const key_override_t alt_i_key_override = ko_make_basic(MOD_MASK_ALT, KC_I, A(KC_QUOT));
const key_override_t alt_dot_key_override = ko_make_basic(MOD_MASK_ALT, KC_DOT, KC_EXLM);
const key_override_t alt_comma_key_override = ko_make_basic(MOD_MASK_ALT, KC_COMM, KC_QUES);
const key_override_t alt_quot_key_override = ko_make_basic(MOD_MASK_ALT, KC_QUOT, KC_GRV);
const key_override_t alt_scln_key_override = ko_make_basic(MOD_MASK_ALT, KC_SCLN, KC_COLN);
const key_override_t alt_dquo_key_override = ko_make_basic(MOD_MASK_ALT, KC_DQUO, KC_DQUO);

const key_override_t cmd_x_key_override = ko_make_basic(MOD_MASK_GUI, KC_X, G(KC_C));
const key_override_t cmd_h_key_override = ko_make_basic(MOD_MASK_GUI, KC_H, G(KC_TAB));


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&bspc_key_override,
	&dot_key_override,
	&comma_key_override,
	&quot_key_override,
	&eql_key_override,
	&alt_i_key_override,
	&alt_dot_key_override,
	&alt_comma_key_override,
	&alt_quot_key_override,
	&alt_scln_key_override,
	&alt_dquo_key_override,
	&cmd_x_key_override,
	&cmd_h_key_override
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_COLN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN);
                return false;
            }
            break;
        case CKC_RN:
            if (record->event.pressed) {
                SEND_STRING("rn");
            }
            break;
        case CKC_PH:
            if (record->event.pressed) {
                SEND_STRING("ph");
            }
            break;
        case KC_SPC: {
            if (get_repeat_key_count() > 1) {
                // Double repeat key after space, set caps word
                if (record->event.pressed) {
                    clear_oneshot_mods();
                    caps_word_on();
                }
                return false;
            } else if (get_repeat_key_count() > 0) {
                // Repeat key after space, set one-shot shift
                if (record->event.pressed) {
                    set_oneshot_mods(MOD_BIT(KC_LSFT));    
                }
                return false;
            }
        }
    }
    return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    bool shifted = (mods & MOD_MASK_SHIFT);
    switch (keycode) {
        case KC_E: return KC_B;
        case KC_B: return KC_E;
        case KC_TAB:
            if (shifted) { return KC_TAB; } 
            else { return S(KC_TAB); }
    }

    return KC_TRNS;
}
