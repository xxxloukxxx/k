/*
3 * (6+6) + 9 = 45
*/

enum layers
{
    QWERTY,
    NAV,
    FN1,
    FN2,
};

#define ___ KC_TRNS

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT,
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, RSFT_T(KC_DOT),
        KC_LCTL, KC_LGUI, KC_SPACE, LT(NAV, KC_ENTER), MO(FN1), KC_RALT),
    [NAV] = LAYOUT(
        KC_HOME, KC_UP, KC_END, KC_PGUP, ___, ___, KC_PGUP, KC_HOME, KC_UP, KC_END,
        KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, ___, ___, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,
        KC_CAPS, ___, ___, ___, ___, ___, ___, ___, ___, KC_ENT,
        ___, ___, ___, ___, ___, ___),
    [FN1] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_TAB, ___, ___, ___, ___, ___, KC_MINS, KC_EQL, KC_BSLS, KC_SCLN,
        ___, ___, ___, ___, ___, ___, ___, KC_LBRC, KC_RBRC, KC_SLSH,
        ___, ___, ___, MO(FN2), ___, ___),

    [FN2] = LAYOUT(
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, ___, ___, ___, ___, ___,
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ___, ___, ___,
        ___, ___, ___, ___, ___, ___)};

const uint16_t PROGMEM test_combo1[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {KC_L, KC_QUOT, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_ESC),
    COMBO(test_combo2, KC_TAB),       // keycodes with modifiers are possible too!
    COMBO(test_combo3, KC_BACKSPACE), // keycodes with modifiers are possible too!
    COMBO(test_combo4, KC_DEL),       // keycodes with modifiers are possible too!
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
