/*
3 * (6+6) + 9 = 45
*/

#include "quantum.h"

#include QMK_KEYBOARD_H

#define ___ KC_TRNS
#define LAYOUT_mrtod(...) LAYOUT(__VA_ARGS__)
#define KC_ALPH_R1 KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P         // 10
#define KC_ALPH_R2 KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L               // 9
#define KC_ALPH_R3 KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M                           // 7
#define KC_NUMBERS KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0         // 10
#define KC_FNxx KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10 // 10
#define KC_MEDIA KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MSTP                          // 5

// Layers
enum
{
  QWERTY = 0,
  NUM,
  FUNC,
  NUMPAD
};

// Tap Dance Declarations
enum
{
  TD_GUI = 0,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_P)),
};

// Layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_mrtod(                                                                       //
        KC_ESC, KC_ALPH_R1, /*                                                         */ KC_BSPC, //
        KC_TAB, KC_ALPH_R2, /*                                                */ KC_QUOT, KC_ENT,  //
        KC_LSFT, KC_ALPH_R3, /*                                */ KC_COMM, KC_DOT, KC_UP, KC_SLSH, //
        KC_LCTL, MO(FUNC), KC_LALT, TD(TD_GUI), KC_SPACE, MO(NUM), /**/ KC_LEFT, KC_DOWN, KC_RIGHT //
        ),                                                                                         //

    [NUM] = LAYOUT_mrtod(                                                                                         //
        KC_GRV, KC_NUMBERS, /*                                                                        */ KC_DEL,  //
        KC_CAPS, KC_MEDIA, /*                                 */ ___, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, //
        ___, KC_PSCR, KC_SCRL, KC_PAUS, ___, ___, /*          */ ___, ___, ___, ___, /*      */ KC_PGUP, KC_SCLN, //
        /*                 */ ___, ___, ___, ___, /**/ ___, /**/ ___, /*            */ KC_HOME, KC_PGDN, KC_END   //
        ),                                                                                                        //

    [FUNC] = LAYOUT_mrtod(                                                                            //
        ___, KC_FNxx, KC_INS,                                                                         //
        ___, KC_MEDIA, /*                                     */ ___, ___, ___, KC_F11, KC_F12, ___,  //
        ___, KC_PSCR, KC_SCRL, KC_PAUS, ___, ___, /*          */ ___, ___, ___, ___, ___, TO(NUMPAD), //
        /*                 */ ___, ___, ___, ___, /**/ ___, /**/ ___, ___, ___, ___),                 //

    [NUMPAD] = LAYOUT_mrtod(                                                          //
        TO(QWERTY), KC_7, KC_8, KC_9, KC_PSLS, KC_PAST, ___, ___, ___, ___, ___, ___, //
        ___, KC_4, KC_5, KC_6, KC_PMNS, KC_PPLS, ___, ___, ___, ___, ___, ___,        //
        ___, KC_1, KC_2, KC_3, KC_DOT, KC_NO, ___, ___, ___, ___, ___, ___,           //
        ___, ___, KC_0, KC_ENT, ___, ___, ___, ___, ___)                              //
};

const uint16_t PROGMEM test_LACC[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM test_LBRC[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM test_LPRN[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM test_RPRN[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM test_RBRC[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM test_RACC[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_TERM[] = {KC_ESC, KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_HOME[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo_END[] = {KC_DOWN, KC_RIGHT, COMBO_END};
//
// const uint16_t PROGMEM combo_BS[] = {KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_ESC[] = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM combo_TAB[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_RST[] = {KC_F7, KC_F8, KC_F9, KC_F10, COMBO_END};

combo_t key_combos[] = {
    COMBO(test_LACC, LSFT(KC_LBRC)),
    COMBO(test_LBRC, KC_LBRC),
    COMBO(test_LPRN, KC_LPRN),
    COMBO(test_RPRN, KC_RPRN),
    COMBO(test_RBRC, KC_RBRC),
    COMBO(test_RACC, LSFT(KC_RBRC)),
    COMBO(combo_TERM, LGUI(LSFT(KC_ENTER))),
    COMBO(combo_HOME, KC_HOME),
    COMBO(combo_END, KC_END),
    //    COMBO(combo_BS, KC_BACKSPACE),
    //    COMBO(combo_ESC, KC_ESC),
    //    COMBO(combo_TAB, KC_TAB),
    COMBO(combo_RST, QK_BOOT),
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
