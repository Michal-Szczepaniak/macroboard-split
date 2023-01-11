#include QMK_KEYBOARD_H

bool spam_space;
bool spam_rmb;
uint16_t spam_timer = false;
uint16_t spam_interval = 50;
uint16_t spam_rmb_timer = false;
uint16_t spam_rmb_interval = 1600;

enum planck_keycodes {
  KC_SPAMSPACE = SAFE_RANGE,
  KC_SPAMRMB,
  KC_THIS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT(
            KC_GRV,  KC_1,    KC_2,               KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
            KC_TAB,  KC_Q,    KC_W,               KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
            KC_ESC,  KC_A,    KC_S,               KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,               KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
            KC_LCTL, KC_LGUI, LCTL(LSFT(KC_GRV)), KC_LALT, MO(4),   KC_SPC,  MO(5),   KC_RALT, KC_TRNS, KC_MPLY, KC_PSCR, KC_RCTL,
                              KC_LALT,            KC_MUTE, KC_VOLD, KC_VOLU, KC_5,    KC_SPC
        ),
        [1] = LAYOUT(
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
            KC_TAB,  KC_R,    KC_Q,    KC_W,    KC_E,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
            KC_ESC,  KC_F,    KC_A,    KC_S,    KC_D,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LSFT_T(KC_ENT),
            KC_LCTL, KC_LGUI, KC_MYCM, KC_LALT, MO(4),   KC_SPC,  MO(5),   KC_RALT, KC_SPC,  KC_MPLY, KC_PSCR, KC_RCTL,
                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
        [2] = LAYOUT(
            KC_GRV,  KC_1,    KC_2,         KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0, KC_BSPC,
            KC_TAB,  KC_Q,    KC_W,         KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,       KC_P, KC_DEL,
            KC_ESC,  KC_A,    KC_S,         KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,         KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH, LSFT_T(KC_ENT),
            KC_LCTL, KC_LGUI, KC_SPAMSPACE, KC_LALT, MO(3),   KC_SPC,  MO(5),   KC_RALT, KC_SPC,  KC_SPAMRMB, KC_PSCR, KC_RCTL,
                              KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
        [3] = LAYOUT(
            KC_GRV, KC_1,   KC_2,  KC_3,   KC_4,    KC_5,    KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
            KC_6,   KC_7,   KC_8,  KC_9,   KC_0,    KC_MINS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
            KC_F1,  KC_F2,  KC_F3, KC_F4,  KC_F5,   KC_F6,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
            KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
            KC_LCTL, KC_NO, KC_NO, KC_NO,  KC_TRNS, KC_NO,   MO(5),   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
        [4] = LAYOUT(
            LSA(KC_GRAVE), LSA(KC_1),  LSA(KC_2),  LSA(KC_3),    LSA(KC_4),    LSA(KC_5), KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
            KC_TAB,        KC_LBRC,    KC_RBRC,    KC_LT,        KC_GT,        KC_AMPR,   KC_PIPE, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_EQL,
            KC_ESC,        KC_LCBR,    KC_RCBR,    KC_LPRN,      KC_RPRN,      KC_MINS,   KC_UNDS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_PLUS,
            KC_LSFT,       C(S(KC_F)), C(S(KC_N)), RALT(KC_INS), LALT(KC_INS), KC_DLR,    KC_THIS, KC_EQL,  KC_PLUS, KC_PAST, KC_BSLS, KC_ENT,
            KC_LCTL,       KC_LGUI,    KC_TRNS,    KC_LALT,      KC_TRNS,      KC_SPC,    MO(5),  KC_RALT, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT,
                                       KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS, KC_TRNS
        ),
        [5] = LAYOUT(
            KC_F1,       KC_F2,       KC_F3,       KC_F4,        KC_F5,        KC_F6,        KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,
            KC_F7,       KC_F8,       KC_F9,       KC_F10,       KC_F11,       KC_F12,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            LSFT(KC_F1), LSFT(KC_F2), LSFT(KC_F3), LSFT(KC_F4),  LSFT(KC_F5),  LSFT(KC_F6),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            LSFT(KC_F7), LSFT(KC_F8), LSFT(KC_F9), LSFT(KC_F10), LSFT(KC_F11), LSFT(KC_F12), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,      MO(6),        KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS,     KC_F16,      KC_F14,        KC_F15,       KC_TRNS, KC_TRNS
        ),
        [6] = LAYOUT(
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
            KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, DF(0),   DF(2),
            KC_TRNS, KC_TRNS, MU_MOD,  AU_ON,   AU_OFF,   KC_TRNS,  KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, DF(1),   KC_WH_U,
            KC_TRNS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,   MI_ON,    MI_OFF,  RGB_TOG, KC_BTN3, KC_TRNS, KC_TRNS, KC_WH_D,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                              KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
        )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_SPAMSPACE:
        if (record->event.pressed) {
            spam_space ^= 1;
            spam_timer = timer_read();
        }
        return false;
        break;
    case KC_SPAMRMB:
        if (record->event.pressed) {
            spam_rmb ^= 1;
            spam_rmb_timer = timer_read();
        }
        return false;
        break;
    case KC_THIS:
        if (record->event.pressed) {
            SEND_STRING("$this->");
        }
        return false;
        break;
    }

    return true;
}

void matrix_scan_user(void) {
    if (spam_space && timer_elapsed(spam_timer) >= spam_interval) {
         spam_timer = timer_read();
         spam_interval = 50 + (rand() % 50);
         SEND_STRING(SS_TAP(X_SPACE));
    }
    if (spam_rmb && timer_elapsed(spam_rmb_timer) >= spam_rmb_interval) {
         spam_rmb_timer = timer_read();
         SEND_STRING(SS_TAP(X_MS_BTN2));
    }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=false;
  //debug_keyboard=true;
  debug_mouse=true;
}
