
/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define FUNC 3 // function / admin
#define PLVR 4 // plover

/* Combomap
 *
 * ,-------------------------------.      ,--------------------------------.
 * |      |    ESC    |     |      |      |     |    ESC    |    BSLH      |
 * |------+-----+-----+-----+------|      |--------------------------------|
 * |      |   BSPC   ENT    |      |      |    LES   COLN  GRT    |        |
 * |------+-----+-----+--RMB+-LMB--+      |--------------------------------|
 * |      |   MINS    |     |      |      |    QUO   UNDR   |     |        |
 * `------+-----+-----+------+-----'      `--------------------------------'
 *  .-------------------------.           .-----------------.
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------'
 */



// PL Base Layer START

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,------------------------------.      ,--------------------------------.
 * |    ' |  ,  |  .  |  P  |  Y  |      |  F  |  G  |  C  |  R  |    L   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |CTRL/A|  O  |  E  |  U  |  I  |      |  D  |  H  |  T  |  N  | CTRL/S |
 * |-----+-----+-----+-----+------+      |--------------------------------|
 * |SHFT/;|  Q  |  J  |  K  |  X  |      |  B  |  M  |  W  |  V  | SHFT/Z |
 * `------+-----+-----+------+----'      `--------------------------------'
 *  .----------------------------.           .---------------------.
 *  |ESC/META| SPC(NUM) | DELETE |           | BSPC | SPC(SYM) |TAB|
 *  '----------------------------'           '---------------------'
 */
[BASE] = LAYOUT_gergoplex(
    KC_QUOTE,  			 			 KC_COMMA, KC_DOT, KC_P, KC_Y,  	KC_F, KC_G, KC_C,    KC_R, 	 KC_L, 
    MT(MOD_LCTL, KC_A),KC_O, KC_E, KC_U, KC_I,  	KC_D, KC_H, KC_H,    KC_T, 	 MT(MOD_LCTL, KC_S),
    MT(MOD_LSFT, KC_SCLN),KC_Q, KC_J, KC_K, KC_X,  	KC_B, KC_M, KC_W, KC_V, MT(MOD_RSFT, KC_Z),

    MT(MOD_LGUI, KC_ESC), LT(NUMB, KC_SPC), KC_DEL,									// Left
		KC_BSPC, LT(SYMB, KC_SPC), MT(MOD_RSFT, KC_TAB)																// Right
    ),

// PL Base Layer END

/* Keymap 1: Symbols layer
 * ,------------------------------.      ,--------------------------------.
 * |  !  |  @  |  {  |  }  |      |      | `   |  ~  |     |     |    \   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |  #  |  $  |  (  |  )  |  LMB |      |  +  |  -  |  /  |  *  |    '   |
 * |-----+-----+-----+-----+------+      |--------------------------------|
 * |  %  |  ^  |  [  |  ]  |  RMB |      |  &  |  =  |  ,  |  .  |   -    |
 * `------+-----+-----+------+----'      `--------------------------------'
 *          .------------------.           .------------------.
 *          |MMB | FUNC |  =   |           |  =  |  ;  |  DEL |
 *          '------------------'           '------------------'
 */
[SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,   KC_GRV,  KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,   KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,   KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_MINS,
    CMB_TOG, TO(FUNC), KC_EQL,             KC_EQL,  KC_SCLN, KC_DEL
    ),


// PL Number Layer

/* Keymap 2: Num Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  *  |  7  |  8  |  9  |   /   |
 * |-----+-----+-----+-----+------|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      |  +  |  4  |  5  |  6  |   -   |
 * |-----+-----+-----+-----+------+      |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      |VOLUP|  1  |  2  |  3  | VOLDN |
 * `------+-----+-----+------+----'      `-------------------------------'
 *          .-----------------.           .--------------.
 *          | F11 | F12|      |           | FUNC |  0  |.|
 *          '-----------------'           '--------------'
 */
[NUMB] = LAYOUT_gergoplex(
    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,		 		KC_PAST,  	KC_7, 	 KC_8, 		KC_9, 	 KC_PSLS,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   		KC_PPLS, KC_4, KC_5,   KC_6, KC_PMNS,
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  		KC_VOLU, KC_1, KC_2, KC_3, KC_VOLD,
    KC_F11,KC_F12,KC_TRNS,  	                        TO(FUNC),KC_0,KC_DOT
			  ),

// PL Function Layer

/* Keymap 3: Function/Admin layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  *  |  7  |  8  |  9  | RESET |
 * |-----+-----+-----+-----+------|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      |  +  | PLV |  5  |  6  |   -   |
 * |-----+-----+-----+-----+------+      |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      |MLFT |  1  |  2  |  3  | VOLDN |
 * `------+-----+-----+------+----'      `-------------------------------'
 *          .-----------------.           .--------------.
 *          | F11 | F12|      |           | FUNC |  0  |.|
 *          '-----------------'           '--------------'
 */
[FUNC] = LAYOUT_gergoplex(
    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,		 		KC_PAST,  	KC_7, 	 KC_8, 		KC_9, 	 RESET,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   		KC_PPLS, TO(PLVR), KC_5,   KC_6, KC_PMNS,
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  		KC_MS_L, KC_1, KC_2, KC_3, KC_VOLD,
     						  KC_F11,KC_F12,KC_TRNS,  	KC_TRNS,KC_0,KC_DOT
			  ),

// PL Function Layer

/* Keymap 4: Plover layer
 * ,-----------------------------.      ,-------------------------------.
 * |  #  |  #  |  #  |  #  |  #  |      |  *  |  #  |  #  |  #  |   #   |
 * |-----+- ---+-----+-----+-----|      |-------------------------------|
 * |  Q  |  W  |  E  |  R  |  T  |      |  U  |  I  |  O  |  P  |   [   |
 * |-----+-----+-----+-----+-----+      |-------------------------------|
 * |  A  |  S  |  D  |  F  |  G  |      |  J |   K  |  L  |  ;  |   '   |
 * `-----+-----+-----+-----+-----'      `-------------------------------'
 *          .-----------------.           .---------------.
 *          | C |  V  | BASE  |           | BASE |  N  | M|
 *          '-----------------'           '---------------'
 */
[PLVR] = LAYOUT_gergoplex(
    KC_NUHS,  KC_NUHS,  KC_NUHS,  KC_NUHS,  KC_NUHS,		 		KC_T,  	KC_NUHS, 	 KC_NUHS, 		KC_NUHS, 	 KC_NUHS,
    KC_Q, KC_W, KC_E, KC_R, KC_T,   		KC_U, KC_I,   KC_O, KC_P, KC_LBRC,
    KC_A, KC_S, KC_D, KC_F, KC_G,  		KC_J, KC_K, KC_L, KC_SCLN,KC_QUOTE,
    KC_C,KC_V,TO(BASE),  	                        TO(BASE),KC_N,KC_M
			  )
};
