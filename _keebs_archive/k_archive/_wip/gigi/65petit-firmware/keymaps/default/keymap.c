#include QMK_KEYBOARD_H

#define ___ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(                                                                                //
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,             //
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,             //
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, /**/ KC_DEL,      //
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, /**/ KC_UP, //
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE, LT(1, KC_SPACE), KC_RALT, KC_RCTL, /**/ KC_LEFT, KC_DOWN,
        KC_RIGHT), //

    [1] = LAYOUT(                                                                              //
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL, //
        ___, KC_F11, KC_F12, ___, ___, ___, ___, ___, ___, KC_LBRC, KC_RBRC, ___,              //
        ___, KC_MUTE, KC_VOLD, KC_VOLU, ___, ___, ___, KC_MINS, KC_EQL, ___, ___, /**/ ___,    //
        ___, ___, ___, ___, ___, ___, ___, ___, KC_SCLN, KC_QUOT, ___, KC_PGUP,                //
        ___, ___, ___, /**/ ___, /**/ ___, /**/ ___, ___, /**/ KC_HOME, KC_PGDN, KC_END),      //
};

const uint16_t PROGMEM combo_HOME[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo_END[] = {KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_PGUP[] = {KC_UP, KC_LEFT, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_PGDN[] = {KC_DOWN, KC_LEFT, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo_SCLN[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_QUOT[] = {KC_L, KC_ENT, COMBO_END};
const uint16_t PROGMEM combo_RST[] = {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_HOME, KC_HOME), //
    COMBO(combo_END, KC_END),   //
    COMBO(combo_PGDN, KC_PGDN), //
    COMBO(combo_PGUP, KC_PGUP), //
    COMBO(combo_SCLN, KC_SCLN), //
    COMBO(combo_QUOT, KC_QUOT), //
    COMBO(combo_RST, QK_BOOT),  //
};
