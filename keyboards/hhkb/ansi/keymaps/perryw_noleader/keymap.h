#include QMK_KEYBOARD_H

enum layout_names {
    _BASE=0,
    _DEV,
    _MOUSE,
    _MEDIA,
    _NAV
};

enum tapdance_keycodes {
    TD_LGUI_MOUSE = 0,     // Tap dance key to switch to mouse layer _MOUSE
    TD_RGUI_MOUSE
};
