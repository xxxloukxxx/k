#include "quantum.h"

// Tap Dance Declarations
enum
{
    ESCTD = 0,
    GUITD,
};

tap_dance_action_t tap_dance_actions[] = {
    [ESCTD] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [GUITD] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_P))
};

enum layers
{
    QWERTY,
    NAV,
    FN,
    SYM,
    NUM,
};

#define ___ KC_TRNS

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_TAB, KC_N, KC_M, KC_SLSH, KC_RSFT,
        KC_LCTL, TD(GUITD), LT(SYM, KC_SPACE), LT(NAV, KC_SPACE), MO(FN), MO(NUM)),

    [NAV] = LAYOUT(
        //        KC_1, KC_2, KC_3, KC_4, KC_5, KC_END, KC_PGUP, KC_DEL, KC_UP, KC_BS,
        //        KC_6, KC_7, KC_8, KC_9, KC_0, KC_HOME, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,
        //        ___, KC_MINS, KC_EQL, KC_COMM, KC_DOT,___,___, ___,___, ___,
        //        ___, ___, ___, ___, ___, ___),
        KC_GRV, KC_QUOT, LSFT(KC_6), ___, ___ /**/ , KC_HOME, KC_PGUP, KC_DEL, KC_UP, KC_BACKSPACE,
        ___, ___, ___, ___, ___               /**/ , KC_END, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,
        ___, ___, ___, ___, ___               /**/ , ___, KC_COMM, KC_DOT, KC_SCLN, ___,
        ___, ___, ___                        /**/  , ___, ___, ___),

    [FN] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, ___, ___, ___, ___, KC_F11, KC_F12,
        ___, KC_PSCR, KC_SCRL, KC_PAUS, ___, ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___),

    [NUM] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___),

    [SYM] = LAYOUT(
        LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),
        ___,___,  ___, ___, KC_BSLS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,
        ___, ___, ___, ___, ___, ___, KC_COMM, KC_DOT, KC_SCLN, KC_QUOT,
        ___, ___, ___, ___, ___, ___)

};

const uint16_t PROGMEM comb_alt1[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM comb_alt2[] = {KC_M, KC_SLSH, COMBO_END};
const uint16_t PROGMEM comb_tab[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM comb_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM comb_bs[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM comb_del[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM comb_ert[] = {KC_T, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM comb_cvb[] = {KC_B, KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
    COMBO(comb_alt1, KC_LALT),
    COMBO(comb_alt2, KC_LALT),
    COMBO(comb_esc, KC_ESC),
    COMBO(comb_tab, KC_TAB),
    COMBO(comb_bs, KC_BACKSPACE),
    COMBO(comb_del, KC_DEL),
    COMBO(comb_ert, LGUI(LSFT(KC_ENTER))),
//    COMBO(comb_cvb, LGUI(KC_ENTER)),
};

void leader_start_user(void)
{
    // Do something when the leader key is pressed
}

void leader_end_user(void)
{
    if (leader_sequence_one_key(KC_ESC))
    {
        tap_code16(KC_MUTE);
    }
    else if (leader_sequence_one_key(KC_S))
    {
        SEND_STRING(SS_LCTL("s"));
    }
    else if (leader_sequence_one_key(KC_Q))
    {
        SEND_STRING(SS_LCTL("q"));
    }
    else if (leader_sequence_one_key(KC_W))
    {
        SEND_STRING(SS_LCTL("w"));
    }
    else if (leader_sequence_one_key(KC_D))
    {
        SEND_STRING(SS_LCTL("d"));
    }
}
