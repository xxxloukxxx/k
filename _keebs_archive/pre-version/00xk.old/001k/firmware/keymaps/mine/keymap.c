/* 
(6+6) + (6+6) + (6+6) + 5
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0]=LAYOUT( 
KC_ESC  , KC_Q    , KC_W   , KC_E  , KC_R    , KC_T , KC_Y , KC_U , KC_I    , KC_O    , KC_P    , KC_BSPC ,
KC_LSFT , KC_A    , KC_S   , KC_D  , KC_F    , KC_G , KC_H , KC_J , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
KC_LCTL , KC_Z    , KC_X   , KC_C  , KC_V    , KC_B , KC_N , KC_M , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
KC_LGUI , KC_LALT , KC_SPC , MO(1) , KC_TAB
),

[1]=LAYOUT( 
KC_GRV  , KC_1    , KC_2   , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_DEL   ,
KC_TRNS , KC_NO   , KC_NO  , KC_NO   , KC_NO   , KC_HOME , KC_PGUP , KC_MINS , KC_EQL  , KC_BSLS , KC_UP   , MO(2)    ,
KC_TRNS , KC_NO   , KC_NO  , KC_NO   , KC_NO   , KC_END  , KC_PGDN , KC_LBRC , KC_RBRC , KC_LEFT , KC_DOWN , KC_RIGHT ,
KC_TRNS , KC_TRNS , KC_ENT , KC_TRNS , KC_TRNS
),

[2]=LAYOUT( 
KC_CAPS , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_TRNS ,
KC_TRNS , KC_MUTE , KC_VOLD , KC_VOLU , KC_MSTP , KC_MPLY , KC_TRNS , KC_TRNS , KC_TRNS , KC_F11  , KC_F12  , KC_TRNS ,
KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
KC_TRNS , KC_TRNS , TO(3)   , KC_TRNS , KC_TRNS
),

[3]=LAYOUT( 
TO(0)   , KC_P7   , KC_P8   , KC_P9 , KC_PPLS , KC_PMNS , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_DEL   , KC_BSPC  ,
KC_LPRN , KC_P4   , KC_P5   , KC_P6 , KC_PAST , KC_PSLS , KC_HOME , KC_NO , KC_NO , KC_PGDN , KC_UP    , KC_PGUP  ,
KC_RPRN , KC_P1   , KC_P2   , KC_P3 , KC_PEQL , KC_NUM  , KC_END  , KC_NO , KC_NO , KC_LEFT , KC_DOWN  , KC_RIGHT ,
KC_P0   , KC_PDOT , KC_TRNS , KC_NO , KC_NO 
)

};
