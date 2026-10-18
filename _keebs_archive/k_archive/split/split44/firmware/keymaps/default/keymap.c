#define ___ KC_TRNS

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(1),
        KC_LCTL, KC_LGUI, KC_LALT, KC_ENTER, KC_SPACE, KC_RALT, KC_RGUI, KC_RCTL),

    [1] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        KC_CAPS, ___, ___, ___, ___, ___, KC_PGUP, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
        ___, ___, ___, ___, ___, ___, KC_PGDN, KC_HOME, KC_END, ___, KC_SCLN, ___,
        ___, ___, ___, ___, ___, ___, ___, ___),

};

// const uint16_t PROGMEM test_combo1[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM test_combo2[] = {KC_F, KC_G, COMBO_END};
// const uint16_t PROGMEM test_combo3[] = {KC_H, KC_J, COMBO_END};
// const uint16_t PROGMEM test_combo4[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_F13[] = {KC_ESC, KC_Q, COMBO_END};
combo_t key_combos[] = {
    //    COMBO(test_combo1, KC_LBRC),
    //    COMBO(test_combo2, KC_LPRN),
    //    COMBO(test_combo3, KC_RPRN),
    //    COMBO(test_combo4, KC_RBRC),
    COMBO(combo_F13, KC_F13),
};

/*
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
KC_ESC  , KC_Q    , KC_W   , KC_E  , KC_R    , KC_T , KC_Y , KC_U , KC_I    , KC_O    , KC_P    , KC_BSPC ,
KC_TAB , KC_A    , KC_S   , KC_D  , KC_F    , KC_G , KC_H , KC_J , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
KC_LSFT , KC_Z    , KC_X   , KC_C  , KC_V    , KC_B , KC_N , KC_M , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
KC_LCTL , KC_LALT  , KC_LGUI , KC_ENT ,KC_SPC , KC_LGUI , KC_RALT , KC_RCTL)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
*/
