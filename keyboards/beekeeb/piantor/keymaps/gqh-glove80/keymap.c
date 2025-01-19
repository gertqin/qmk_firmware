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
    _NAV,
    _SYM,
};

#define LT_SYM_ESC LT(_SYM, KC_ESC)
#define LT_NAV_ENT LT(_NAV, KC_ENT)

#define CTL_GRV LCTL_T(KC_GRV)
#define CTL_QUES LCTL_T(KC_QUES)
#define GUI_TAB LGUI_T(KC_TAB)
#define ALT_UNDS LALT_T(KC_UNDS)
#define ALT_BSLS LALT_T(KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_split_3x6_3(
        KC_SCLN,     KC_B,   KC_F,   KC_L,   KC_D,     KC_V,                                   KC_QUOT,  KC_P,   KC_O,     KC_U,      KC_MINS,   KC_COLN,
        LT_SYM_ESC,  KC_N,   KC_S,   KC_R,   KC_T,     KC_M,                                   KC_Y,     KC_C,   KC_A,     KC_I,      KC_E,      A(KC_BSPC),
        CTL_QUES,    KC_Q,   KC_Z,   KC_X,   KC_K,     KC_J,                                   KC_G,     KC_W,   KC_DOT,   KC_COMM,   KC_DQUO,   CTL_GRV,
                                              GUI_TAB,  KC_H,  QK_REP,            LT_NAV_ENT,  KC_SPC,  ALT_UNDS
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_SCLN,   KC_DOT,   KC_6,   KC_5,   KC_4,   KC_PLUS,                                 KC_BSLS,  KC_LCBR,   KC_LBRC,  KC_RBRC,  KC_RCBR,   KC_COLN,
        KC_LSFT,   KC_LALT,  KC_3,   KC_2,   KC_1,   KC_0,                                    KC_AMPR,  KC_LEFT,   KC_DOWN,  KC_UP,    KC_RIGHT,  KC_BSPC,
        KC_LCTL,   KC_COMM,  KC_9,   KC_8,   KC_7,   KC_MINS,                                 KC_ASTR,  KC_EQL,    KC_LT,    KC_GT,    KC_SLSH,   KC_GRV,
                                              KC_TRNS,  S(KC_H), KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_F12,    KC_F12,   KC_CIRC,  KC_PERC,  KC_DLR,   KC_PLUS,                           KC_PIPE,  KC_LCBR,   KC_LBRC,  KC_RBRC,  KC_RCBR,   KC_COLN,
        KC_TRNS,   XXXXXXX,  KC_HASH,  KC_AT,    KC_EXLM,  KC_QUES,                           KC_AMPR,  KC_SCLN,   KC_LPRN,  KC_RPRN,  KC_DQUO,   KC_BSPC,
        KC_TRNS,   XXXXXXX,  KC_BSLS,  KC_ASTR,  KC_AMPR,  KC_MINS,                           KC_ASTR,  KC_EQL,    KC_LT,    KC_GT,    KC_SLSH,   KC_TILD,
                                              KC_TRNS,  S(KC_H), KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
};

// const uint16_t PROGMEMlcbr_combo[] = {KC_LBRC, KC_LPRN, COMBO_END};
// const uint16_t PROGMEM rcbr_combo[] = {KC_RPRN, KC_RBRC, COMBO_END};
combo_t key_combos[] = {
//     COMBO(lcbr_combo, KC_LCBR),
//     COMBO(rcbr_combo, KC_RCBR),
};

const key_override_t bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t alt_bspc_key_override = ko_make_basic(MOD_MASK_GUI, A(KC_BSPC), G(KC_BSPC));
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_GRV);

const key_override_t alt_i_key_override = ko_make_basic(MOD_MASK_ALT, KC_I, A(KC_QUOT));

const key_override_t cmd_j_key_override = ko_make_basic(MOD_MASK_GUI, KC_J, G(KC_C));
const key_override_t cmd_m_key_override = ko_make_basic(MOD_MASK_GUI, KC_M, G(KC_TAB));


// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&bspc_key_override,
	&alt_bspc_key_override,
	&dot_key_override,
	&comma_key_override,
	&quot_key_override,
	&alt_i_key_override,
	&cmd_j_key_override,
	&cmd_m_key_override
};

#define REP_KEY_TIMEOUT 500

uint16_t keypress_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        keypress_timer = timer_read();
    }

    if (get_repeat_key_count() > 0) {
        switch (keycode) {
            case KC_SPC:
            case KC_QUOT:
            case KC_DQUO:
            case KC_BSPC:
            case A(KC_BSPC):
            case CTL_QUES:
            case LT_NAV_ENT: {
                if (get_repeat_key_count() > 1 && timer_elapsed(keypress_timer) < TAPPING_TERM) {
                    // Double repeat key after space, set caps word
                    if (record->event.pressed) {
                        clear_mods();
                        clear_oneshot_mods();
                        caps_word_on();
                    }
                    return false;
                } else {
                    // Repeat key after space, set one-shot shift
                    if (record->event.pressed) {
                        register_mods(MOD_BIT(KC_LSFT));    
                        set_oneshot_mods(MOD_BIT(KC_LSFT));    
                    } else {
                        unregister_mods(MOD_BIT(KC_LSFT));    
                    }
                    return false;
                }
            }
        }
        return true;
    }

    switch (keycode) {
        case CTL_QUES:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUES);
                return false;
            }
            break;
        case ALT_UNDS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
    }

    return true;
}

void matrix_scan_user(void) {
    if (timer_elapsed(keypress_timer) > REP_KEY_TIMEOUT) {
        set_last_keycode(KC_SPC);
    }
}

