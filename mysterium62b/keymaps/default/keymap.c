#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FN 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define F_FN LT(_FN, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* qwerty */
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC ,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT ,
    KC_GRV,   KC_A,    KC_S,    KC_D,    F_FN,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  ,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_LCTL,  KC_LGUI, KC_LALT, MO(_FN), LOWER,   KC_SPC,    MO(_FN), KC_ENT,  KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
  ),

  [_LOWER] = LAYOUT(
    KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSPC , 
    KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL  ,
    KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE ,
    KC_TRNS,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                      KC_F12,  KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO   ,
    KC_NO,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_NO,  KC_NO  , KC_TRNS, KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY
  ),

  [_RAISE] = LAYOUT(
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_LCBR, KC_RCBR, KC_BSPC , 
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL  ,  
    KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS , 
    KC_TRNS,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                      KC_F12,  KC_NUHS, KC_PGUP, KC_PGDN, KC_NO,   KC_NO   ,
    KC_NO,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,    KC_NO,  KC_NO  , KC_TRNS, KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY
  ),

  [_FN] = LAYOUT(
    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 , KC_F12  ,
    KC_NO,    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,                       KC_NO  , KC_NO  , KC_UP  , KC_NO  , KC_PSCR, KC_NO   ,
    KC_NO,    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,                       KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , KC_NO   ,
    KC_NO,    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,                       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO ,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_NO,  KC_NO,    KC_NO  , KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO
  ),


  [_ADJUST] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_Z,    KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
