#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

#define BASE  0 // default layer
#define SYMB  1 // symbols & numbers
#define MOUSE 2 // mouse keys
#define FUNCT 3 // fn keys

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

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  HSV_240_255_255,
  HSV_120_255_128,
  HSV_38_255_255,
  HSV_300_255_128,
  HSV_0_255_255,
};

enum {
  TD_PAREN = 0
};

void dance_paren_finished (qk_tap_dance_state_t *state, void *user_data) {
  register_code (KC_RSFT);

  if (state->count == 1) {
    register_code (KC_9);
  } else {
    register_code (KC_0);
  }
}

void dance_paren_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code (KC_RSFT);

  if (state->count == 1) {
    unregister_code (KC_9);
  } else {
    unregister_code (KC_0);
  }
};

//All tap dance functions would go here.
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_PAREN]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_paren_finished, dance_paren_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------------------.          ,---------------------------------------------------------.
 * |    `    |   1   |   2   |   3   |   4   |   5   | VolDn |          | VolUp |   6   |   7   |   8   |   9   |   0   |   <=    |
 * |---------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+---------|
 * |  Del    |   Q   |   W   |   E   |   R   |   T   |   {   |          |   }   |   Y   |   U   |   I   |   O   |   P   |    +    |
 * |---------+-------+-------+-------+-------+-------|       |          |       |-------+-------+-------+-------+-------+---------|
 * | <=/Ctrl |   A   |   S   |   D   | F/ L1 | G/ L2 |-------|          |-------| H/ L2 | J/ L1 |   K   |   L   |   :   | =/Ctrl  |
 * |---------+-------+-------+-------+-------+-------|   [   |          |   ]   |-------+-------+-------+-------+-------+---------|
 * |  AltGr  |   Z   |   X   |   C   | V/Win |   B   |       |          |       |   N   | M/Win |   ,   |   .   |   /   |  AltGr  |
 * `---------+-------+-------+-------+-------+---------------'          `---------------+-------+-------+-------+-------+---------'
 *   | Home  | PgUp  |  L3   |  L2   |  L1   |                                          |   [   |   ]   |MdaPlay|PgDown |  End  |
 *   `---------------------------------------'                                          `---------------------------------------'
 *                                           ,---------------.          ,---------------.
 *                                           | Left  | Right |          | Down  |  Up   |
 *                                   ,-------|-------|-------|          |-------+-------+-------.
 *                                   |  Tab  | Caps  | Mute  |          |SysReq | Enter | Space |
 *                                   |   /   |   /   |-------|          |-------|   /   |   /   |
 *                                   | Shift |  Alt  |  ESC  |          |  ESC  |  Alt  | Shift |
 *                                   `-----------------------'          `-----------------------'
 */
  [BASE] = LAYOUT_ergodox(
      // LEFT HAND ---------------------------------------------------------------------------------
      KC_GRAVE,         KC_1,    KC_2,  KC_3,  KC_4,        KC_5, KC_AUDIO_VOL_DOWN,
      KC_DELETE,        KC_Q,    KC_W,  KC_E,  KC_R,        KC_T, KC_LCBR,
      CTL_T(KC_BSPACE), KC_A,    KC_S,  KC_D,  LT(1,KC_F),  LT(2,KC_G),
      KC_RALT,          KC_Z,    KC_X,  KC_C,  GUI_T(KC_V), KC_B, KC_LBRACKET,
      KC_HOME,          KC_PGUP, TT(3), TT(2), TT(1),
                                                                      KC_LEFT, KC_RIGHT,
                                                                               KC_AUDIO_MUTE,
                                           LSFT_T(KC_TAB), ALT_T(KC_CAPSLOCK), KC_ESCAPE,

                                                                                                 // RIGHT HAND ---------------------------------------------------------------------------------------------------------------
                                                                                                                      KC_AUDIO_VOL_UP, KC_6,       KC_7,         KC_8,        KC_9,                KC_0,      KC_BSPACE,
                                                                                                                      KC_RCBR,         KC_Y,       KC_U,         KC_I,        KC_O,                KC_P,      KC_PLUS,
                                                                                                                                       LT(2,KC_H), LT(1,KC_J),   KC_K,        KC_L,                KC_COLN,   CTL_T(KC_EQUAL),
                                                                                                                      KC_RBRACKET,     KC_N,       RGUI_T(KC_M), KC_COMMA,    KC_DOT,              KC_SLASH,  KC_RALT,
                                                                                                                                                   KC_LBRACKET,  KC_RBRACKET, KC_MEDIA_PLAY_PAUSE, KC_PGDOWN, KC_END,
                                                                                                  KC_DOWN,    KC_UP,
                                                                                                  KC_PSCREEN,
                                                                                                  KC_ESCAPE,  ALT_T(KC_ENTER), RSFT_T(KC_SPACE)),

