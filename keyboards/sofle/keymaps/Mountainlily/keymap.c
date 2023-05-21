#include QMK_KEYBOARD_H


// Super Alt Tab -- https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab
bool     is_alt_tab_active   = false; 
bool     is_shalt_tab_active = false; 
uint16_t alt_tab_timer       = 0;
uint16_t alt_tab_timeout_spt = 1000;

enum custom_keycodes {          
  ALT_TAB = SAFE_RANGE,
  SHALT_TAB,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;

    case SHALT_TAB:
      if (record->event.pressed) {
        if (!is_shalt_tab_active) {
          is_shalt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_LSFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {

  if (is_alt_tab_active || is_shalt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > alt_tab_timeout_spt) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
      is_shalt_tab_active = false;
    }
  }

}


// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,      KC_1,       KC_2,    KC_3,    KC_4,          KC_5,                                          KC_6,         KC_7,    KC_8,    KC_9,    KC_0,       KC_DEL, 
        KC_TAB,      KC_Q,       KC_D,    KC_R,    KC_W,          KC_B,                                          KC_J,         KC_F,    KC_U,    KC_P,    KC_SCLN,    KC_QUOT, 
        KC_LSFT,     KC_A,       KC_S,    KC_H,    KC_T,          KC_G,                                          KC_Y,         KC_N,    KC_E,    KC_O,    KC_I,       KC_RSFT, 
        KC_LALT,     KC_Z,       KC_X,    KC_M,    KC_C,          KC_V,         KC_NO,          KC_MUTE,         KC_K,         KC_L,    KC_COMM, KC_DOT,  KC_QUES,    KC_RALT, 
                                 KC_LGUI, MO(3),   LT(2, KC_TAB), LT(1,KC_ENT), LCTL_T(KC_SPC), RCTL_T(KC_BSPC), LT(1,KC_DEL), MO(2),   MO(3),   KC_RGUI
        ),
    [1] = LAYOUT(
        KC_DEL,      KC_6,       KC_7,    KC_8,    KC_9,          KC_0,                                          KC_NO,        KC_WBAK, KC_BTN3, KC_WFWD, KC_NO,      KC_NO, 
        KC_BSPC,     KC_NO,      KC_HOME, KC_UP,   KC_END,        KC_PGUP,                                       KC_WH_U,      KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,      KC_NO, 
        KC_TRNS,     LSA(KC_NO), KC_LEFT, KC_DOWN, KC_RGHT,       KC_PGDN,                                       KC_WH_D,      KC_MS_L, KC_MS_D, KC_MS_R, LSA(KC_NO), KC_TRNS, 
        KC_TRNS,     LCA(KC_NO), KC_NO,   KC_NO,   KC_NO,         KC_NO,        KC_NO,          KC_MPLY,         KC_NO,        KC_NO,   KC_NO,   KC_NO,   LCA(KC_NO), KC_TRNS, 
                                 KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,        KC_TRNS,         KC_TRNS,      KC_TRNS, KC_TRNS, TO(0)
        ),
    [2] = LAYOUT(
        KC_GRV,      KC_NO,      KC_NO,   KC_NO,   KC_NO,         KC_NO,                                         KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO, 
        KC_NO,       KC_TILD,    KC_HASH, KC_LBRC, KC_RBRC,       KC_COLN,                                       KC_DQUO,      KC_ASTR, KC_SLSH, KC_BSLS, KC_PIPE,    KC_NO, 
        KC_TRNS,     KC_EXLM,    KC_UNDS, KC_LPRN, KC_RPRN,       KC_SCLN,                                       KC_QUOT,      KC_PLUS, KC_MINS, KC_EQL,  KC_AMPR,    KC_TRNS, 
        KC_TRNS,     KC_AT,      KC_DLR,  KC_LCBR, KC_RCBR,       KC_NO,        KC_NO,          KC_NO,           KC_NO,        KC_PERC, KC_LT,   KC_GT,   KC_CIRC,    KC_TRNS, 
                                 KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,        KC_TRNS,         KC_TRNS,      KC_TRNS, KC_TRNS, TO(0)
        ),
    [3] = LAYOUT(
        RCS(KC_ESC), KC_NO,      KC_NO,   KC_NO,   KC_NO,         NK_TOGG,                                       KC_APP,       KC_PSCR, KC_SCRL, KC_PAUS, KC_INS,     KC_NUM, 
        KC_NO,       KC_NO,      KC_NO,   KC_NO,   LCTL(KC_F2),   KC_NO,                                         KC_NO,        KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_NO, 
        KC_TRNS,     KC_NO,      KC_NO,   KC_NO,   KC_F2,         KC_NO,                                         KC_NO,        KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_TRNS, 
        KC_TRNS,     RGUI(KC_L), KC_NO,   KC_NO,   KC_NO,         KC_NO,        KC_NO,          KC_NO,           KC_NO,        KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_TRNS, 
                                 KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,        KC_TRNS,         KC_TRNS,      KC_TRNS, KC_TRNS, TO(0)
        )

    /*
    [x] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        ),
    */
}; 


// Encoders
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {

    [0] = { ENCODER_CCW_CW(SHALT_TAB, ALT_TAB), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(KC_NO, KC_NO),   ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [2] = { ENCODER_CCW_CW(KC_NO, KC_NO),   ENCODER_CCW_CW(KC_NO, KC_NO)  },
    [3] = { ENCODER_CCW_CW(KC_NO, KC_NO),   ENCODER_CCW_CW(KC_NO, KC_NO)  },

};
#endif

