/*
3 * (6+6) + 9 = 45
*/

#define ___ KC_TRNS

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_SLSH,
        KC_LCTL, MO(2), KC_LALT, KC_LGUI, KC_SPACE, MO(1), KC_LEFT, KC_DOWN, KC_RIGHT),
    // FOR TEST fn1 et fn2
    //        KC_LCTL, KC_LGUI, KC_LALT, KC_F10  , KC_SPACE, KC_F9, KC_LEFT, KC_DOWN, KC_RIGHT),

    //    [1] = LAYOUT(
    //        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
    //        KC_CAPS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , ___, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
    //        ___, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , ___, ___, KC_PGUP, KC_SCLN,
    //        ___, ___, ___, ___, ___, ___,                            KC_HOME, KC_PGDN, KC_END),

    [1] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        KC_CAPS, ___, ___, ___, ___, ___, ___, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, KC_PGUP, KC_SCLN,
        ___, ___, ___, ___, ___, ___, KC_HOME, KC_PGDN, KC_END),

    [2] = LAYOUT(
        KC_F13, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_INS,
        KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MSTP, ___, ___, ___, KC_F11, KC_F12, KC_F13,
        ___, KC_PSCR, KC_SCRL, KC_PAUS, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, ___, ___, ___, KC_F14, ___, ___, ___, ___),

    [3] = LAYOUT(
        TO(0), KC_7, KC_8, KC_9, KC_PSLS, KC_PAST, ___, ___, ___, ___, ___, ___,
        ___, KC_4, KC_5, KC_6, KC_PMNS, KC_PPLS, ___, ___, ___, ___, ___, ___,
        ___, KC_1, KC_2, KC_3, KC_DOT, KC_NO, ___, ___, ___, ___, ___, ___,
        ___, ___, KC_0, KC_ENT, ___, ___, ___, ___, ___),

};

const uint16_t PROGMEM test_combo1[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_F13[] = {KC_ESC, KC_Q, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_LBRC),
    COMBO(test_combo2, KC_LPRN),
    COMBO(test_combo3, KC_RPRN),
    COMBO(test_combo4, KC_RBRC),
    COMBO(combo_F13, KC_F13),
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
