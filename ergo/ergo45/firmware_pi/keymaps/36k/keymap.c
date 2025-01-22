/*
3 * (6+6) + 9 = 45
*/

#include "quantum.h"

enum layers { QWERTY,
    NAV,
    FN };

// Tap Dance Declarations
enum {
    TD_GUI = 0,
};

tap_dance_action_t tap_dance_actions[] = {
    /* [TD_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_P)), */
};

#define ___ KC_TRNS
#define XXX KC_NO
#define KC_BSPC KC_BACKSPACE

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(                                                                         //
        XXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, XXX,                  //
        XXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, XXX,               //
        XXX, LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, XXX, //
        XXX, KC_LCTL, KC_LALT, KC_LGUI, KC_SPACE, MO(NAV), MO(FN), KC_RSFT, XXX                //
        ),                                                                                     //

    [NAV] = LAYOUT(                                                                       //
        XXX, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_EQL, KC_DEL, KC_UP, KC_BSPC, XXX,  //
        XXX, KC_6, KC_7, KC_8, KC_9, KC_0, ___, KC_SCLN, KC_LEFT, KC_DOWN, KC_RIGHT, XXX, //
        XXX, ___, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, ___, ___, ___, ___, KC_BSLS, XXX,   //
        XXX, ___, ___, ___, ___, ___, ___, ___, XXX                                       //
        ),                                                                                //

    [FN] = LAYOUT(                                                                   //
        XXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, ___, ___, ___, ___, KC_CAPS, XXX,    //
        XXX, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ___, ___, ___, XXX, //
        XXX, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, XXX,                  //
        XXX, ___, ___, ___, ___, ___, ___, ___, XXX                                  //
        ),
};

// COMBO is everything !(mais pas tout quand même)

const uint16_t PROGMEM combo_esc[] = { KC_Q, KC_W, COMBO_END };
const uint16_t PROGMEM combo_tab[] = { KC_S, KC_D, COMBO_END };
const uint16_t PROGMEM combo_tab2[] = { KC_A, KC_S, KC_D, COMBO_END };
const uint16_t PROGMEM combo_ent[] = { KC_L, KC_QUOT, COMBO_END };
const uint16_t PROGMEM combo_ralt[] = { KC_DOT, KC_COMMA, COMBO_END };
const uint16_t PROGMEM combo_grav[] = { KC_W, KC_E, COMBO_END };
const uint16_t PROGMEM combo_circonflexe[] = { KC_Q, KC_W, KC_E, COMBO_END };
const uint16_t PROGMEM combo_home[] = { KC_LEFT, KC_DOWN, COMBO_END };
const uint16_t PROGMEM combo_end[] = { KC_DOWN, KC_RIGHT, COMBO_END };
const uint16_t PROGMEM combo_pgup[] = { KC_DEL, KC_BSPC, KC_UP, COMBO_END };
const uint16_t PROGMEM combo_pgdn[] = { KC_LEFT, KC_DOWN, KC_RIGHT, COMBO_END };
const uint16_t PROGMEM combo_rst[] = { KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, COMBO_END };
//
combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC),             //
    COMBO(combo_tab, KC_TAB),             //
    COMBO(combo_tab2, KC_TAB),            //
    COMBO(combo_ent, KC_ENTER),           //
    COMBO(combo_ralt, KC_RALT),           //
    COMBO(combo_grav, KC_GRV),            //
    COMBO(combo_circonflexe, LSFT(KC_6)), //
    COMBO(combo_home, KC_HOME),           //
    COMBO(combo_end, KC_END),             //
    COMBO(combo_pgup, KC_PGUP),           //
    COMBO(combo_pgdn, KC_PGDN),           //
    COMBO(combo_rst, QK_BOOT)             //
};
