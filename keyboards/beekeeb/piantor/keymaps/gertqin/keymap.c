// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

// Compile on MacOS:
// > brew tap ArmMbed/homebrew-formulae
// > brew install arm-none-eabi-gcc

#include QMK_KEYBOARD_H

enum LAYERS {
    _DEF,
    _NAV,
    _SYM,
    _EXT
};

enum CustomKeycodes {
    RESET = SAFE_RANGE,
    APP_FWD,
    APP_BWD,
    TAB_FWD,
    TAB_BWD,
    WIN_FWD,
    WIN_BWD
};

const uint16_t PROGMEM reset_combo[] = {KC_ESC, KC_ENT, COMBO_END};
combo_t key_combos[] = {
    COMBO(reset_combo, RESET),
};

#define NUM_SWAP_CMDS 3
#define SWAP_CMD_TIMEOUT 1000

struct swap_definition {
    uint16_t keycode_fwd;
    uint16_t keycode_bwd;
    uint16_t tap_key;
    uint16_t mod_key;
};

struct swap_definition swap_definitions[NUM_SWAP_CMDS] = {
    { APP_FWD, APP_BWD, KC_TAB, KC_LGUI },
    { TAB_FWD, TAB_BWD, KC_TAB, KC_LCTL },
    { WIN_FWD, WIN_BWD, KC_GRV, KC_LGUI }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_split_3x6_3(
        OSM(MOD_LGUI),  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,  KC_BSPC,
        KC_ESC,         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,     KC_ENT,
        KC_GRV,         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLS,
                                            OSM(MOD_LALT), TO(_NAV),  OSM(MOD_LSFT),        OSL(_SYM),  KC_SPC,  OSM(MOD_LCTL)
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        OSM(MOD_LGUI),  G(KC_Z),  G(KC_X),  G(KC_C),   G(KC_V),  SCMD(KC_Z),                    A(KC_LEFT),  KC_PGDN,  KC_PGUP,  A(KC_RGHT),  KC_DEL,      KC_BSPC,
        KC_ESC,         TAB_BWD,  TAB_FWD,  APP_BWD,   APP_FWD,  G(KC_LBRC),                    KC_LEFT,     KC_DOWN,  KC_UP,    KC_RGHT,     G(KC_RBRC),  KC_ENT,
        XXXXXXX,        WIN_BWD,  WIN_FWD,  S(KC_TAB), KC_TAB,   G(KC_RBRC),                    G(KC_LEFT),  KC_HOME,  KC_END,   G(KC_RGHT),  XXXXXXX,     TO(_EXT),
                                            OSM(MOD_LALT), RESET,  OSM(MOD_LSFT),           OSL(_SYM),  KC_SPC,  OSM(MOD_LCTL)
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        OSM(MOD_LGUI),  S(KC_1),     S(KC_2),  S(KC_3),     S(KC_4),     S(KC_5),                S(KC_8),    KC_7,  KC_8,  KC_9,  S(KC_7),  KC_BSPC,
        KC_ESC,         S(KC_SCLN),  KC_SCLN,  S(KC_9),     S(KC_0),     KC_LBRC,                S(KC_EQL),  KC_4,  KC_5,  KC_6,  KC_0,     KC_ENT,
        KC_GRV,         S(KC_MINS),  KC_MINS,  S(KC_LBRC),  S(KC_RBRC),  KC_RBRC,                S(KC_6),    KC_1,  KC_2,  KC_3,  KC_SLSH,  KC_BSLS,
                                            XXXXXXX, TO(_NAV),  KC_EQL,                    OSL(_SYM),  KC_SPC,  KC_DOT
    ),
    [_EXT] = LAYOUT_split_3x6_3(
        OSM(MOD_LGUI),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
        KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,  KC_ENT,
        KC_GRV,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS,  KC_SLSH,
                                            OSM(MOD_LALT), TO(_NAV),  OSM(MOD_LSFT),        OSL(_SYM),  KC_SPC,  OSM(MOD_LCTL)
    ),
};

uint8_t locked_mods = 0;

void oneshot_locked_mods_changed_user(uint8_t mods) {
    locked_mods = mods;
}

void reset_all(void) {
    clear_oneshot_mods();

    if (locked_mods & MOD_MASK_GUI) { unregister_code(KC_LGUI); }
    if (locked_mods & MOD_MASK_CTRL) { unregister_code(KC_LCTL); }
    if (locked_mods & MOD_MASK_ALT) { unregister_code(KC_LALT); }
    if (locked_mods & MOD_MASK_SHIFT) { unregister_code(KC_LSFT); }

    layer_move(_DEF);
};

bool swap_cmd_active[NUM_SWAP_CMDS] = {false};
uint16_t swap_timer = 0;

void clear_swap_cmd_active(uint16_t keycode, keyrecord_t *record) {
    for (uint16_t swap_cmd_idx = 0; swap_cmd_idx < NUM_SWAP_CMDS; ++swap_cmd_idx) {
        struct swap_definition *def = &swap_definitions[swap_cmd_idx];
        if (swap_cmd_active[swap_cmd_idx] && keycode != def->keycode_fwd && keycode != def->keycode_bwd) {
            swap_cmd_active[swap_cmd_idx]= false;
            unregister_code(def->mod_key);   
        }
    }
}

void process_swap_cmd(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        clear_swap_cmd_active(keycode, record);
    }


    for (uint16_t swap_cmd_idx = 0; swap_cmd_idx < NUM_SWAP_CMDS; ++swap_cmd_idx) {
        struct swap_definition *def = &swap_definitions[swap_cmd_idx];
        if (keycode != def->keycode_fwd && keycode != def->keycode_bwd) {
            continue;
        }

        bool is_fwd = keycode == def->keycode_fwd;

        if (record->event.pressed) {
            if (!swap_cmd_active[swap_cmd_idx]) {
                register_code(def->mod_key);   
                swap_cmd_active[swap_cmd_idx] = true;
            }
            swap_timer = timer_read();

            if (!is_fwd) {
                register_code(KC_LSFT);   
            }
            register_code(def->tap_key);   
        } else {
            unregister_code(def->tap_key);   
            if (!is_fwd) {
                unregister_code(KC_LSFT);   
            }
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_swap_cmd(keycode, record);
    
    switch (keycode) {
    case KC_ESC:
        // on esc - reset all before pressing esc
        if (record->event.pressed) {
            reset_all();
        }
        break;
    }
    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RESET:
        reset_all();
        break;
    case KC_SPC:
    case KC_ENT:
        if (!IS_LAYER_ON(_EXT)) {
            reset_all();
        }
        break;
    case KC_BSPC:
    case KC_DEL:
        // reset on all edit keys on nav layer
        if (IS_LAYER_ON(_NAV)) {
            reset_all();
        }
        break;
    }
};

void matrix_scan_user(void) {
    // clear swap state
    for (uint16_t swap_cmd_idx = 0; swap_cmd_idx < NUM_SWAP_CMDS; ++swap_cmd_idx) {
        if (swap_cmd_active[swap_cmd_idx] && timer_elapsed(swap_timer) > SWAP_CMD_TIMEOUT) {
            swap_cmd_active[swap_cmd_idx] = false;
            unregister_code(swap_definitions[swap_cmd_idx].mod_key);   
        }
    }
}

