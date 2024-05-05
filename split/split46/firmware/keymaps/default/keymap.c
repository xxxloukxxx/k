#include QMK_KEYBOARD_H

#include "quantum.h"

// Tap Dance Declarations
enum
{
    TD_GUI = 0,
    TD_TERM
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_P)),
};

#define ______ KC_TRNS
#define MTGUI MT(MOD_LGUI, KC_SPACE)

enum
{
    QWERTY = 0,
    NAV,
    NUM,
    NUMPAD,
    SYM,
    FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, /* ----- */ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, /* ----- */ KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, /* ----- */ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, TD(TD_GUI), MO(SYM), MTGUI, /* ----- */ LT(NAV, KC_SPACE), MO(NUM), MO(FN), KC_RALT, KC_RCTL),

    [NAV] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, /* ----- */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        KC_CAPS, ______, ______, ______, ______, ______, /* ----- */ KC_HOME, KC_MINS, KC_EQL, KC_UP, KC_SCLN, KC_BSLS,
        ______, ______, ______, ______, ______, ______, /* ----- */ KC_END, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,
        ______, ______, ______, ______, ______, /* ----- */ ______, ______, ______, ______, ______),

    [NUM] = LAYOUT(
        ______, KC_1, KC_2, KC_3, KC_4, KC_5, /* ----- */ KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        ______, ______, ______, ______, ______, ______, /* ----- */ ______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, ______,
        ______, ______, ______, ______, ______, ______, /* ----- */ ______, ______, ______, ______, ______, ______,
        ______, ______, ______, ______, ______, /* ----- */ ______, ______, ______, ______, ______),

    [FN] = LAYOUT(
        ______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /* ----- */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, TO(NUMPAD),
        KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MSTP, /* ----- */ ______, ______, ______, KC_F11, KC_F12, ______,
        ______, KC_PSCR, KC_SCRL, KC_PAUS, ______, ______, /* ----- */ ______, ______, ______, ______, ______, ______,
        ______, ______, ______, ______, ______, /* ----- */ ______, ______, ______, ______, ______),

    [SYM] = LAYOUT(
        ______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), /* ----- */ LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), ______,
        ______, ______, ______, ______, ______, ______, /* ----- */ ______, ______, ______, ______, ______, ______,
        ______, ______, ______, ______, ______, ______, /* ----- */ ______, ______, ______, ______, ______, ______,
        ______, ______, ______, ______, ______, /* ----- */ ______, ______, ______, ______, ______),
    [NUMPAD] = LAYOUT(
        TO(QWERTY), ______, ______, ______, ______, ______, /* ----- */ KC_7, KC_8, KC_9, KC_PSLS, KC_PAST, ______,
        ______, ______, ______, ______, ______, ______, /* ----- */ KC_4, KC_5, KC_6, KC_PMNS, KC_PPLS, ______,
        ______, ______, ______, ______, ______, ______, /* ----- */ KC_1, KC_2, KC_3, ______, ______, ______,
        ______, ______, ______, ______, ______, /* ----- */ KC_ENT, KC_0, KC_DOT, ______, ______),

};

const uint16_t PROGMEM home_combo[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM end_combo[] = {KC_RIGHT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM term_combo[] = {KC_ESC, KC_Q, KC_W, COMBO_END};
combo_t key_combos[] = {
    COMBO(home_combo, KC_HOME),
    COMBO(end_combo, KC_END),
    COMBO(term_combo, LGUI(LSFT(KC_ENTER))),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
