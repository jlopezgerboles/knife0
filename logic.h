#ifndef LOGIC_H
#define LOGIC_H

#include "render_state.h"

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
	render_state_t* render_state;
} logic_t;

void logic_update(logic_t* logic);

#endif
