// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// Compile on MacOS:
// > brew tap ArmMbed/homebrew-formulae
// > brew install arm-none-eabi-gcc

#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _NAV,
    _SYM,
    _FN,
};

enum custom_keycodes {
   W_BSPC = SAFE_RANGE,
};

enum keycode_aliases {
    OSM_LCTL = OSM(MOD_LCTL),
    OSM_LALT = OSM(MOD_LALT),
    OSM_LGUI = OSM(MOD_LGUI),
    OSM_LSFT = OSM(MOD_LSFT),
    OSM_RSFT = OSM(MOD_RSFT),

    OSL_NAV = OSL(_NAV),

    SYM_H = LT(_SYM, KC_H),
    SYM_C = LT(_SYM, KC_C),

    CTL_Z = CTL_T(KC_Z),
    CTL_SLSH = CTL_T(KC_SLSH),

    FN_ENT = LT(_FN, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        KC_MINS,   KC_V,   KC_B,   KC_L,   KC_F,     KC_Q,                     KC_QUOT,  KC_W,   KC_O,     KC_U,     KC_SCLN,  W_BSPC,
        OSM_LSFT,  KC_S,   KC_N,   KC_T,   SYM_H,    KC_M,                     KC_Y,     SYM_C,  KC_A,     KC_I,     KC_E,     OSM_RSFT,
        KC_ESC,    CTL_Z,  KC_X,   KC_J,   KC_D,     KC_K,                     KC_G,     KC_P,   KC_DOT,   KC_COMM,  CTL_SLSH, FN_ENT,
                                       OSM_LGUI,  KC_R,  QK_REP,          OSL_NAV,  KC_SPC,  OSM_LALT
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_TRNS,   KC_MINS,  KC_6,   KC_5,   KC_4,   KC_PLUS,                  KC_LBRC,  KC_LCBR,   KC_RCBR,  KC_RBRC,  KC_BSPC,   KC_TRNS,
        KC_TRNS,   KC_0,     KC_3,   KC_2,   KC_1,   KC_UNDS,                  KC_LEFT,  KC_DOWN,   KC_UP,    KC_RIGHT, KC_ENT,    KC_TRNS,
        KC_TRNS,   OSM_LCTL, KC_9,   KC_8,   KC_7,   KC_ASTR,                  KC_GRV,   KC_TAB,    KC_DOT,   KC_COMM,  KC_SLSH,   KC_ENT,
                                       OSM_LGUI,  OSM_LALT, QK_REP,       KC_TRNS,  KC_SPC,  OSM_LALT
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_AT,   KC_LT,   KC_GT,   KC_MINS, KC_PERC,                  KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR,  KC_BSPC, KC_TRNS,
        KC_TRNS, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,                  KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, KC_TRNS,
        KC_TRNS, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE,                  KC_GRV,  KC_COLN, KC_COMM, KC_DOT,  KC_QUOT, KC_ENT,
                                       OSM_LGUI,  OSM_LALT, QK_REP,       KC_TRNS,  KC_SPC,  OSM_LALT
    ),
    [_FN] = LAYOUT_split_3x6_3(
        XXXXXXX,   KC_F11,  KC_F6,  KC_F5,  KC_F4,  XXXXXXX,                   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,
        OSM_LSFT,  KC_F10,  KC_F3,  KC_F2,  KC_F1,  XXXXXXX,                   XXXXXXX,  KC_LSFT,   KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_ESC,    KC_F12,  KC_F9,  KC_F8,  KC_F7,  XXXXXXX,                   XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                       OSM_LGUI,  OSM_LALT, QK_REP,       QK_LLCK,  KC_TRNS,  KC_TRNS
    ),
};

const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t ctl_slash_key_override = ko_make_basic(MOD_MASK_SHIFT, CTL_SLSH, KC_BSLS);
const key_override_t cmd_j_key_override = ko_make_basic(MOD_MASK_GUI, KC_J, G(KC_C));
const key_override_t cmd_c_key_override = ko_make_basic(MOD_MASK_GUI, KC_C, G(KC_J));
const key_override_t alt_i_key_override = ko_make_basic(MOD_MASK_ALT, KC_I, A(KC_QUOT));
const key_override_t alt_quot_key_override = ko_make_basic(MOD_MASK_ALT, KC_QUOT, A(KC_I));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &dot_key_override,
    &comma_key_override,
    &ctl_slash_key_override,
    &cmd_j_key_override,
    &cmd_c_key_override,
    &alt_i_key_override,
    &alt_quot_key_override
};

const uint16_t caps_combo[] PROGMEM = {OSM_LSFT, OSM_RSFT, COMBO_END};
combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    uint8_t mod_state = get_mods();
    uint8_t os_mod_state = get_oneshot_mods();

    switch (keycode) {
    case W_BSPC:
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_GUI || os_mod_state & MOD_MASK_GUI) {
                tap_code16(KC_BSPC);
            } else if (mod_state & MOD_MASK_CTRL) {
                del_mods(MOD_MASK_CTRL);
                tap_code16(KC_DEL);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_SHIFT || os_mod_state & MOD_MASK_SHIFT) {
                tap_code16(KC_BSPC);
            } else {
                tap_code16(A(KC_BSPC));
            }
        }
        return false;  // Skip default handling.
    case SYM_H:
        if (mod_state & MOD_MASK_GUI || os_mod_state & MOD_MASK_GUI) {
            if (record->event.pressed) {
                register_code(KC_H);
            } else {
                unregister_code(KC_H);
            }
            return false;
        }
    }

    return true;  // Continue default handling.
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_Z:
        case CTL_SLSH:
        case FN_ENT:
            return 220;
        default:
            return TAPPING_TERM;
    }
}

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*',
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*',
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*',
                       '*', '*', '*',  '*', '*', '*'
    );
