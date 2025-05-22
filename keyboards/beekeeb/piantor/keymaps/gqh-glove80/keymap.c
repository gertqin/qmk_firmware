// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// Compile on MacOS:
// > brew tap ArmMbed/homebrew-formulae
// > brew install arm-none-eabi-gcc

#include QMK_KEYBOARD_H

#define REP_KEY_TIMEOUT 500
#define SMART_CASE_TIMEOUT 5000

#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)

#define LT_SYM_ESC LT(_SYM, KC_ESC)
#define OSL_SYM OSL(_SYM)
#define LT_NAV_ENT LT(_NAV, KC_ENT)
#define LT_FN_TAB LT(_FN, KC_TAB)

#define GUI_ESC LGUI_T(KC_ESC)
#define CTL_GRV LCTL_T(KC_GRV)
#define ALT_TAB LALT_T(KC_TAB)

enum LAYERS {
    _MAIN,
    _DAN,
    _FN,
    _NAV,
    _SYM,
};

enum CustomKeycodes {
    SC_NORM = SAFE_RANGE,
    SC_SNAK,
    SC_CAME,
    SC_UPPE
};

enum SmartCase {
    CASE_NORMAL,
    CASE_SNAKE,
    CASE_CAMEL,
    CASE_UPPER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        LT_FN_TAB, KC_B,   KC_F,   KC_L,   KC_K,     KC_Q,                                   KC_QUOT,  KC_P,   KC_O,     KC_U,     KC_SCLN,  KC_MINS,
        OSL_SYM,   KC_N,   KC_S,   KC_H,   KC_T,     KC_M,                                   KC_Y,     KC_C,   KC_A,     KC_E,     KC_I,     A(KC_BSPC),
        CTL_GRV,   KC_X,   KC_V,   KC_J,   KC_D,     KC_Z,                                   KC_G,     KC_W,   KC_DOT,   KC_DQUO,  KC_COMM,  KC_SLSH,
                                              GUI_ESC,  KC_R,  OSM_LSFT,           LT_NAV_ENT,  KC_SPC,  ALT_TAB
    ),
    [_DAN] = LAYOUT_split_3x6_3(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     A(KC_A),  A(KC_O),
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                             KC_TRNS,  KC_TRNS,  KC_TRNS,  A(KC_QUOT),  KC_TRNS,  KC_TRNS,
                                              KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_FN] = LAYOUT_split_3x6_3(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                               KC_F7,    KC_F8,     KC_F9,    KC_F10,   KC_F11,   KC_F12, 
        XXXXXXX,  SC_UPPE,  SC_CAME,  SC_SNAK,  SC_NORM,  XXXXXXX,                             XXXXXXX,  TO(_DAN),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                             XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                              KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_TRNS,   KC_COMM,  KC_6,   KC_5,   KC_4,   KC_PLUS,                                 KC_LCBR,  KC_LBRC,   KC_LPRN,  KC_RPRN,  KC_RBRC,   KC_RCBR,
        KC_TRNS,   KC_DOT,   KC_3,   KC_2,   KC_1,   KC_0,                                    KC_LEFT,  KC_DOWN,   KC_UP,    KC_RIGHT, KC_DEL,    KC_BSPC,
        KC_TRNS,   KC_LALT,  KC_9,   KC_8,   KC_7,   KC_MINS,                                 KC_ASTR,  KC_EQL,    KC_LT,    KC_GT,    KC_QUES,   KC_SLSH,
                                              KC_TRNS,  S(KC_R), KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TRNS,  XXXXXXX,  KC_CIRC,  KC_PERC,  KC_DLR,   KC_PLUS,                            KC_LCBR,  KC_LBRC,   KC_LPRN,  KC_RPRN,   KC_RBRC,   KC_RCBR,
        KC_TRNS,  XXXXXXX,  KC_HASH,  KC_AT,    KC_EXLM,  KC_PIPE,                            KC_SCLN,  KC_COLN,   KC_UNDS,  KC_GRV,    KC_DEL,    KC_BSPC,
        KC_TRNS,  XXXXXXX,  KC_BSLS,  KC_ASTR,  KC_AMPR,  KC_MINS,                            KC_ASTR,  KC_EQL,    KC_LT,    KC_GT,     KC_QUES,   KC_SLSH,
                                              KC_TRNS,  S(KC_R), KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
};

const key_override_t bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t alt_bspc_key_override = ko_make_basic(MOD_MASK_GUI, A(KC_BSPC), G(KC_BSPC));

const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t slsh_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);

