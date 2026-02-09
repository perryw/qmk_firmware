/* Copyright 2020 Boardsource
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
    _SPACE,
};

// Readability keycodes
#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define SPACE    MO(_SPACE)
#define SPC_FN LT(_SPACE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT_ortho_4x12(
    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
    RM_TOGG,        KC_LCTL, KC_LALT, KC_LGUI, LOWER,   SPC_FN, SPC_FN,   RAISE,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
  ),

  [_RAISE] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    QK_BOOT, RM_VALD, RM_VALU, _______, _______, _______, _______, _______,    RM_HUEU,    RM_HUED, RM_SATU, RM_SATD
  ),

  [_LOWER] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    RM_NEXT, RM_PREV, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_SPACE] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
    RM_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

#ifdef RGB_MATRIX_ENABLE
// NOTE: the LEDs 0-9 are underglow
// NOTE: Don't use rgb_matrix_set_color_all here - it overrides the typing heatmap effect
//       Only set specific layer indicator LEDs to preserve heatmap on typed keys
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)){  // special handling per layer
        case 0: // main layer
            break;
        case 1:  // RAISE layer
            // rgb_matrix_set_color_all(0, 0, 0); // Commented out to preserve heatmap

            // E
            // rgb_matrix_set_color(13, 25, 11, 71);
            // R
            // rgb_matrix_set_color(14, 25, 11, 71);
            // I
            // rgb_matrix_set_color(18, 25, 11, 71);
            // A
            // rgb_matrix_set_color(23, 25, 11, 71);
            // S
            // rgb_matrix_set_color(24, 25, 11, 71);

            // RAISE key
            rgb_matrix_set_color(53, 25, 11, 71);
            break;
        case 2: // LOWER layer
            // rgb_matrix_set_color_all(0, 0, 0); // Commented out to preserve heatmap

            // W
            // rgb_matrix_set_color(12, 38, 53, 16);
            // E
            // rgb_matrix_set_color(13, 38, 53, 16);
            // R
            // rgb_matrix_set_color(14, 38, 53, 16);
            // O
            // rgb_matrix_set_color(19, 38, 53, 16);
            // L
            // rgb_matrix_set_color(31, 38, 53, 16);

            // LOWER key
            rgb_matrix_set_color(50, 38, 53, 16);

            break;
        case 3: // SPACE layer
            // rgb_matrix_set_color_all(0, 0, 0); // Commented out to preserve heatmap

            // E
            // rgb_matrix_set_color(13, 4, 80, 48);
            // P
            // rgb_matrix_set_color(20, 4, 80, 48);
            // A
            // rgb_matrix_set_color(23, 4, 80, 48);
            // S
            // rgb_matrix_set_color(24, 4, 80, 48);
            // C
            // rgb_matrix_set_color(37, 4, 80, 48);

            // SPACE keys (both)
            rgb_matrix_set_color(51, 4, 80, 48);
            rgb_matrix_set_color(52, 4, 80, 48);

            break;
        default:
            break;
    }
    return false;
}
#endif
