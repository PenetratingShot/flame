#ifndef SCREEN_H
#define SCREEN_H

#include "../cpu/type.h"
#include "../cpu/ports.h"
#include "../include/mem.h"

// VGA Output Buffer
#define VIDEO_ADDRESS 0xb8000

// Screen Dimensions
#define MAX_ROWS 25
#define MAX_COLS 80

// Common Color Codes
#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0xf4

/* Screen i/o ports */
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

/* Public kernel API */
void clear();
void kprint_at(char *message, int col, int row);
void kprint(char *message);
void kprint_backspace();

#endif
