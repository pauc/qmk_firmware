#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum tap_dance_codes {
  DANCE_0,
};

/* Keymap template
 *
 * ,---------------------------------------------------------.          ,---------------------------------------------------------.
 * |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
 * |---------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+---------|
 * |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
 * |---------+-------+-------+-------+-------+-------|       |          |       |-------+-------+-------+-------+-------+---------|
 * |         |       |       |       |       |       |-------|          |-------|       |       |       |       |       |         |
 * |---------+-------+-------+-------+-------+-------|       |          |       |-------+-------+-------+-------+-------+---------|
 * |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
 * `---------+-------+-------+-------+-------+---------------'          `---------------+-------+-------+-------+-------+---------'
 *   |       |       |       |       |       |                                          |       |       |       |       |       |
 *   `---------------------------------------'                                          `---------------------------------------'
 *                                           ,---------------.          ,---------------.
 *                                           |       |       |          |       |       |
 *                                   ,-------|-------|-------|          |-------+-------+-------.
 *                                   |       |       |       |          |       |       |       |
 *                                   |       |       |-------|          |-------|       |       |
 *                                   |       |       |       |          |       |       |       |
 *                                   `-----------------------'          `-----------------------'
 */

#define BASE_MACOS  0 // Base layer for MaxOS
#define SYMB        1 // symbols & numbers

#define MOUSE       2 // mouse keys
#define FUNCT       3 // fn keys

/* ================================================================================================================================= */
/* ================================================================================================================================= */

