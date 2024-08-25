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
    FN1,
    NAV,
    FN2,
};

#define ___ KC_TRNS

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT,
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMMA, RSFT_T(KC_DOT),
        KC_LCTL, KC_LGUI, KC_SPACE, LT(NAV, KC_ENTER), MO(FN1), KC_LALT),

    [FN1] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_TAB, ___, ___, ___, ___, ___, KC_MINS, KC_EQL, KC_BSLS, KC_SCLN,
        ___, ___, ___, ___, ___, ___, KC_LBRC, KC_RBRC, KC_SLSH, ___,
        ___, ___, ___, MO(FN2), ___, ___),

    [NAV] = LAYOUT(
       KC_HOME, KC_UP, KC_END, KC_PGUP, ___, ___, KC_PGUP, KC_HOME, KC_UP, KC_END,
       KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, ___, ___, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,
       KC_CAPS, ___, ___, ___, ___, ___,___, ___, ___, KC_ENT,
       ___, ___, ___, ___, ___, ___),

    [FN2] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        ___, KC_MUTE, KC_VOLD, KC_VOLU, ___, ___, ___, ___, KC_F11, KC_F12,
        ___, KC_PSCR, KC_SCRL, KC_PAUS, ___, ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___),

};

const uint16_t PROGMEM comb_tab[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM comb_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM comb_bs[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM comb_del[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM comb_term[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM comb_app[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM comb_reset[] = {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, COMBO_END};

combo_t key_combos[] = {
    COMBO(comb_esc, KC_ESC),
    COMBO(comb_tab, KC_TAB),
    COMBO(comb_bs, KC_BACKSPACE),
    COMBO(comb_del, KC_DEL),
    COMBO(comb_term, LSFT(LGUI(KC_ENT))),
    COMBO(comb_app, LGUI(KC_P)),
    COMBO(comb_reset, QK_BOOT),
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
