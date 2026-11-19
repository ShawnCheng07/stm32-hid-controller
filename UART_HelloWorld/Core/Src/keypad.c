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

static const char keypad_map[KEYPAD_ROWS][KEYPAD_COLS] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};


void Keypad_Init(void)
{
	for (int row = 0; row < KEYPAD_ROWS; ++row)
	{
		HAL_GPIO_WritePin(row_ports[row], row_pins[row], GPIO_PIN_RESET);
	}
}

char Keypad_Scan(void)
{
	for (int row = 0; row < KEYPAD_ROWS; ++row)
	{
		HAL_GPIO_WritePin(row_ports[row], row_pins[row], GPIO_PIN_SET);
		for (int col = 0; col < KEYPAD_COLS; ++col)
		{
			if (HAL_GPIO_ReadPin(col_ports[col], col_pins[col]) == GPIO_PIN_SET)
			{
				HAL_Delay(50);
				if (HAL_GPIO_ReadPin(col_ports[col], col_pins[col]) == GPIO_PIN_SET)
				{
					while (HAL_GPIO_ReadPin(col_ports[col], col_pins[col]) == GPIO_PIN_SET)
					{
						HAL_Delay(5);
					}
					HAL_GPIO_WritePin(row_ports[row], row_pins[row], GPIO_PIN_RESET);
					return keypad_map[row][col];
				}
			}
		}
		HAL_GPIO_WritePin(row_ports[row], row_pins[row], GPIO_PIN_RESET);
	}
	return '\0';
}
