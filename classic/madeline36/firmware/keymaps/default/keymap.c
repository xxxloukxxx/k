#include "quantum.h"

enum layers { _BASE,
    _RAISE,
    _LOWER,
    _FN };

#define ___ KC_TRNS

#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_SPC)
#define FN LT(_FN, KC_ENT)
#define _S(x) LSFT_T(x)
#define _C(x) LCTL_T(x)
#define _A(x) LALT_T(x)
#define _G(x) LGUI_T(x)

#define KC_BSPC KC_BACKSPACE
#define KC_LFT KC_LEFT
#define KC_RGT KC_RIGHT
#define KC_DN KC_DOWN

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(                                                                                             //
        /*              */ KC_Q, KC_W, KC_E, KC_R, KC_T, /* */ KC_Y, KC_U, KC_I, KC_O, KC_P,                      //
        /*              */ KC_A, KC_S, KC_D, KC_F, KC_G, /* */ KC_H, KC_J, KC_K, KC_L, KC_QUOT,                   //
        /*  */ _S(KC_Z), _C(KC_X), _A(KC_C), KC_V, KC_B, /* */ KC_N, KC_M, _A(KC_COMMA), _C(KC_DOT), _S(KC_SLSH), //
        /*             */ _C(KC_TAB), _G(KC_ESC), RAISE, /* */ LOWER, _A(KC_BSPC), FN),                           //

    [_LOWER] = LAYOUT(                                                                                //
        /*            */ KC_1, KC_2, KC_3, KC_4, KC_5, /* */ KC_MINS, KC_EQL, KC_DEL, KC_UP, KC_BSPC, //
        /*            */ KC_6, KC_7, KC_8, KC_9, KC_0, /* */ KC_BSLS, KC_SCLN, KC_LFT, KC_DN, KC_RGT, //
        /* */ ___, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, /* */ ___, ___, ___, ___, KC_TAB,              //
        /*                           */ ___, ___, ___, /* */ ___, ___, ___),                          //

    [_RAISE] = LAYOUT(                                                                                 //
        /*    */ KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, /* */ KC_UNDS, KC_PLUS, ___, ___, KC_TILDE, //
        /* */ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, /* */ KC_PIPE, KC_COLN, ___, ___, KC_GRV,   //
        /*                     */ ___, ___, ___, ___, ___, /* */ KC_LCBR, KC_RCBR, ___, ___, ___,      //
        /*                               */ ___, ___, ___, /* */ ___, ___, ___),                       //

    [_FN] = LAYOUT(                                                                               //
        /*   */ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /* */ KC_PSCR, KC_SCRL, KC_PAUS, ___, KC_CAPS, //
        /*  */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, /* */ KC_F11, KC_F12, ___, ___, ___,           //
        /* */ KC_MUTE, KC_VOLD, KC_VOLU, ___, ___, /* */ ___, ___, ___, ___, ___,                 //
        /*                       */ ___, ___, ___, /* */ ___, ___, ___),                          //
};

// COMBO is everything !
const uint16_t PROGMEM combo_esc[] = { KC_Q, KC_W, COMBO_END };
const uint16_t PROGMEM combo_bsp[] = { KC_O, KC_P, COMBO_END };
const uint16_t PROGMEM combo_tab[] = { KC_S, KC_D, COMBO_END };
const uint16_t PROGMEM combo_ta2[] = { KC_S, KC_A, COMBO_END };
const uint16_t PROGMEM combo_ent[] = { KC_L, KC_QUOT, COMBO_END };
const uint16_t PROGMEM combo_alt[] = { KC_DOT, KC_COMMA, COMBO_END };
const uint16_t PROGMEM combo_hom[] = { KC_LEFT, KC_DOWN, COMBO_END };
const uint16_t PROGMEM combo_end[] = { KC_DOWN, KC_RIGHT, COMBO_END };
const uint16_t PROGMEM combo_pgu[] = { KC_DEL, KC_BSPC, KC_UP, COMBO_END };
const uint16_t PROGMEM combo_pgd[] = { KC_LEFT, KC_DOWN, KC_RIGHT, COMBO_END };
const uint16_t PROGMEM combo_rst[] = { KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, COMBO_END };
//
combo_t key_combos[] = {
    COMBO(combo_bsp, KC_BSPC), //
    COMBO(combo_esc, KC_ESC),  //
    COMBO(combo_tab, KC_TAB),  //
    COMBO(combo_ta2, KC_TAB),  //
    COMBO(combo_ent, KC_ENT),  //
    COMBO(combo_alt, KC_RALT), //
    COMBO(combo_hom, KC_HOME), //
    COMBO(combo_end, KC_END),  //
    COMBO(combo_pgu, KC_PGUP), //
    COMBO(combo_pgd, KC_PGDN), //
    COMBO(combo_rst, QK_BOOT)  //
};

// Encoders
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[4][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] /*  */ = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },   //
    [_LOWER] /* */ = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }, //
    [_RAISE] /* */ = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },   //
    [_FN] /*    */ = { ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },   //
};
#endif
