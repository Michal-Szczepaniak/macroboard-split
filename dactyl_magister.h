/* Copyright 2021 Michał Szczepaniak
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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
	L000, L001, L002, L003, L004, L005, R006, R007, R008, R009, R010, R011, \
	L100, L101, L102, L103, L104, L105, R106, R107, R108, R109, R110, R111, \
	L200, L201, L202, L203, L204, L205, R206, R207, R208, R209, R210, R211, \
	L300, L301, L302, L303, L304, L305, R306, R307, R308, R309, R310, R311, \
	L400, L401, L402, L403, L404, L405, R406, R407, R408, R409, R410, R411, \
	            L502, L503, L504, L505, R506, R507                          \
) { \
	{ L000,  L001,  L002,  L003,  L004,  L005 }, \
	{ L100,  L101,  L102,  L103,  L104,  L105 }, \
	{ L200,  L201,  L202,  L203,  L204,  L205 }, \
	{ L300,  L301,  L302,  L303,  L304,  L305 }, \
	{ L400,  L401,  L402,  L403,  L404,  L405 }, \
	{ KC_NO, KC_NO, L502,  L503,  L504,  L505 }, \
	{ R006,  R007,  R008,  R009,  R010,  R011 }, \
	{ R106,  R107,  R108,  R109,  R110,  R111 }, \
	{ R206,  R207,  R208,  R209,  R210,  R211 }, \
	{ R306,  R307,  R308,  R309,  R310,  R311 }, \
	{ R406,  R407,  R408,  R409,  R410,  R411 }, \
	{ R506,  R507, KC_NO, KC_NO, KC_NO, KC_NO }  \
}
