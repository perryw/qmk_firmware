// Copyright 2022 @boardsource
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _RAISE,
    _LOWER,
    _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x12(
        KC_TAB,             KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,        KC_Y,        KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
        MT(MOD_LCTL,KC_ESC),KC_A,    KC_S,    KC_D,    KC_F,     KC_G,        KC_H,        KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,        KC_N,        KC_M,     KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
        RGB_TOG,            KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER), LT(_NAV,KC_SPC), LT(_NAV,KC_SPC), MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_RAISE] = LAYOUT_ortho_4x12(
        S(KC_GRV),  S(KC_1),  S(KC_2),  S(KC_3),  S(KC_4),  S(KC_5),  S(KC_6),  S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),    KC_BSPC,
        KC_DEL,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    S(KC_MINS), S(KC_EQL),  S(KC_LBRC), S(KC_RBRC), S(KC_BSLS),
        _______,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   S(KC_NUHS), S(KC_NUBS), KC_HOME,    KC_END,     _______,
        QK_BOOT,    _______,  _______,  _______,  _______,  _______,  _______,  MO(_NAV),   KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MPLY
    ),
    [_LOWER] = LAYOUT_ortho_4x12(
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
        RGB_MOD,  _______, _______, _______, MO(_NAV),_______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),
    [_NAV] = LAYOUT_ortho_4x12(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
