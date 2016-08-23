static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
// Layer_XX: TRNS template
KEYMAP(
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                                   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS,   TRNS, TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS,             TRNS, TRNS, TRNS,   TRNS, TRNS, TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS,
                                                      TRNS,   TRNS
),
*/

// Layer_00: QUERTY
KEYMAP(
ESC  , 1   , 2   , 3   , 4   , 5   , MINS,                                       EQL , 6   , 7   , 8   , 9   , 0   , RBRC,
K    , Q   , E   , W   , R   , T   , H   ,                                       LBRC, Y   , U   , I   , O   , P   , BSLS,
TAB  , F   , LEFT, UP  , RGHT, G   ,                                                   H   , J   , K   , L   , SCLN, QUOT,
N    , Z   , X   , C   , V   , B   , J   ,     P   , U   ,   F11 , F12 ,         ENT , N   , M   , COMM, DOT , SLSH, RSFT,
LCTL , SCLN, BSLS, LALT, M   ,            SPC, FN9 , O   ,   PGUP, SPC , FN1 ,               RGUI, LEFT, DOWN, UP  , RGHT,
                                                     L   ,   PGDN
),

// Layer_01: FX + media keyes
KEYMAP(
EQL , 6   , 7   , 8   , 9   , 0   , RBRC,                                       F12 , F6  , F7  , F8  , F9  , F10 , TRNS,
F7  , F1  , F2  , F3  , F4  , F5  , TRNS,                                       FN0 , TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
F11 , F6  , A   , S   , D   , F7  ,                                                   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
F12 , FN11, FN12, FN13, FN14, FN15, TRNS,      F12 , F8  ,   MUTE, MPLY,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
Y   , U   , I   , O   , P   ,            TRNS, TRNS, F9  ,   VOLU, TRNS, TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS,
                                                     F10 ,   VOLD
),

// Layer_02: keyboard functions
KEYMAP(
FN0 , TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                       FN4 , TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                                   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS,   TRNS, TRNS,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS,             TRNS, TRNS, TRNS,   TRNS, TRNS, TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS,
                                                      TRNS,   TRNS
),

// Layer_03: Numpad
KEYMAP(
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                       TRNS, NLCK, PSLS, PAST, PAST, PMNS, BSPC,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                       TRNS, NO  , P7  , P8  , P9  , PMNS, BSPC,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                                   NO  , P4  , P5  , P6  , PPLS, PENT,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS,   TRNS, TRNS,       TRNS, NO  , P1  , P2  , P3  , PPLS, PENT,
TRNS, TRNS, TRNS, TRNS, TRNS,             TRNS, TRNS, TRNS,   TRNS, TRNS, TRNS,             P0  , PDOT, SLSH, PENT, PENT,
                                                      TRNS,   TRNS
),
};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
    DOUBLE_TAP_T,
    DOUBLE_TAP_G,
    DOUBLE_TAP_B,
};

enum macro_id {
  KEY_AND_CLICK_G,
  KEY_AND_CLICK_T,
  KEY_AND_CLICK_B,
};

#define WAIT_BEFORE_CLICK 40

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [ 0] = ACTION_FUNCTION(TEENSY_KEY),                                     // FN0 - Teensy key

    [ 1] = ACTION_LAYER_TAP_KEY(1, KC_ESC),

    [ 2] = ACTION_LAYER_SET(2, ON_PRESS),                                   // FN2 - set Layer_02
    [ 3] = ACTION_LAYER_TOGGLE(3),                                          // FN3 - toggle Layer_03 aka Numpad layer
    [ 4] = ACTION_LAYER_SET(0, ON_PRESS),                                   // FN4 - set Layer_00

    [ 5] = ACTION_MODS_TAP_KEY(MOD_LALT | MOD_LGUI | MOD_LCTL, KC_BSPC),    // FN5
    [ 8] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
    [ 9] = ACTION_MODS_ONESHOT(MOD_LSFT),

    [10] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC),

    [11] = ACTION_MODS_KEY(MOD_LCTL, KC_1),
    [12] = ACTION_MODS_KEY(MOD_LCTL, KC_2),
    [13] = ACTION_MODS_KEY(MOD_LCTL, KC_3),
    [14] = ACTION_MODS_KEY(MOD_LCTL, KC_4),
    [15] = ACTION_MODS_KEY(MOD_LCTL, KC_5),

    [21] = ACTION_FUNCTION_TAP(DOUBLE_TAP_T),
    [22] = ACTION_FUNCTION_TAP(DOUBLE_TAP_G),
    [23] = ACTION_FUNCTION_TAP(DOUBLE_TAP_B),

};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    print("id="); phex(id); print("\n");
    print("opt="); phex(opt); print("\n");
    if (record->event.pressed) print("P;"); else print("R;"); print("\n");
    print("Taps="); phex(record->tap.count); print("\n");
    if (record->tap.interrupted) print("i;"); print("\n");

    switch (id) {

      case TEENSY_KEY:
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
        break;

      case DOUBLE_TAP_T:
        double_tab(record, KC_T);
        break;
      case DOUBLE_TAP_G:
        double_tab(record, KC_G);
        break;
      case DOUBLE_TAP_B:
        double_tab(record, KC_B);
        break;
    }
}

void double_tab(keyrecord_t *record, int key) {
if (record->event.pressed) {
    if (record->tap.count > 1 && !record->tap.interrupted) {
        mousekey_on(KC_BTN1);
        mousekey_send();
    } else {
        register_code(key);
        send_keyboard_report();
    }
} else {
    if (record->tap.count > 1  && !(record->tap.interrupted)) {
      mousekey_off(KC_BTN1);
      mousekey_send();
    } else {
        unregister_code(key);
        send_keyboard_report();
    }
}
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
            case KEY_AND_CLICK_G:
                return (record->event.pressed ?
                      MACRO(T(G), W(WAIT_BEFORE_CLICK), T(BTN1), END) :
                      MACRO_NONE );
                break;
            case KEY_AND_CLICK_T:
                return (record->event.pressed ?
                      MACRO(T(T), W(WAIT_BEFORE_CLICK), T(BTN1), END) :
                      MACRO_NONE );
                break;
            case KEY_AND_CLICK_B:
                return (record->event.pressed ?
                      MACRO(T(B), W(WAIT_BEFORE_CLICK), T(BTN1), END) :
                      MACRO_NONE );
                break;
        }
    }
    return MACRO_NONE;
}