const key_override_t cmd_j_key_override = ko_make_basic(MOD_MASK_GUI, KC_J, G(KC_C));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&bspc_key_override,
	&alt_bspc_key_override,
	&dot_key_override,
	&comma_key_override,
	&slsh_key_override,
	&cmd_j_key_override
};

enum SmartCase smart_case = CASE_NORMAL;

uint16_t keypress_timer = 0;


layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == _DAN) {
        smart_case = CASE_NORMAL;
    }
    return state;
}

bool is_char(uint16_t keycode) {
    return keycode >= KC_A && keycode <= KC_Z;
}

bool is_number(uint16_t keycode) {
    return keycode >= KC_1 && keycode <= KC_0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        keypress_timer = timer_read();
    }

    // Repeat key
    if (get_repeat_key_count() > 0) {
        switch (keycode) {
            case KC_UP:
            case KC_DOWN:
            case KC_LEFT:
            case KC_RIGHT:
            case KC_SPC:
            case KC_QUOT:
            case KC_DQUO:
            case KC_MINS:
            case KC_BSPC:
            case A(KC_BSPC):
            case LT_NAV_ENT: {
                // Repeat key after space, set one-shot shift
                if (record->event.pressed) {
                    register_mods(MOD_BIT(KC_LSFT));    
                    set_oneshot_mods(MOD_BIT(KC_LSFT));    
                } else {
                    unregister_mods(MOD_BIT(KC_LSFT));    
                }
                return false;
            }
            // case ALT_COLN:
            //     if (record->event.pressed) {
            //         tap_code16(KC_COLN);
            //         return false;
            //     }
        }
        return true;
    }

    // Handle smart case enabled
    if (smart_case != CASE_NORMAL) {
        switch (keycode) {
            case KC_SPC:
                switch (smart_case) {
                    case CASE_NORMAL:
                        break;
                    case CASE_SNAKE:
                    case CASE_UPPER:
                        if (record->event.pressed) {
                            tap_code16(KC_UNDS);
                        }
                        return false;
                    case CASE_CAMEL:
                        if (record->event.pressed) {
                            register_mods(MOD_BIT(KC_LSFT));    
                            set_oneshot_mods(MOD_BIT(KC_LSFT));    
                        } else {
                            unregister_mods(MOD_BIT(KC_LSFT));    
                        }
                        return false;
                }
                break;
            // case LT_SYM_ESC:
            case LT_NAV_ENT:
                if (record->tap.count && record->event.pressed) {
                    smart_case = CASE_NORMAL;
                    return keycode == LT_NAV_ENT; // Exit smart case without pressing esc
                }
                break;
        }

        if (record->event.pressed) {
            if (smart_case == CASE_UPPER && is_char(keycode) && !get_mods()) {
                tap_code16(S(keycode));
                return false;
            }

            if (!is_char(keycode) && !is_number(keycode) &&
                keycode != KC_MINS &&
                keycode != KC_BSPC &&
                keycode != A(KC_BSPC) &&
                // keycode != LT_SYM_ESC &&
                keycode != LT_NAV_ENT) {
                // Only keep smart case on for chars, numbers, '-' and bspc
                smart_case = CASE_NORMAL;
            }
        }
    }

    // Smart case keys
    switch (keycode) {
        case SC_NORM:
            if (record->event.pressed) {
                layer_clear();
                smart_case = CASE_NORMAL;
            }
            return false;
        case SC_SNAK:
            if (record->event.pressed) {
                layer_clear();
                smart_case = CASE_SNAKE;
                tap_code16(KC_UNDS);
            }
            return false;
        case SC_CAME:
            if (record->event.pressed) {
                layer_clear();
                smart_case = CASE_CAMEL;
                set_oneshot_mods(MOD_BIT(KC_LSFT));    
            }
            return false;
        case SC_UPPE:
            if (record->event.pressed) {
                layer_clear();
                smart_case = CASE_UPPER;
            }
            return false;
    }

    // LT keys
    // switch (keycode) {
    //     case ALT_COLN:
    //         if (record->tap.count && record->event.pressed) {
    //             tap_code16(KC_COLN);
    //             return false;
    //         }
    //         break;
    // }

    return true;
}

void matrix_scan_user(void) {
    if (timer_elapsed(keypress_timer) > REP_KEY_TIMEOUT) {
        set_last_keycode(KC_SPC);
    }

    if (timer_elapsed(keypress_timer) > SMART_CASE_TIMEOUT) {
        smart_case = CASE_NORMAL;
    }
}

