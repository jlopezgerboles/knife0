#include "logic.h"

#include <stdio.h>

void logic_update(logic_t* logic) {
	if(logic->button_pressed[BUTTON_UP]) {
		logic->render_state.color = 0xFF0000;
		printf("UP Pressed!\n");
	}
	if(logic->button_held[BUTTON_UP]) printf("UP Held!\n");
	if(logic->button_released[BUTTON_UP]) printf("UP Released!\n");
	if(logic->button_pressed[BUTTON_DOWN]) {
		logic->render_state.color = 0x00FF00;
		printf("DOWN Pressed!\n");
	}
	if(logic->button_pressed[BUTTON_LEFT]) {
		logic->render_state.color = 0x0000FF;
		printf("LEFT Pressed!\n");
	}
}
