#include "quantum.h"

// Tap Dance Declarations
enum {
    GUITD = 0,
};

tap_dance_action_t tap_dance_actions[] = {
};

enum layers {
    QWERTY,
    NAV,
    NUM,
    FN,
};

#define ___ KC_TRNS

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(                                                               //
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,                  //
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT,               //
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, //
        KC_LCTL, KC_LGUI, LALT_T(KC_SPACE), LT(NAV, KC_SPACE), MO(FN), KC_RALT      //
        ),                                                                           //

    [NUM] = LAYOUT(                                                 //
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,           //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,           //
        ___, ___, ___, ___, ___, ___                                //
        ),                                                          //

    [NAV] = LAYOUT(                                                                 //
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_EQL, KC_DEL, KC_UP, KC_BACKSPACE, //
        KC_6, KC_7, KC_8, KC_9, KC_0, ___, KC_SCLN, KC_LEFT, KC_DOWN, KC_RIGHT,     //
        ___, ___, ___, KC_LBRC, KC_RBRC, ___, ___, ___, ___, KC_BSLS,               //
        ___, ___, ___, ___, ___, ___                                                //
        ),                                                                          //

    [FN] = LAYOUT(                                                                     //
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, ___, ___, ___, KC_VOLU, KC_CAPS,            //
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MUTE, KC_VOLD, KC_MPLY, //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,                              //
        ___, ___, ___, ___, ___, ___                                                   //
        ),                                                                             //
};

//
// COMBO is everything !
//

const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM comb_quot[] = {KC_L, KC_ENTER, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_ralt[] = {KC_DOT, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo_rsft[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_rsft2[] = {KC_DOT, KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo_grav[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_grav2[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_home[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo_end[] = {KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_pgup[] = {KC_LEFT, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_pgdn[] = {KC_LEFT, KC_DOWN, KC_RIGHT, COMBO_END};
//
//
const uint16_t PROGMEM combo_rst[] = {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, COMBO_END};
//
combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC), //
    COMBO(combo_tab, KC_TAB), //
    COMBO(combo_ent, KC_ENTER),  //
    COMBO(combo_ralt, KC_RALT),  //
    COMBO(combo_rsft, KC_RSFT),  //
    COMBO(combo_rsft2, KC_RSFT), //
    COMBO(combo_grav, KC_GRV), //
    COMBO(combo_home, KC_HOME), //
    COMBO(combo_end, KC_END),   //
    COMBO(combo_pgup, KC_PGUP), //
    COMBO(combo_pgdn, KC_PGDN), //
    //
    //
    COMBO(combo_rst, QK_BOOT), //
};

void leader_start_user(void) {}

void leader_end_user(void) {}
