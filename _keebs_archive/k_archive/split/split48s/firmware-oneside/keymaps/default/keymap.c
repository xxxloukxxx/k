#include "quantum.h"

enum layers {
    BASE,
    NAV,
    FNC,
};

#define _______ KC_TRNS
#define ______ KC_TRNS
#define _____ KC_TRNS
#define ____ KC_TRNS
#define ___ KC_TRNS
#define KC_LFT KC_LEFT
#define KC_RGT KC_RIGHT
#define KC_DN KC_DOWN
#define KC_HOM KC_HOME
#define KC_BSP KC_BACKSPACE
#define KC_NUML KC_NUM

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(                                    //
        KC_NUML, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_BSP,  //
        _______, KC_P4, KC_P5, KC_P6, KC_PAST, KC_DEL,  //
        MO(FNC), KC_P1, KC_P2, KC_P3, KC_PMNS, ______,  //
        MO(NAV), _____, KC_P0, KC_PDOT, KC_PPLS, KC_ENT //
        ),                                              //

    [NAV] = LAYOUT(                            //
        ____, ______, _____, ______, ___, ___, //
        ____, KC_HOM, KC_UP, KC_END, ___, ___, //
        ____, KC_LFT, KC_DN, KC_RGT, ___, ___, //
        ____, ______, _____, ______, ___, ___  //
        ),                                     //

    [FNC] = LAYOUT(                   //
        ___, ___, ___, ___, ___, ___, //
        ___, ___, ___, ___, ___, ___, //
        ___, ___, ___, ___, ___, ___, //
        ___, ___, ___, ___, ___, ___  //
        ),                            //
};

const uint16_t PROGMEM combo_esc[] = { KC_PPLS, KC_ENTER, COMBO_END };
const uint16_t PROGMEM combo_pgup1[] = { KC_LEFT, KC_RIGHT, KC_UP, COMBO_END };
const uint16_t PROGMEM combo_pgup2[] = { KC_HOM, KC_END, KC_UP, COMBO_END };
const uint16_t PROGMEM combo_pgdn[] = { KC_LEFT, KC_RIGHT, KC_DOWN, COMBO_END };
const uint16_t PROGMEM combo_rst[] = { KC_P7, KC_P8, KC_P9, KC_PSLS, KC_BACKSPACE, COMBO_END };
//
combo_t key_combos[] = {
    COMBO(combo_pgup1, KC_PGUP), //
    COMBO(combo_pgup2, KC_PGUP), //
    COMBO(combo_pgdn, KC_PGDN),  //
    COMBO(combo_esc, KC_ESC),    //
    COMBO(combo_rst, QK_BOOT),   //
};
