/* 
12 + 12 + 14 + 15 = 53
*/

#include QMK_KEYBOARD_H

#define NO KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
	KC_ESC ,KC_Q   ,KC_W   ,KC_E  ,KC_R  ,KC_T  ,                                  KC_Y,  KC_U,  KC_I   , KC_O    , KC_P    , KC_BACKSPACE,
	KC_TAB ,KC_A   ,KC_S   ,KC_D  ,KC_F  ,KC_G  ,                                  KC_H,  KC_J,  KC_K   , KC_L    , KC_SCLN , KC_QUOT ,
	KC_LSFT,KC_Z   ,KC_X   ,KC_C  ,KC_V  ,KC_B  ,  NO,                       NO ,  KC_N,  KC_M,  KC_COMM, KC_DOT  , KC_UP   , KC_SLSH,
	KC_LCTL,KC_LGUI,KC_LALT,       NO    ,NO    ,  NO,  NO  ,KC_SPACE,   NO ,NO ,  NO  ,  NO  ,           KC_LEFT , KC_DOWN , KC_RIGHT
    )
};
