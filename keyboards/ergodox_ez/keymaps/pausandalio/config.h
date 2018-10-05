/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define RGBLIGHT_COLOR_LAYER_0 0x33, 0x33, 0x33
#define RGBLIGHT_COLOR_LAYER_1 0xFF, 0x00, 0x00
#define RGBLIGHT_COLOR_LAYER_2 0x00, 0xFF, 0x00
#define RGBLIGHT_COLOR_LAYER_3 0x00, 0x00, 0xFF

#define RGBLIGHT_SLEEP
#define TAPPING_TERM 200

#ifdef MOUSEKEY_DELAY
#undef MOUSEKEY_DELAY
#endif
#ifdef MOUSEKEY_INTERVAL
#undef MOUSEKEY_INTERVAL
#endif
#ifdef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_TIME_TO_MAX
#endif
#ifdef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_MAX_SPEED
#endif
#ifdef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_WHEEL_DELAY
#endif
#ifdef MOUSEKEY_WHEEL_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#endif

#define MOUSEKEY_DELAY             25
#define MOUSEKEY_INTERVAL          20
#define MOUSEKEY_TIME_TO_MAX       60
#define MOUSEKEY_MAX_SPEED         4
#define MOUSEKEY_WHEEL_DELAY       50
#define MOUSEKEY_WHEEL_TIME_TO_MAX 60
