/*
https://github.com/manna-harbour/miryoku/tree/master/docs/reference
*/

enum layers
{
    BASE,
    NAV,
    NUM,
    SYM,
    FUN,
    MEDIA,
};

#define ___ KC_NO

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,                                                                    //
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_QUOT), //
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,                                                            //
        LT(MEDIA, KC_ESC), KC_TAB, LT(NAV, KC_SPC), LT(SYM, KC_ENTER), LT(NUM, KC_BSPC), LT(FUN, KC_DEL)),                             //

    [NAV] = LAYOUT(
        ___, ___, ___, ___, ___, KC_AGAIN, KC_PASTE, KC_COPY, KC_CUT, KC_UNDO,               //
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ___, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, //
        ___, ___, ___, ___, ___, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,                  //
        ___, KC_TRNS, ___, KC_ENT, KC_BSPC, KC_DEL),                                         //

    [MEDIA] = LAYOUT(
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,                                 //
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, ___, ___, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,                                 //
        KC_TRNS, ___, ___, KC_MSTP, KC_MPLY, KC_MUTE),                                    //

    [NUM] = LAYOUT(
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, ___, ___, ___, ___, ___,                //
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, ___, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, //
        KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, ___, ___, ___, ___, ___,                 //
        KC_DOT, KC_0, KC_MINS, ___, KC_TRNS, ___),

    [SYM] = LAYOUT(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, ___, ___, ___, ___, ___,                //
        KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, ___, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, //
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, ___, ___, ___, ___, ___,                  //
        KC_LPRN, KC_RPRN, KC_UNDS, KC_TRNS, ___, ___),                                       //

    [FUN] = LAYOUT(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, ___, ___, ___, ___, ___,                 //
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL, ___, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, //
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, ___, ___, ___, ___, ___,                 //
        KC_APP, KC_SPC, KC_TAB, ___, ___, KC_TRNS)};

const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_bsp[] = {KC_O, KC_I, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_del, KC_DEL),
    COMBO(combo_bsp, KC_BACKSPACE),
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
