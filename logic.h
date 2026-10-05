#ifndef LOGIC_H
#define LOGIC_H

typedef enum button_e {
	BUTTON_LEFT,
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_RIGHT,
	BUTTON_SELECT,
	BUTTON_START,
	BUTTON_A,
	BUTTON_B,
	BUTTON_COUNT
} button_e;

typedef struct logic_t {
	int button_held[BUTTON_COUNT];
	int button_pressed[BUTTON_COUNT];
	int button_released[BUTTON_COUNT];
} logic_t;

#endif
