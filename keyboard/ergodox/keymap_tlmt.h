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
ESC , 1   , 2   , 3   , 4   , 5   , MINS,                                       EQL , 6   , 7   , 8   , 9   , 0   , BSPC,
TAB , Q   , W   , E   , R   , T   , FN2 ,                                       LBRC, Y   , U   , I   , O   , P   , QUOT,
ESC , A   , S   , D   , F   , G   ,                                                   H   , J   , K   , L   , SCLN, ENT ,
LSFT, Z   , X   , C   , V   , B   , FN1 ,       GRV , LALT,   LBRC, RBRC,       FN3 , N   , M   , COMM, DOT , SLSH, RSFT,
LGUI, LCTL, BSLS, LGUI, LALT,             SPC , FN5 , HOME,   PGUP, ENT , SPC ,             RGUI, LEFT, DOWN, UP  , RGHT,
                                                      END ,   PGDN
),

// Layer_01: FX + media keyes
KEYMAP(
PWR , F1  , F2  , F3  , F4  , F5  , F11 ,                                       F12 , F6  , F7  , F8  , F9  , F10 , TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, FN4 ,                                       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,                                                   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS,   VOLD, VOLU,       TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
TRNS, TRNS, TRNS, TRNS, TRNS,             TRNS, TRNS, TRNS,   TRNS, TRNS, TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS,
                                                      TRNS,   TRNS
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
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [ 0] = ACTION_FUNCTION(TEENSY_KEY),                                     // FN0 - Teensy key

    [ 1] = ACTION_LAYER_MOMENTARY(1),                                       // FN1 - switch to Layer_01
    [ 2] = ACTION_LAYER_SET(2, ON_PRESS),                                   // FN2 - set Layer_02
    [ 3] = ACTION_LAYER_TOGGLE(3),                                          // FN3 - toggle Layer_03 aka Numpad layer
    [ 4] = ACTION_LAYER_SET(0, ON_PRESS),                                   // FN4 - set Layer_00

    [ 5] = ACTION_MODS_TAP_KEY(MOD_LALT | MOD_LGUI | MOD_LCTL, KC_BSPC),    // FN5
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