/* Keymap 0: Base layer for Mac OSx
 *
 * ,---------------------------------------------------------.          ,---------------------------------------------------------.
 * | M_PLAY  |   1   |   2   |   3   |   4   |   5   | VolDn |          | VolUp |   6   |   7   |   8   |   9   |   0   |   <=    |
 * |---------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+---------|
 * |  Del    |   Q   |   W   |   E   |   R   |   T   |  MEH  |          |  MEH  |   Y   |   U   |   I   |   O   |   P   |    +    |
 * |---------+-------+-------+-------+-------+-------|       |          |       |-------+-------+-------+-------+-------+---------|
 * | <=:Ctrl |   A   |   S   |   D   | L1:F  | L2:G  |-------|          |-------| L2:H  | L1:J  |   K   |   L   |   :   | =:Ctrl  |
 * |---------+-------+-------+-------+-------+-------| HYPR  |          | HYPR  |-------+-------+-------+-------+-------+---------|
 * |  LAlt   |   Z   |   X   |   C   |   V   |   B   |       |          |       |   N   |   M   |   ,   |   .   |   /   |  Ralt   |
 * `---------+-------+-------+-------+-------+---------------'          `---------------+-------+-------+-------+-------+---------'
 *   | Home  | PgUp  |RC_MACR|PL_MACR|  L3   |                                          |   [   |   ]   |  L3   |PgDown |  End  |
 *   `---------------------------------------'                                          `---------------------------------------'
 *                                           ,---------------.          ,---------------.
 *                                           | Left  | Right |          | Down  |  Up   |
 *                                   ,-------|-------|-------|          |-------+-------+-------.
 *                                   |  Tab  |  Esc  | Mute  |          |  MEH  | Enter | Space |
 *                                   |   :   |   :   |-------|          |-------|   :   |   :   |
 *                                   | Shift |  Cmd  | CapsL |          | CapsL |  Cmd  | Shift |
 *                                   `-----------------------'          `-----------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE_MACOS] = LAYOUT_ergodox_pretty(
    KC_MEDIA_PLAY_PAUSE, KC_1,        KC_2,           KC_3,            KC_4,           KC_5,        KC_AUDIO_VOL_DOWN,                              KC_AUDIO_VOL_UP, KC_6,           KC_7,               KC_8,               KC_9,       KC_0,       KC_BSPACE,
    KC_DELETE,           KC_Q,        KC_W,           KC_E,            KC_R,           KC_T,        KC_MEH,                                         KC_MEH,          KC_Y,           KC_U,               KC_I,               KC_O,       KC_P,       KC_PLUS,
    LCTL_T(KC_BSPACE),   KC_A,        KC_S,           KC_D,            LT(1, KC_F),    LT(2, KC_G),                                                                  LT(2, KC_H),    LT(1, KC_J),        KC_K,               KC_L,       KC_COLN,    CTL_T(KC_EQUAL),
    KC_LALT,             KC_Z,        KC_X,           KC_C,            KC_V,           KC_B,        KC_HYPR,                                        KC_HYPR,         KC_N,           KC_M,               KC_COMMA,           KC_DOT,     KC_SLASH,   KC_RALT,
    KC_HOME,             KC_PGUP,     DYN_REC_START1, DYN_MACRO_PLAY1, TT(3),                                                                                                        KC_LBRACKET,        KC_RBRACKET,        TT(3),      KC_PGDOWN,  KC_END,
                                                                                                    KC_LEFT,  KC_RIGHT,                KC_DOWN,     KC_UP,
                                                                                                              KC_AUDIO_MUTE,           KC_MEH,
                                                                           SFT_T(KC_TAB), LGUI_T(KC_ESCAPE),  KC_CAPSLOCK,             KC_CAPSLOCK, RGUI_T(KC_ENTER), RSFT_T(KC_SPACE)
  ),
  [SYMB] = LAYOUT_ergodox_pretty(
    KC_CIRC,        KC_BSLASH,      KC_SLASH,       KC_PIPE,        KC_EQUAL,       KC_PLUS,        KC_ASTR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_TRANSPARENT,
    RALT(KC_SLASH), KC_QUES,        KC_SCOLON,      KC_AMPR,        KC_MINUS,       KC_DQUO,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_KP_PLUS,     KC_TRANSPARENT,
    RALT(KC_1),     KC_EXLM,        KC_AT,          TD(DANCE_0),    KC_UNDS,        KC_QUOTE,                                                                       KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_KP_EQUAL,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TILD,        KC_HASH,        KC_DLR,         KC_PERC,        KC_GRAVE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          TO(0),          TO(0),                                                                                                          KC_COMMA,       KC_0,           KC_KP_DOT,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MOUSE] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          TO(0),          TO(0),                                                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_BTN1
  ),
  [FUNCT] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          TO(0),          TO(0),                                                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    RGB_TOG,        RGB_MOD,        RGB_SLD,        SYSTEM_SLEEP,   KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
  }
  return true;
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
  } else {
    if (biton32(layer_state) == 0) {
      ergodox_right_led_1_off();
      ergodox_right_led_2_off();
      ergodox_right_led_3_off();
    }

    if (biton32(layer_state) == 1) {
      ergodox_right_led_1_on();
      ergodox_right_led_2_off();
      ergodox_right_led_3_off();
    }

    if (biton32(layer_state) == 2) {
      ergodox_right_led_1_off();
      ergodox_right_led_2_on();
      ergodox_right_led_3_off();
    }

    if (biton32(layer_state) == 3) {
      ergodox_right_led_1_off();
      ergodox_right_led_2_off();
      ergodox_right_led_3_on();
    }
  }
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    switch (layer) {
      case 0:
        if(!disable_layer_color) {
          rgblight_sethsv_noeeprom(0,0,150);
        }
        break;
      case 1:
        if(!disable_layer_color) {
          rgblight_sethsv_noeeprom(0,255,255);
        }
        break;
      case 2:
        if(!disable_layer_color) {
          rgblight_sethsv_noeeprom(70,255,160);
        }
        break;
      case 3:
        if(!disable_layer_color) {
          rgblight_sethsv_noeeprom(153,255,213);
        }
        break;
      default:
        if(!disable_layer_color) {
          rgblight_config.raw = eeconfig_read_rgblight();
          if(rgblight_config.enable == true) {
            rgblight_enable();
            rgblight_mode(rgblight_config.mode);
            rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
          }
          else {
            rgblight_disable();
          }
        }
        break;
    }
    return state;
};


void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_0_dance_step(qk_tap_dance_state_t *state);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RSFT(KC_9));
        tap_code16(RSFT(KC_9));
        tap_code16(RSFT(KC_9));
    }
    if(state->count > 3) {
        tap_code16(RSFT(KC_9));
    }
}

uint8_t dance_0_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_0_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(RSFT(KC_9)); break;
        case DOUBLE_TAP: register_code16(RSFT(KC_0)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RSFT(KC_9)); register_code16(RSFT(KC_9));
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(RSFT(KC_9)); break;
        case DOUBLE_TAP: unregister_code16(RSFT(KC_0)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RSFT(KC_9)); break;
    }
    dance_state.step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};
