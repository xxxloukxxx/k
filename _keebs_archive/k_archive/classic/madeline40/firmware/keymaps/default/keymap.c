#include "quantum.h"

enum layers {
    QWERTY,
    NAV,
    FN,
};

#define _____ KC_TRNS

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(                                                                        //
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,                  //
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENTER,                       //
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, KC_QUOT, //
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPACE, LT(NAV, KC_SPACE), KC_RALT, KC_RSFT, MO(FN)      //
        ),                                                                                    //

    [NAV] = LAYOUT(                                                                        //
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_EQL, KC_HOME, KC_UP, KC_END, KC_DEL,     //
        KC_6, KC_7, KC_8, KC_9, KC_0, _____, KC_SCLN, KC_LEFT, KC_DOWN, KC_RIGHT,          //
        _____, _____, _____, KC_LBRC, KC_RBRC, _____, _____, _____, _____, KC_BSLS, _____, //
        _____, _____, _____, _____, _____, _____, _____, _____                             //
        ),                                                                                 //

    [FN] = LAYOUT(                                                                           //
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_MUTE,      //
        KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, _____, _____, KC_VOLD, KC_VOLU, _____,       //
        _____, _____, _____, _____, _____, _____, KC_PSCR, KC_SCRL, KC_PAUS, KC_CAPS, _____, //
        _____, _____, _____, _____, _____, _____, _____, _____                               //
        ),                                                                                   //
};

const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_tab2[] = {KC_A, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_grav[] = {KC_W, KC_E, COMBO_END};
/* const uint16_t PROGMEM combo_home[] = {KC_LEFT, KC_DOWN, COMBO_END}; */
/* const uint16_t PROGMEM combo_end[] = {KC_DOWN, KC_RIGHT, COMBO_END}; */
const uint16_t PROGMEM combo_pgup[] = {KC_HOME, KC_UP, KC_END, COMBO_END};
const uint16_t PROGMEM combo_pgup2[] = {KC_LEFT, KC_UP, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_pgdn[] = {KC_LEFT, KC_DOWN, KC_RIGHT, COMBO_END};
//
//
const uint16_t PROGMEM combo_rst[] = {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, COMBO_END};
//
combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),  //
    COMBO(combo_tab, KC_TAB),  //
    COMBO(combo_tab2, KC_TAB), //
    COMBO(combo_grav, KC_GRV), //
    /* COMBO(combo_home, KC_HOME),  // */
    /* COMBO(combo_end, KC_END),    // */
    COMBO(combo_pgup, KC_PGUP),  //
    COMBO(combo_pgup2, KC_PGUP), //
    COMBO(combo_pgdn, KC_PGDN),  //
    //
    //
    COMBO(combo_rst, QK_BOOT), //
};
