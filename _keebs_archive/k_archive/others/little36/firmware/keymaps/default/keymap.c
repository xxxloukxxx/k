/*
3 *(5+5) + 6 = 36
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
       KC_Q                 , KC_W   , KC_E    , KC_R   , KC_T     , KC_Y    , KC_U   , KC_I     , KC_O  , KC_P     ,
       MT(MOD_LSFT, KC_A)   , KC_S   , KC_D    , KC_F   , KC_G     , KC_H    , KC_J   , KC_K     , KC_L  , KC_RSFT   ,
       MT(MOD_LCTL, KC_Z)   , KC_X   , KC_C    , KC_V   , KC_B     , KC_N    , KC_M   , KC_LALT  , KC_RGUI, KC_RCTL ,
                                        KC_ESC , MO(2)  , KC_SPACE , KC_ENT  ,  MO(1) , KC_BSPC ),

    [1] = LAYOUT(
       KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
       KC_GRV  , KC_TRNS  , KC_TRNS  , KC_NO  , KC_NO  , KC_DEL ),

    [2] = LAYOUT(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO )

};

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_ESC)) { tap_code16(KC_MUTE); }
    else if (leader_sequence_one_key(KC_S)) { SEND_STRING(SS_LCTL("s")); }
    else if (leader_sequence_one_key(KC_Q)) { SEND_STRING(SS_LCTL("q")); }
    else if (leader_sequence_one_key(KC_W)) { SEND_STRING(SS_LCTL("w")); }
    else if (leader_sequence_one_key(KC_D)) { SEND_STRING(SS_LCTL("d")); }
}
