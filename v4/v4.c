// Copyright 2022 Vitaly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

enum Layer {
    _BASE,
    _FUNCTIONS,
    _SPECIAL_CHAR,
    _NUM,
};

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    oled_write_P(PSTR("Daniels tastatur\n\n"), false);
    // oled_write_P(PSTR("Ord per minutt: "), false);

    // oled_write(get_u8_str(get_current_wpm(), ' '), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("\n\nLag: Vanlig"), false);
            break;
        case _FUNCTIONS:
            oled_write_P(PSTR("\n\nLag: Piler osv"), false);
            break;
        case _SPECIAL_CHAR:
            oled_write_P(PSTR("\n\nLag: Spesiategn"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("\n\nLag: Tall"), false);
            break;
        default:
            oled_write_P(PSTR("\n\nLag: Ukjent"), false);
            break;
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("\n\nCAPS LOCK") : PSTR("\n\nikke caps"), false);

    return true;
}
#endif