/* Keymap 1: Symbols and numbers
 *
 * ,---------------------------------------------------------.          ,---------------------------------------------------------.
 * |    ^    |   \   |   /   |   |   |   =   |   +   |   *   |          |       |       |   ,   |   0   |   .   |       |         |
 * |---------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+---------|
 * |    ¿    |   ?   |   ;   |   &   |   -   |   "   |       |          |       |       |   7   |   8   |   9   |       |         |
 * |---------+-------+-------+-------+-------+-------|       |          |       |-------+-------+-------+-------+-------+---------|
 * |    ¡    |   !   |   @   |  (/)  |   _   |   '   |-------|          |-------|       |   4   |   5   |   6   |       |         |
 * |---------+-------+-------+-------+-------+-------|       |          |       |-------+-------+-------+-------+-------+---------|
 * |         |   ~   |   #   |   $   |   %   |   `   |       |          |       |       |   1   |   2   |   3   |       |         |
 * `---------+-------+-------+-------+-------+---------------'          `---------------+-------+-------+-------+-------+---------'
 *   |       |       |  L0   |  L0   |  L0   |                                          |   ,   |   0   |   .   |       |       |
 *   `---------------------------------------'                                          `---------------------------------------'
 *                                           ,---------------.          ,---------------.
 *                                           |       |       |          |       |       |
 *                                   ,-------|-------|-------|          |-------+-------+-------.
 *                                   |       |       |       |          |       |       |       |
 *                                   |       |       |-------|          |-------|       |       |
 *                                   |       |       |  L0   |          |       |       |       |
 *                                   `-----------------------'          `-----------------------'
 */
  [SYMB] = LAYOUT_ergodox(
      // LEFT HAND ----------------------------------------------------------------------------------
      KC_CIRC,        KC_BSLASH,      KC_SLASH,  KC_PIPE,      KC_EQUAL,    KC_PLUS,  KC_ASTR,
      RALT(KC_SLASH), KC_QUES,        KC_SCOLON, KC_AMPR,      KC_KP_MINUS, KC_DQUO,  KC_TRANSPARENT,
      RALT(KC_1),     KC_EXLM,        KC_AT,     TD(TD_PAREN), KC_UNDS,     KC_QUOTE,
      KC_TRANSPARENT, KC_TILD,        KC_HASH,   KC_DLR,       KC_PERC,     KC_GRAVE, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, TO(0),     TO(0),        TO(0),
                                                                      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                      KC_TRANSPARENT,
                                                      KC_TRANSPARENT, KC_TRANSPARENT, TO(0),

                                                                                                 // RIGHT HAND -------------------------------------------------------------------------------------------------
                                                                                                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_COMMA, KC_0, KC_KP_DOT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_7,     KC_8, KC_9,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                                      KC_TRANSPARENT, KC_4,     KC_5, KC_6,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_1,     KC_2, KC_3,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                                                      KC_COMMA, KC_0, KC_KP_DOT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

/* Keymap 2: Mouse control and arrows
 *
 * ,---------------------------------------------------------.          ,---------------------------------------------------------.
 * |         |       |       |       |       |       |MdaPrev|          |MdaNext|       |       |MClick |       |       |         |
 * |---------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+---------|
 * |         |       |       |  Up   |       |       | VolDn |          | VolUp |       |LClick | MsUp  |RClick | MWhUp |         |
 * |---------+-------+-------+-------+-------+-------|       |          |       |-------+-------+-------+-------+-------+---------|
 * |         |       | Left  | Down  | Right |       |-------|          |-------|       |MsLeft |MsDown |MsRight|MWhDown|         |
 * |---------+-------+-------+-------+-------+-------|MdaStop|          |MdaPlay|-------+-------+-------+-------+-------+---------|
 * |         |       |       |       |       |       |       |          |       |       |       |       |       |       |         |
 * `---------+-------+-------+-------+-------+---------------'          `---------------+-------+-------+-------+-------+---------'
 *   |       |       |  L0   |  L0   |  L0   |                                          |  L0   |  L0   |  L0   |       |       |
 *   `---------------------------------------'                                          `---------------------------------------'
 *                                           ,---------------.          ,---------------.
 *                                           |       |       |          |       |       |
 *                                   ,-------|-------|-------|          |-------+-------+-------.
 *                                   |       |       |       |          |       |       |       |
 *                                   |       |       |-------|          |-------|RClick |LClick |
 *                                   |       |       |  L0   |          |       |       |       |
 *                                   `-----------------------'          `-----------------------'
 */
  [MOUSE] = LAYOUT_ergodox(
      // LEFT HAND -------------------------------------------------------------------------------------------------------
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,   KC_MEDIA_STOP,
      KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          TO(0),          TO(0),
                                                                      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                      KC_TRANSPARENT,
                                                      KC_TRANSPARENT, KC_TRANSPARENT, TO(0),

                                                                                                 // RIGHT HAND ----------------------------------------------------------------------------------------------------------------------
                                                                                                                      KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                      KC_AUDIO_VOL_UP,     KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,   KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT,
                                                                                                                                           KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN, KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_TRANSPARENT,
                                                                                                                      KC_MEDIA_PLAY_PAUSE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                                                           TO(0),          TO(0),          TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_MS_BTN2, KC_MS_BTN1),


/* Keymap 3: Function keys and colors
 *
 * ,---------------------------------------------------------.          ,---------------------------------------------------------.
 * |  Blue   | Green |Orange |Purple |  Red  |       |       |          |       |       |  F10  |  F11  |  F12  |       |         |
 * |---------+-------+-------+-------+-------+-------+-------|          |-------+-------+-------+-------+-------+-------+---------|
 * |         |       |       | Hue-  | Hue+  |       |       |          |       |       |  F7   |  F8   |  F9   |       |         |
 * |---------+-------+-------+-------+-------+-------|       |          |       |-------+-------+-------+-------+-------+---------|
 * |         |       |       |Bright-|Bright+|       |-------|          |-------|       |  F4   |  F5   |  F6   |       |         |
 * |---------+-------+-------+-------+-------+-------|       |          |       |-------+-------+-------+-------+-------+---------|
 * |         |       |       |AnimNo |AnimSt |       |       |          |       |       |  F1   |  F2   |  F3   |       |         |
 * `---------+-------+-------+-------+-------+---------------'          `---------------+-------+-------+-------+-------+---------'
 *   |       |       |  L0   |  L0   |  L0   |                                          |  L0   |  L0   |  L0   |       |       |
 *   `---------------------------------------'                                          `---------------------------------------'
 *                                           ,---------------.          ,---------------.
 *                                           |       |       |          |       |       |
 *                                   ,-------|-------|-------|          |-------+-------+-------.
 *                                   |Toggle |       |       |          |       |       |       |
 *                                   | RGB   |       |-------|          |-------|       |       |
 *                                   |       |       |  L0   |          |       |       |       |
 *                                   `-----------------------'          `-----------------------'
 */
  [FUNCT] = LAYOUT_ergodox(
      // LEFT HAND ----------------------------------------------------------------------------------
      HSV_240_255_255, HSV_120_255_128, HSV_38_255_255, HSV_300_255_128, HSV_0_255_255, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_HUD, RGB_HUI, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_VAD, RGB_VAI, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SLD, RGB_MOD, KC_TRANSPARENT, KC_TRANSPARENT,
      KC_TRANSPARENT, KC_TRANSPARENT, TO(0), TO(0), TO(0),
                                                                      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                      KC_TRANSPARENT,
                                                             RGB_TOG, KC_TRANSPARENT, TO(0),

                                                                                                 // RIGHT HAND ----------------------------------------------------------------------------------------------------------------------
                                                                                                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_F10, KC_F11, KC_F12, KC_TRANSPARENT, KC_SYSTEM_POWER,
                                                                                                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_F7,  KC_F8,  KC_F9,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                                      KC_TRANSPARENT, KC_F4,  KC_F5,  KC_F6,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,  KC_F2,  KC_F3,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                                                      TO(0),  TO(0),  TO(0),  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

    case HSV_240_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(240,255,255);
        #endif
      }
      return false;
      break;

    case HSV_120_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(120,255,128);
        #endif
      }
      return false;
      break;

    case HSV_38_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(38,255,255);
        #endif
      }
      return false;
      break;

    case HSV_300_255_128:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(300,255,128);
        #endif
      }
      return false;
      break;

    case HSV_0_255_255:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_sethsv(0,255,255);
        #endif
      }
      return false;
      break;

  }
  return true;
}

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();

    rgblight_setrgb_at(255, 255, 0, 13);
    rgblight_setrgb_at(255, 255, 0, 14);
  } else {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    if (biton32(layer_state) == 0) {
      rgblight_setrgb_at(RGBLIGHT_COLOR_LAYER_0, 13);
      rgblight_setrgb_at(RGBLIGHT_COLOR_LAYER_0, 14);
    }

    if (biton32(layer_state) == 1) {
      ergodox_right_led_1_on();

      rgblight_setrgb_at(RGBLIGHT_COLOR_LAYER_1, 13);
      rgblight_setrgb_at(RGBLIGHT_COLOR_LAYER_1, 14);
    }

    if (biton32(layer_state) == 2) {
      ergodox_right_led_2_on();

      rgblight_setrgb_at(RGBLIGHT_COLOR_LAYER_2, 13);
      rgblight_setrgb_at(RGBLIGHT_COLOR_LAYER_2, 14);
    }

    if (biton32(layer_state) == 3) {
      ergodox_right_led_3_on();

      rgblight_setrgb_at(RGBLIGHT_COLOR_LAYER_3, 13);
      rgblight_setrgb_at(RGBLIGHT_COLOR_LAYER_3, 14);
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
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};

void suspend_wakeup_init_user(void) {
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
}
