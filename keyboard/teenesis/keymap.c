/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "bootloader.h"
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


#define KEYMAP(                                                                         \
    /* spatial positions */                                                             \
    k40,k41,k42,k43,k44,k45,                                k46,k47,k48,k49,k4A,k4B,    \
    k30,k31,k32,k33,k34,k35,                                k36,k37,k38,k39,k3A,k3B,    \
    k20,k21,k22,k23,k24,k25,                                k26,k27,k28,k29,k2A,k2B,    \
    k10,k11,k12,k13,k14,k15,    k53,k63,        k59,k6B,    k16,k17,k18,k19,k1A,k1B,    \
        k01,k02,k03,k05,    k54,k51,k64,        k5B,k67,k68,    k06,k08,k09,k0A,        \
                                    k62,        k58                                     \
    )                                                                                   \
    /* matrix positions */                                                              \
    {                                                                                   \
     { KC_NO   ,KC_##k10,KC_##k20,KC_##k30,KC_##k40,KC_NO   ,KC_NO   },                 \
     { KC_##k01,KC_##k11,KC_##k21,KC_##k31,KC_##k41,KC_##k51,KC_NO   },                 \
     { KC_##k02,KC_##k12,KC_##k22,KC_##k32,KC_##k42,KC_NO   ,KC_##k62},                 \
     { KC_##k03,KC_##k13,KC_##k23,KC_##k33,KC_##k43,KC_##k53,KC_##k63},                 \
     { KC_NO   ,KC_##k14,KC_##k24,KC_##k34,KC_##k44,KC_##k54,KC_##k64},                 \
     { KC_##k05,KC_##k15,KC_##k25,KC_##k35,KC_##k45,KC_NO   ,KC_NO   },                 \
     { KC_##k06,KC_##k16,KC_##k26,KC_##k36,KC_##k46,KC_NO   ,KC_NO   },                 \
     { KC_NO   ,KC_##k17,KC_##k27,KC_##k37,KC_##k47,KC_NO   ,KC_##k67},                 \
     { KC_##k08,KC_##k18,KC_##k28,KC_##k38,KC_##k48,KC_##k58,KC_##k68},                 \
     { KC_##k09,KC_##k19,KC_##k29,KC_##k39,KC_##k49,KC_##k59,KC_NO   },                 \
     { KC_##k0A,KC_##k1A,KC_##k2A,KC_##k3A,KC_##k4A,KC_NO   ,KC_NO   },                 \
     { KC_NO   ,KC_##k1B,KC_##k2B,KC_##k3B,KC_##k4B,KC_##k5B,KC_##k6B},                 \
    }

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Layer0
KEYMAP(
    NO  , NO  , NO  , NO  , NO  , NO  ,                                           NO  , NO  , NO  , NO  , NO  , NO,
    DEL , BSPC, D   , R   , W   , B   ,                                           J   , F   , U   , P   , LBRC, RBRC,
    Q   , A   , S   , FN3 , T   , G   ,                                           Y   , N   , E   , O   , I   , QUOT,
    FN8 , Z   , X   , M   , C   , V   ,       INS , 2   ,       RALT, HOME,       K   , L   , COMM, DOT , SLSH, FN9 ,
          LALT, FN20, TAB , FN24,       FN4 , FN2 , 1   ,       RGUI, FN22, FN1 ,       LEFT, UP  , DOWN, RGHT,
                                                    FN7 ,       RCTL
),

// Layer1 - original Kinesis
KEYMAP(
    EQL , 0   , 1   , 2   , 3   , 4   ,                                           5   , 6   , 7   , 8   , 9   , MINS,
    TAB , Q   , W   , E   , R   , T   ,                                           Y   , U   , I   , O   , P   , BSLS,
    CAPS, A   , S   , D   , F   , G   ,                                           H   , J   , K   , L   , SCLN, QUOT,
    LSFT, Z   , X   , C   , V   , B   ,       LCTL, LALT,       RGUI, RCTL,       N   , M   , COMM, DOT , SLSH, RSFT,
          GRV , BSLS, LEFT, RGHT,       BSPC, DEL , HOME,       PGUP, ENT , FN1 ,       UP  , DOWN, LBRC, RBRC,
                                                    END ,       PGDN
),

// Layer2
KEYMAP(
    NO  , NO  , NO  , NO  , NO  , NO  ,                                           NO  , NO  , NO  , NO  , NO  , NO,
    TRNS, DEL , F7  , F12 , F11 , F1  ,                                           TRNS, TRNS, 4   , 5   , TRNS, TRNS,
    TRNS, F10 , F2  , TRNS, F4  , F3  ,                                           3   , 1   , 0   , 2   , 7   , EQL ,
    TRNS, F9  , F8  , F6  , F5  , TRNS,       PSCR, F18 ,       TRNS, PGUP,       6   , 9   , 8   , TRNS, TRNS, PPLS,
          TRNS, TRNS, SPC , TRNS,       FN21, TRNS, FN0 ,       TRNS, FN23, TRNS,       HOME, PGUP, PGDN, END ,
                                                    MINS,       TRNS
),

// Layer3
KEYMAP(
    NO  , NO  , NO  , NO  , NO  , NO  ,                                           NO  , NO  , NO  , NO  , NO  , NO  ,
    TRNS, DEL , F7  , F12 , F11 , F1  ,                                           TRNS, TRNS, FN14, FN15, TRNS, TRNS,
    FN31, F10 , F2  , TRNS, F4  , F3  ,                                           FN13, FN11, FN10, FN12, FN17, EQL ,
    TRNS, F9  , F8  , F6  , F5  , TRNS,       TRNS, F18 ,       TRNS, PGDN,       FN16, FN19, FN18, TRNS, TRNS, PPLS,
          TRNS, TRNS, SPC , TRNS,       FN21, TRNS, FN0 ,       TRNS, FN23, TRNS,       HOME, PGUP, PGDN, END ,
                                                    MINS,       TRNS
),

};

#define MACRO_JIRA_NOFORMAT                                 \
        MACRO(                                              \
            I(15),                                          \
            D(LSFT), T(LBRC), U(LSFT),                      \
            T(N), T(O), T(F), T(O), T(R), T(M), T(A), T(T), \
            D(LSFT), T(RBRC), U(LSFT),                      \
            T(ENT),                                         \
        END)

#define MACRO_JIRA_QUOTE                                    \
        MACRO(                                              \
            I(15),                                          \
            D(LSFT), T(LBRC), U(LSFT),                      \
            T(Q), T(U), T(O), T(T), T(E),                   \
            D(LSFT), T(RBRC), U(LSFT),                      \
            T(ENT),                                         \
        END)

#define MACRO_C_COMMENT                                     \
        MACRO(                                              \
            I(15),                                          \
            T(SLSH), D(LSFT), T(8), U(LSFT),                \
            T(SPC), T(SPC),                                 \
            D(LSFT), T(8), U(LSFT), T(SLSH),                \
            T(LEFT), T(LEFT), T(LEFT),                      \
        END)

/* id for user defined functions and macros */
enum function_id {
    TEENSY_KEY,
};

enum macro_id {
    JIRA_NOFORMAT,
    JIRA_QUOTE,
    C_COMMENT,
};

/* user defined functions implementation */
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

/* user defined macros implementation */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
            case JIRA_NOFORMAT:  return MACRO_JIRA_NOFORMAT;
            case JIRA_QUOTE:     return MACRO_JIRA_QUOTE;
            case C_COMMENT:      return MACRO_C_COMMENT;
        }
    }
    return MACRO_NONE;
}

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [ 0] = ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key - reboot to programmator mode
    // [ 1] = ACTION_LAYER_MOMENTARY(1),
    [ 1] = ACTION_LAYER_TAP_KEY(3, KC_SPC),
    [ 2] = ACTION_LAYER_TAP_KEY(2, KC_ESC),
    [ 3] = ACTION_LAYER_TAP_KEY(2, KC_H),
    // [ 4] = ACTION_LAYER_TOGGLE(1),
    [ 4] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ENT),
    // [ 5] = ACTION_MODS_KEY(MOD_LGUI | MOD_LSFT, KC_0),
    // [ 6] = ACTION_MODS_KEY(MOD_LALT | MOD_LSFT, KC_V),
    [ 7] = ACTION_MODS_KEY(MOD_LGUI, KC_Z), // UNDO shortcut
    // [ 8] = ACTION_MODS(MOD_LALT | MOD_LGUI | MOD_LCTL),
    [ 8] = ACTION_MODS_TAP_KEY(MOD_LALT | MOD_LGUI | MOD_LCTL, KC_SCLN), // META combo MOD_LALT | MOD_LGUI | MOD_LCTL
    [ 9] = ACTION_MODS_TAP_KEY(MOD_LALT | MOD_LGUI | MOD_LCTL, KC_MINS), // META combo MOD_LALT | MOD_LGUI | MOD_LCTL

    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_9),

    [20] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_GRV),
    [21] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_F16),
    [22] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_BSLS),
    [23] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_F17),
    [24] = ACTION_MODS_ONESHOT(MOD_LGUI),
    // [25] = ACTION_MODS_KEY(MOD_LGUI, KC_ENT),

    // [29] = ACTION_MACRO(C_COMMENT),
    // [30] = ACTION_MODS_KEY(MOD_LCTL|MOD_LALT|MOD_LGUI, KC_F), // ACTION_MACRO(JIRA_NOFORMAT),
    // [31] = ACTION_MODS_KEY(MOD_LCTL|MOD_LALT|MOD_LGUI, KC_Q), // ACTION_MACRO(JIRA_QUOTE),
    [31] = ACTION_LAYER_TOGGLE(1),
};

#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, key_t key)
{
    if (layer < KEYMAPS_SIZE) {
        return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
    } else {
        // fall back to layer 0
        return pgm_read_byte(&keymaps[0][(key.row)][(key.col)]);
    }
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    action_t action;
    if (FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    } else {
        action.code = ACTION_NO;
    }
    return action;
}

