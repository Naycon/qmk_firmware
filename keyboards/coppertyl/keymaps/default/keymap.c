/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum layers {
    _QWERTY = 0,
    _BRACKETS,
    _QUOTES,
    _SYMBOLS,
    _ARROWS,
    _NUMBERS,
};

#define MCTL_Q MT(MOD_LCTL, KC_Q)
#define MCTL_SPC MT(MOD_LCTL, KC_SPC)
#define MCTL_ENT MT(MOD_LCTL, KC_ENT)
#define MCMD_ESC MT(MOD_LGUI, KC_ESC)
#define MSFT_Z MT(MOD_LSFT, KC_Z)
#define MSFT_X MT(MOD_LSFT, KC_X)
#define LBRK_J LT(_BRACKETS, KC_J)
#define LQUO_K LT(_QUOTES, KC_K)
#define LSYM_L LT(_SYMBOLS, KC_L)
#define LARW_F LT(_ARROWS, KC_F)
#define LNUM_D LT(_NUMBERS, KC_D)
#define KC_NSONG KC_MEDIA_FAST_FORWARD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //|------------------------------------------------------|                        |------------------------------------------------------|
       MCTL_Q,    KC_W,       KC_E,      KC_R,      KC_T,                               KC_Y,      KC_U,      KC_I,     KC_O,      KC_P,   \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
        KC_A,     KC_S,     LNUM_D,     LARW_F,     KC_G,                               KC_H,      LBRK_J,   LQUO_K,   LSYM_L,    SE_OSLH, \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
       MSFT_Z,    MSFT_X,     KC_C,      KC_V,      KC_B,                               KC_N,      KC_M,     SE_AA,     SE_AE,     KC_DOT, \
  //|--------------------------------+----------+----------+----------|  |----------+----------+----------+--------------------------------|
                                        KC_LALT,  MCMD_ESC,  MCTL_SPC,     MCTL_ENT,  KC_BSPC,    KC_TAB  \
                                   //|--------------------------------|  |--------------------------------|
  ),
  [_BRACKETS] = LAYOUT( \
  //|------------------------------------------------------|                        |------------------------------------------------------|
       KC_NO,     KC_NO,    SE_LBRC,   SE_RBRC,    KC_NO,                              KC_NO,      KC_NO,   SE_QUES,   KC_EXLM,    KC_NO,  \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
    SE_LESS_MAC,SE_GRTR_MAC, SE_LPRN,  SE_RPRN,    KC_NO,                              KC_NO,      KC_NO, SE_LCBR_MAC,SE_RCBR_MAC, KC_NO,  \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
       KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,                              KC_NO,      KC_NO,    KC_NO,    KC_COMM,   KC_COMM, \
  //|--------------------------------+----------+----------+----------|  |----------+----------+----------+--------------------------------|
                                        KC_NO,     KC_NO,     KC_NO,         KC_NO,    KC_NO,      KC_NO  \
                                   //|--------------------------------|  |--------------------------------|
  ),
  [_QUOTES] = LAYOUT( \
  //|------------------------------------------------------|                        |------------------------------------------------------|
        KC_NO,   SE_TILD,   SE_UNDS,   SE_MINS,    KC_NO,                               KC_NO,    KC_NO,     KC_NO,     KC_NO,    KC_NO,   \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
    SE_BSLS_MAC, SE_SLSH,   SE_APOS,   SE_QUO2,   SE_GRV,                               KC_NO,   SE_COLN,    KC_NO,    SE_SCLN,   KC_NO,   \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
        KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,                               KC_NO,    KC_NO,     KC_NO,     KC_NO,    KC_NO,   \
  //|--------------------------------+----------+----------+----------|  |----------+----------+----------+--------------------------------|
                                        KC_NO,     KC_NO,     KC_NO,         KC_NO,     KC_NO,    KC_NO   \
                                   //|--------------------------------|  |--------------------------------|
  ),

  [_SYMBOLS] = LAYOUT( \
  //|------------------------------------------------------|                        |------------------------------------------------------|
        KC_NO,   SE_CIRC,   KC_PERC,   KC_HASH,    KC_NO,                               KC_NO,    KC_NO,    SE_ASTR,    KC_NO,    KC_NO,   \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
        SE_AT, SE_PIPE_MAC, SE_AMPR,    SE_EQL,    KC_NO,                               KC_0,  SE_DLR_MAC,  SE_PLUS,    KC_NO,    KC_NO,   \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
        KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,                               KC_NO,    KC_NO,     KC_NO,     KC_NO,    KC_NO,   \
  //|--------------------------------+----------+----------+----------|  |----------+----------+----------+--------------------------------|
                                        KC_NO,     KC_NO,     KC_NO,         KC_NO,     KC_NO,    KC_NO   \
                                   //|--------------------------------|  |--------------------------------|
  ),

  [_ARROWS] = LAYOUT( \
  //|------------------------------------------------------|                        |------------------------------------------------------|
        KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,                               KC_NO,   KC_PGUP,   KC_PGDN,    KC_NO,    KC_NO,\
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
        KC_NO,   KC_HOME,    KC_END,    KC_NO,     KC_NO,                              KC_LEFT,  KC_DOWN,    KC_UP,    KC_RIGHT,  KC_NO,   \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
        KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,                               KC_NO,    KC_NO,     KC_NO,     KC_NO,    KC_NO,   \
  //|--------------------------------+----------+----------+----------|  |----------+----------+----------+--------------------------------|
                                        KC_NO,     KC_NO,     KC_NO,         KC_NO,     KC_NO,    KC_NO   \
                                   //|--------------------------------|  |--------------------------------|
  ),

  [_NUMBERS] = LAYOUT( \
  //|------------------------------------------------------|                        |------------------------------------------------------|
        KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,                               KC_NO,    KC_7,       KC_8,      KC_9,     KC_NO,  \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
        KC_NO, KC__VOLDOWN,   KC_NO,  KC__VOLUP,   KC_NO,                               KC_0,     KC_4,       KC_5,      KC_6,     KC_NO,  \
  //|----------+----------+----------+----------+----------|                        |----------+----------+----------+----------+----------|
        KC_NO,    KC_NO,     KC_NO,     KC_NO,     KC_NO,                               KC_NO,    KC_1,       KC_2,      KC_3,     KC_NO,  \
  //|--------------------------------+----------+----------+----------|  |----------+----------+----------+--------------------------------|
                                        KC_NO,     KC_NO,     KC_NO,         KC_NO,     KC_NO,    KC_NO   \
                                   //|--------------------------------|  |--------------------------------|
  )
};

