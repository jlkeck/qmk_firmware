#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _MEDR,
  _NAVR,
  _MOUR,
  _NSSL,
  _NSL,
  _FUNL
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,---------------------------------------------------------|                 |------------------------------------------------------------.
    ALT_T(KC_ESC),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______, // RALT_T(KC_BSPC),
  //|------------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+---------------|
    CTL_T(KC_TAB),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,  KC_QUOT, _______, // RCTL_T(KC_ENT),
  //|------------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+---------------|
  /* LSFT_T(KC_CAPS) */ KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH, _______, // RSFT_T(KC_QUOT),
  //|------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------------|
  //
     KC_LCTL, KC_LALT, KC_LGUI, LT(_MEDR, KC_ESC), LT(_NAVR, KC_SPC), LT(_MOUR, KC_TAB), LT(_NSSL, KC_ENT), LT(_NSL, KC_BSPC), LT(_FUNL,KC_DEL), KC_RGUI, KC_RALT, _______ // KC_RCTL
  //`--------+--------+--------|+|----------------+------------------+------------------|+|----------------+------------------+-----------------|+|------+--------+--------'
  ),


  [_MEDR] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   KC_MUTE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   RGB_RST, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_NAVR] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                   KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                    KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_MOUR] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                   _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_NSSL] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_NSL] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______,  KC_DOT,    KC_0, KC_MINS, _______, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_FUNL] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                   _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                DT_PRNT,  DT_UP,   DT_DOWN,  KC_APP,  KC_SPC,  KC_TAB, _______, _______, _______, _______, _______, _______
          //`------------------------------------------------------------------------------------------------------------'
  )
};

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}
