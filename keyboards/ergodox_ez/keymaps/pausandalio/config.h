/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define ORYX_CONFIGURATOR
#define RGBLIGHT_SLEEP
#define DYNAMIC_MACRO_NO_NESTING
#define DYNAMIC_MACRO_SIZE 256

#ifdef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_MAX_SPEED
#endif
#define MOUSEKEY_MAX_SPEED 6
