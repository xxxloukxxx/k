/* [{a:3},"Q\n\n\n\n\nESC","W\n\n\n\nAPE",{a:7},"E","R","T",{x:0.5},"Y","U","I",{a:3},"O\n\n\n\n\nBAC","P\n\n\n\nKSPC"], */
/* ["A\n\n\n\n\nT","S\n\n\n\nAB",{a:7},"D","F","G",{x:0.5},"H","J","K",{a:3},"L\n\n\n\n\nRET","´\n\n\n\nURN"], */
/* ["Z'\n\n\n\n\nLSH","X\n\n\n\nIFT",{a:7},"C","V","B",{x:0.5},"N","M",",",{a:3},".\n\n\n\n\nRA","/\n\n\n\nLT"], */
/* [{a:7,w:1.25},"LCTL",{x:0.25,w:1.25},"LGUI",{x:0.25,w:2},"LALT,SPACE",{x:0.5,w:2},"NAV,SPACE",{x:0.25,w:1.25},"FN1",{x:0.25,w:1.25},"RSHIFT"], */
/* [{y:1},"1","2","3","4","5",{x:0.5},"","-","=","UP","DEL"], */
/* [{a:3},"6\n\n\n\n\nCAPS","7\n\n\n\nLOCK",{a:7},"8","9","0",{x:0.5},"",";",{a:3},"LEFT\n\n\n\n\nHO","DN\n\n\n\nME\nE","RIGHT\n\n\n\nND"], */
/* [{a:7},"","","","","",{x:0.5},"","","[","]","\\"], */
/* [{w:1.25},"",{x:0.25,w:1.25},"",{x:0.25,w:2},"",{x:0.5,c:"#000000",t:"#cccccc",w:2},"",{x:0.25,c:"#cccccc",t:"#000000",w:1.25},"",{x:0.25,w:1.25},""], */
/* [{y:1},"F1","F2","F3","F4","F5",{x:0.5},"","","","VOL UP",""], */
/* ["F6","F7","F8","F9","F10",{x:0.5},"","","MUTE","VOL DN","PLAY"], */
/* ["","","","","",{x:0.5},"","","","",""], */
/* [{w:1.25},"",{x:0.25,w:1.25},"",{x:0.25,w:2},"",{x:0.5,w:2},"",{x:0.25,c:"#000000",t:"#cccccc",w:1.25},"",{x:0.25,c:"#cccccc",t:"#000000",w:1.25},""] */

#include "quantum.h"

// Tap Dance Declarations
enum {
    GUITD = 0,
};

tap_dance_action_t tap_dance_actions[] = {
    /* [GUITD] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_P)) // */
};

enum layers {
    QWERTY,
    NAV,
    FN,
};

#define ___ KC_TRNS

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(                                                               //
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,                  //
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT,               //
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, //
        KC_LCTL, KC_LGUI, LALT_T(KC_SPACE), LT(NAV, KC_SPACE), MO(FN), KC_RSFT),

    [NAV] = LAYOUT(                                                             //
        KC_1, KC_2, KC_3, KC_4, KC_5, ___, KC_MINS, KC_EQL, KC_UP, KC_DEL,      //
        KC_6, KC_7, KC_8, KC_9, KC_0, ___, KC_SCLN, KC_LEFT, KC_DOWN, KC_RIGHT, //
        ___, ___, ___, ___, ___, ___, ___, KC_LBRC, KC_RBRC, KC_BSLS,           //
        ___, ___, ___, ___, ___, ___),

    [FN] = LAYOUT(                                                               //
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, ___, ___, ___, KC_VOLU, ___,          //
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, ___, ___, KC_MUTE, KC_VOLD, KC_MPLY, //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,                        //
        ___, ___, ___, ___, ___, ___),
};

const uint16_t PROGMEM comb_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM comb_tab[] = {KC_A, KC_S, COMBO_END};
/* const uint16_t PROGMEM comb_lsft[]  = {KC_Z, KC_X, COMBO_END}; */
const uint16_t PROGMEM comb_bs[]    = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM comb_bs2[]    = {KC_UP, KC_DEL, COMBO_END};
const uint16_t PROGMEM comb_enter[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM comb_ralt[]  = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM comb_caps[]  = {KC_6, KC_7, COMBO_END};
const uint16_t PROGMEM comb_grav[]  = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_home[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo_end[]  = {KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_pgup[] = {KC_LEFT, KC_UP, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_pgdn[] = {KC_LEFT, KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_lprn[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_lcbr[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo_lbrc[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo_rprn[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_rcbr[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo_rbrc[] = {KC_N, KC_M, COMBO_END};
//
const uint16_t PROGMEM combo_term[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM combo_rst[]  = {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, COMBO_END};
//
combo_t key_combos[] = {
    COMBO(comb_esc, KC_ESC), //
    COMBO(comb_tab, KC_TAB), //
    /* COMBO(comb_lsft, KC_LSFT),               // */
    COMBO(comb_bs, KC_BACKSPACE),            //
    COMBO(comb_bs2, KC_BACKSPACE),            //
    COMBO(comb_enter, KC_ENTER),             //
    COMBO(comb_ralt, KC_RALT),               //
    COMBO(comb_caps, KC_CAPS),               //
    COMBO(comb_grav, KC_GRV),                //
    COMBO(combo_home, KC_HOME),              //
    COMBO(combo_end, KC_END),                //
    COMBO(combo_pgup, KC_PGUP),              //
    COMBO(combo_pgdn, KC_PGDN),              //
    COMBO(combo_lprn, KC_LPRN),              //
    COMBO(combo_lcbr, KC_LCBR),              //
    COMBO(combo_lbrc, KC_LBRC),              //
    COMBO(combo_rprn, KC_RPRN),              //
    COMBO(combo_rcbr, KC_RCBR),              //
    COMBO(combo_rbrc, KC_RBRC),              //
    COMBO(combo_term, LSFT(LGUI(KC_ENTER))), //
    COMBO(combo_rst, QK_BOOT),               //
};

void leader_start_user(void) {}

void leader_end_user(void) {}
