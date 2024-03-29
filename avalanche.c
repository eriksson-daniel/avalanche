// Copyright 2022 Vitaly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        switch(biton32(layer_state)){
            case 1:
                if (clockwise) {
                    tap_code(KC_LEFT);
                } else {
                    tap_code(KC_RGHT);
                }

                return true;
            case 4:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }

                return true;
            default:
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }

                return true;

        }
    } else if (index == 1) { /* Second encoder */
        switch(biton32(layer_state)){
            case 2:
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    register_code(KC_LEFT_SHIFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LEFT_SHIFT);
                }
            
                return true;
            case 4:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }

                return true;    
            default:
                if (clockwise) {
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                }

                return true;
        }
    }
    return true;
}
#endif
