/*
 * keypad.h
 *
 *  Created on: Nov 15, 2026
 *      Author: shawn
 */

#ifndef SRC_KEYPAD_H_
#define SRC_KEYPAD_H_

#include "main.h"

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

// Initializes all keypad row pins to LOW
void Keypad_Init(void);

// Scans the keypad with blocking, returns the null terminator if there is no button press
char Keypad_Scan(void);

#endif /* SRC_KEYPAD_H_ */
