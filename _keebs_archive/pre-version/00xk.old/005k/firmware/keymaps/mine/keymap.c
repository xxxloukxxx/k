/*
(6+6) + (6+6) + (6+6) + 5 + 5
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT, MO(2), KC_SPACE, MO(1), KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT),

    [1] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_PGUP, KC_SCLN,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),

    [2] = LAYOUT(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_INS,
        KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MSTP, _______, _______, _______, KC_F11, KC_F12, TG(3),
        _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [3] = LAYOUT(
        KC_NUM, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_PAST, _______, _______, _______, _______, _______, _______,
        _______, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PPLS, _______, _______, _______, _______, _______, _______,
        _______, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_PENT, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_P0, _______, _______, _______, _______, _______, _______, _______)

};



#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
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

