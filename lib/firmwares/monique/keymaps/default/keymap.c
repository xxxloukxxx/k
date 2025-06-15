#include "quantum.h"

enum layers { _BASE, _RAISE, _LOWER, _FN, _BOTH };

#define ___ KC_TRNS

#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_SPC)
#define FN LT(_FN, KC_ENT)

#define KC_BSPC KC_BACKSPACE
#define KC_LFT KC_LEFT
#define KC_RGT KC_RIGHT
#define KC_DN KC_DOWN

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(                                                                                  //
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, /*   */ KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_BSPC,   //
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, /*         */ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,           //
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, /*        */ KC_H, KC_J, KC_K, KC_L, KC_ENTER,                //
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, /*        */ KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, KC_RSFT, //
        KC_LCTL, KC_LGUI, KC_LALT, RAISE, /*             */ LOWER, FN, KC_RGUI, KC_LCTL,                     //
        KC_MUTE),                                                                                      //

    [_LOWER] = LAYOUT(                                                   //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,      //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,           //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,      //
        ___, ___, ___, ___, ___, ___, ___, ___,                          //
        KC_MUTE),                                                        //

    [_RAISE] = LAYOUT(                                                   //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,      //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,           //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,      //
        ___, ___, ___, ___, ___, ___, ___, ___,                          //
        KC_MUTE),                                                        //

    [_BOTH] = LAYOUT(                                                    //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,      //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,           //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,      //
        ___, ___, ___, ___, ___, ___, ___, ___,                          //
        KC_MUTE),                                                        //

    [_FN] = LAYOUT(                                                      //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,      //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,           //
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,      //
        ___, ___, ___, ___, ___, ___, ___, ___,                          //
        KC_MUTE),                                                        //
};

// COMBO is everything !
const uint16_t PROGMEM combo_rst[] = {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, COMBO_END};
//
combo_t key_combos[] = {
    COMBO(combo_rst, QK_BOOT) //
};

// Encoders
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[5][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] /*  */ = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},   //
    [_LOWER] /* */ = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},   //
    [_RAISE] /* */ = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},   //
    [_FN] /*    */ = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},   //
    [_BOTH] /*    */ = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}, //
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    update_tri_layer(_LOWER, _RAISE, _BOTH);
    return true;
}
