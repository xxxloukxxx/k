/*
3 *(5+5) + 8 = 38
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SLSH,
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_ENT,
        KC_LSFT, KC_LCTL, KC_LGUI, KC_SPC, MO(1), MO(2), KC_ESC, KC_TAB),
    [1] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_MINS, KC_EQL, KC_SCLN, KC_QUOT, KC_BSLS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_LBRC, KC_RBRC, KC_F13, KC_UP, KC_RIGHT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_F14, KC_TRNS, KC_LALT, KC_LEFT, KC_DOWN),

    [2] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_F13, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_F12,
        KC_MUTE, KC_VOLU, KC_VOLD, KC_MSTP, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_PGDN)};

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
