/*
 * keypad.c
 *
 *  Created on: Nov 15, 2026
 *      Author: shawn
 */

#include "keypad.h"


static GPIO_TypeDef* row_ports[KEYPAD_ROWS] = {
		ROW_1_GPIO_Port, ROW_2_GPIO_Port, ROW_3_GPIO_Port, ROW_4_GPIO_Port
};

static uint16_t row_pins[KEYPAD_ROWS] = {
		ROW_1_Pin, ROW_2_Pin, ROW_3_Pin, ROW_4_Pin
};

static GPIO_TypeDef* col_ports[KEYPAD_COLS] = {
		COL_1_GPIO_Port, COL_2_GPIO_Port, COL_3_GPIO_Port, COL_4_GPIO_Port
};

static uint16_t col_pins[KEYPAD_COLS] = {
		COL_1_Pin, COL_2_Pin, COL_3_Pin, COL_4_Pin
};
