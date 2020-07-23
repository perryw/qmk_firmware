#include "keymap.h"

//Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LGUI_MOUSE] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, _MOUSE),
    [TD_RGUI_MOUSE] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RGUI, _MOUSE),
    [TD_LALT_MOUSE] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LALT, _MOUSE),
    [TD_RALT_MOUSE] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RALT, _MOUSE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     |-----------+-------+--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
     |    `      |  1    | 2      | 3     |   4   |   5   |   6   | 7     | 8     | 9     | 0     | -     | =     | Bksp |Bksp|
     |-----------+-------+--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
     |    Tab    |  Q    | W      | E     |   R   |   T   |   Y   |  U    | I     | O     | P     | [     | ]     |      | \  |
     |-----------+-------+--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
     | Esc/Ctrl  |   A   | S      | D     |   F   |   G   |   H   |  J    | K     | L     |;/Media| '     | Enter |      |    |
     |-----------+-------+--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
     |   Shift   | Z/Ctl | X/Alt  | C/Gui |   V   |   B   |   N   |  M    | ,/Gui | ./Alt | //Ctl | Shift | NAV   |      |    |
     |-----------+-------+--------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
                 |------+--------------------+-------------------+--------------------+------|
                 | TapTap(Alt, Mouse)  | Gui | *** Space/DEV *** | TapTap(Gui, Mouse) | Dev  |
                 |------+--------------------+-------------------+--------------------+------|
    */

    [_BASE] = LAYOUT( //  default layer
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(_MEDIA, KC_SCLN), KC_QUOT, ALL_T(KC_ENT),
        KC_LSFT, CTL_T(KC_Z), ALT_T(KC_X), GUI_T(KC_C), KC_V, KC_B, KC_N, KC_M, GUI_T(KC_COMM), ALT_T(KC_DOT), CTL_T(KC_SLSH), KC_RSFT, MO(_NAV),
        TD(TD_LALT_MOUSE), KC_LGUI, LT(_DEV, KC_SPC), KC_RGUI, TD(TD_RALT_MOUSE)),

    /* Layer DEV: DEV mode (DEV Fn)
      TODO: Add a cmd/tab function to the developer layer for quick switching between different applications when debugging
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      | F1  | F2  | F3  | F4 | F5 |   F6   |       F7       |     F8       |     F9    |     F10     | F11 |   F12 |  DEL  | DEL |
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      | CAPS |     |     |     |    |    |        |                |              |           |             |     |       |       |     |
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      | F1  | F2  | F3  | F4 | F5 | Left   |  Down          | Up           | Right     |             |     |       |       |     |
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    | SPC|        |                |              |           |             |     | NAV   |       |     |
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+
     */

    [_DEV] = LAYOUT(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DELETE, KC_DELETE,
        KC_CAPSLOCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_NAV),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Layer MOUSE: MOUSE mode (MOUSE Fn)
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    |    |        |                |              |           |             |     |       |       |     |
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |BTN1 | UP  |BTN2|    |        |    WHEEL-DN    |   WHEEL-UP   |           |             |     |       |       |     |
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     | LF  | DN  | RT |    |        |   BTN1         |  BTN2        |    BTN3   |             |     |       |       |     |
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    |    |        |                |              |           |             |     | NAV   |       |     |
      |------+-----+-----+-----+----+----+--------+----------------+--------------+-----------+-------------+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+
     */

    [_MOUSE] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_WH_D, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_NAV),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Layer MEDIA: mode (Hold Semi-colon)
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |                |              |           |             |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |                |              |           |             |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |  Previous      | Next         |           |  Play/Pause |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |  Volume Down   | Volume Up    | Mute      |             |     |       | NAV   |     |
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

    [_MEDIA] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_MUTE, KC_TRNS, KC_MPLY, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, MO(_NAV),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Layer NAV: mode (Hold Fn)
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |                |              |           |             |     |       |  DEL  | DEL |
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      | CAPS |     |     |     |    |    |    |                |              |           |             | UP  |       |       |     |
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |                |              |    HOME   |    PgUP     | LFT |  RT   |       |     |
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |                |              |    END    |     PgD     |  DN |       | NAV   |     |
      |------+-----+-----+-----+----+----+----+----------------+--------------+-----------+-------------+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

    [_NAV] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_DEL,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, MO(_NAV),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};
