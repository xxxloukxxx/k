/*
(6+6) + (6+6) + (6+6) + 5 + 5
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,                          KC_P7,  KC_P8,  KC_P9  ,KC_PAST,
        KC_TAB,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,      KC_ENT,                          KC_P4,  KC_P5,  KC_P6  ,KC_PPLS,
        KC_LSFT,   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT,      KC_UP,            KC_P1,  KC_P2,  KC_P3  ,KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE   , KC_SPACE  , MO(1), MO(2),        KC_LEFT, KC_DOWN, KC_RIGHT,          KC_P0,  KC_PDOT ),

    [1] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,                                   _______, _______, _______,KC_PSLS,
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_QUOT, KC_BSLS,             _______, _______, _______,KC_PMNS,
        _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_SLSH,_______, KC_PGUP,    _______, _______, _______,_______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END, _______, _______ ),

    [2] = LAYOUT(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_INS,                       _______, _______, _______, _______,
        KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MSTP, _______, _______, _______, KC_F11, KC_F12,_______,               _______, _______, _______, _______,
        KC_CAPS, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_NUM,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,_______ )

};

#ifdef OLED_ENABLE
// static void render_logo(void) {
//    static const char PROGMEM qmk_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//    };
//
//    oled_write_P(qmk_logo, false);
//}

static void render_logo(void) {
//    static const char PROGMEM raw_logo[] = {
//        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
//        0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9,
//        0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//    };
//
//    static const char PROGMEM raw_logo1[] = {
//        0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08,
//         0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82,
//         0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//    };
//
//    static const char PROGMEM raw_logo2[] = {
//        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02,
//         0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
//         0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//    };
//    
//    oled_write_P(PSTR("PROUT \n"),false);
//    oled_write_raw_P(raw_logo, sizeof(raw_logo));
//    oled_write_P(PSTR("\n"),false);
//    oled_write_raw_P(raw_logo1, sizeof(raw_logo1));
//    oled_write_P(PSTR("\n"),false);
//    oled_write_raw_P(raw_logo2, sizeof(raw_logo2));
//    oled_write_P(PSTR("\n PROUT \n"),false);
}



bool oled_task_user(void) {
    // Host Keyboard Layer Status
   oled_write_P(PSTR("Gigi Keyb'\n"),false);
    
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Fn1\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Fn2\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
	render_logo();    
    return false;
}
#endif

