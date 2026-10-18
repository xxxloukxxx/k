/*
(6+6) + (6+6) + (6+6) + 5 + 5
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R    , KC_T , KC_Y   , KC_U   , KC_I     , KC_O  , KC_P   , KC_BSPC,
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F    , KC_G , KC_H   , KC_J   , KC_K     , KC_L  , KC_QUOT, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V    , KC_B , KC_N   , KC_M   , KC_COMM  , KC_DOT, KC_UP  , KC_SLSH,
        KC_LCTL, QK_LGUI, KC_LGUI, KC_LALT, KC_SPACE, MO(1), KC_LEFT, KC_DOWN, KC_RIGHT),

    [1] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_CAPS, KC_F1  , KC_F2  ,KC_F3   , KC_F4  , KC_F5  , _______, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,KC_F11  , KC_F12 , KC_VOLD, KC_VOLU, KC_PGUP, KC_SCLN,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),

//  [2] = LAYOUT(
//      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_INS,
//      KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MSTP, _______, _______, _______, KC_F11, KC_F12,_______ ,
//      _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______, _______, _______),

};

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_M)) {
        // Leader, m => Mute
        tap_code16(KC_MUTE);
    } else if (leader_sequence_one_key(KC_S)) {
//        // Leader, s => Ctrl+S
        SEND_STRING(SS_LCTL("s"));
        
//    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
//        // Leader, d, d, s => Types the below string
//        SEND_STRING("https://start.duckduckgo.com\n");


//    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
//        // Leader, a, s => GUI+S
    }
}
