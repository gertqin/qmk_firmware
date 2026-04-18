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
   ARROW,
};

enum keycode_aliases {
    OSM_LCTL = OSM(MOD_LCTL),
    OSM_LALT = OSM(MOD_LALT),
    OSM_LGUI = OSM(MOD_LGUI),
    OSM_LSFT = OSM(MOD_LSFT),
    OSM_RSFT = OSM(MOD_RSFT),

    OSL_NAV = OSL(_NAV),
    OSL_SYM = OSL(_SYM),

    CTL_X = CTL_T(KC_X),
    CTL_SCLN = CTL_T(KC_SCLN),
    CTL_SLSH = CTL_T(KC_SLSH),

    FN_ENT = LT(_FN, KC_ENT),

    GC_LEFT = G(C(KC_LEFT)),
    GC_RIGHT = G(C(KC_RIGHT)),
    GA_LEFT = G(A(KC_LEFT)),
    GA_RIGHT = G(A(KC_RIGHT)),
    S_ESC = S(KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        KC_MINS,   KC_F,   KC_L,   KC_H,   KC_V,    KC_Q,                     KC_QUOT,  KC_W,   KC_U,     KC_O,    KC_Y,      KC_BSPC,
        OSM_LSFT,  KC_S,   KC_R,   KC_N,   KC_T,    KC_K,                     KC_C,     KC_D,   KC_E,     KC_A,    KC_I,      OSM_RSFT,
        KC_ESC,    CTL_X,  KC_J,   KC_B,   KC_M,    KC_Z,                     KC_P,     KC_G,   KC_COMM,  KC_DOT,  CTL_SCLN,  FN_ENT,
                                    OSM_LGUI,  OSM_LALT,  OSL_SYM,       OSL_NAV,  KC_SPC,  KC_TAB
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_TRNS,   KC_MINS,   KC_6,   KC_5,   KC_4,   KC_PLUS,                  GC_LEFT,  GA_LEFT, GA_RIGHT, GC_RIGHT, S_ESC,   KC_BSPC,
        KC_TRNS,   KC_0,      KC_3,   KC_2,   KC_1,   KC_UNDS,                  KC_LEFT,  KC_DOWN, KC_UP,    KC_RIGHT, KC_DOT,  KC_TRNS,
        KC_TRNS,   CTL_SLSH,  KC_9,   KC_8,   KC_7,   KC_ASTR,                  SELWBAK,  KC_TAB,  KC_GRV,   SELWORD,  KC_DEL,  KC_ENT,
                                    OSM_LGUI,  OSM_LALT,  OSL_SYM,       QK_LLCK,  KC_SPC,  KC_TAB
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TILD, KC_LT,   KC_GT,   KC_MINS, KC_PERC,                  KC_CIRC,  KC_LCBR, KC_RCBR, KC_DLR,  KC_QUOT, KC_BSPC,
        KC_TRNS, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,                  KC_HASH,  KC_LPRN, KC_RPRN, KC_COLN, KC_DQUO, ARROW,
        KC_TRNS, KC_BSLS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE,                  KC_AT,    KC_GRV,  KC_COMM, KC_DOT,  KC_SCLN, KC_ENT,
                                    OSM_LGUI,  OSM_LALT,  QK_LLCK,      OSM_LGUI,  KC_SPC,  KC_TAB
    ),
    [_FN] = LAYOUT_split_3x6_3(
        XXXXXXX,   KC_F11,  KC_F6,  KC_F5,  KC_F4,  XXXXXXX,                   DT_PRNT,  DT_DOWN,   DT_UP,   XXXXXXX,  XXXXXXX,  QK_BOOT,
        OSM_LSFT,  KC_F10,  KC_F3,  KC_F2,  KC_F1,  XXXXXXX,                   XXXXXXX,  KC_LSFT,   KC_LCTL, XXXXXXX,  XXXXXXX,  XXXXXXX,
        OSM_LCTL,  KC_F12,  KC_F9,  KC_F8,  KC_F7,  XXXXXXX,                   XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
                                    OSM_LGUI,  OSM_LALT, QK_LLCK,       QK_LLCK,  KC_TRNS,  KC_TRNS
    ),
};

const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t ctl_slash_key_override = ko_make_basic(MOD_MASK_SHIFT, CTL_SLSH, KC_BSLS);
const key_override_t cmd_h_key_override = ko_make_basic(MOD_MASK_GUI, KC_H, G(KC_C));
const key_override_t cmd_c_key_override = ko_make_basic(MOD_MASK_GUI, KC_C, G(KC_H));
const key_override_t alt_i_key_override = ko_make_basic(MOD_MASK_ALT, KC_I, A(KC_QUOT));
const key_override_t alt_quot_key_override = ko_make_basic(MOD_MASK_ALT, KC_QUOT, A(KC_I));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &dot_key_override,
    &comma_key_override,
    &ctl_slash_key_override,
    &cmd_h_key_override,
    &cmd_c_key_override,
    &alt_i_key_override,
    &alt_quot_key_override
};

const uint16_t caps_combo[] PROGMEM = {OSM_LSFT, OSM_RSFT, COMBO_END};
combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG),         // two shifts => activate Caps Word.
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*',
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*',
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*',
                       '*', '*', '*',  '*', '*', '*'
    );

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT_LSHIFT); // Apply shift to the next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_COLN:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    uint8_t os_mod_state = get_oneshot_mods();

    bool gui = mod_state & MOD_MASK_GUI || os_mod_state & MOD_MASK_GUI;
    bool shift = mod_state & MOD_MASK_SHIFT || os_mod_state & MOD_MASK_SHIFT;
    bool alt = mod_state & MOD_MASK_ALT || os_mod_state & MOD_MASK_ALT;
    bool ctrl = mod_state & MOD_MASK_CTRL || os_mod_state & MOD_MASK_CTRL;

    switch (keycode) {
    case W_BSPC:
        if (record->event.pressed) {
            if (shift || gui) {
                tap_code16(KC_BSPC);
            } else if (alt) {
                del_mods(MOD_MASK_ALT);
                del_oneshot_mods(MOD_MASK_ALT);
                tap_code16(KC_BSPC);
                set_mods(mod_state);
            } else if (ctrl) {
                del_mods(MOD_MASK_CTRL);
                del_oneshot_mods(MOD_MASK_CTRL);
                tap_code16(KC_DEL);
                set_mods(mod_state);
            } else {
                tap_code16(A(KC_BSPC));
            }
        }
        return false;
    case ARROW:  // Unicode arrows -> => through Shift
        if (record->event.pressed) {
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            SEND_STRING(shift ? "=>" : "->");
            set_mods(mod_state);
        }
        return false;
    }

    if (IS_LAYER_ON(_SYM)) {
        if (record->event.pressed) {
            // Disable one-shot shift on symbol layer
            del_oneshot_mods(MOD_MASK_SHIFT);
            // Fix rolling on keys w/wo weak mod shift, e.g. +=
            clear_weak_mods();
            send_keyboard_report();
        }
    }

    return true;  // Continue default handling.
}
