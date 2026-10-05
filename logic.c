#include "logic.h"

#include <stdio.h>

void logic_update(logic_t* logic) {
	if(logic->button_pressed[BUTTON_UP]) printf("UP Pressed!\n");
	if(logic->button_held[BUTTON_UP]) printf("UP Held!\n");
	if(logic->button_released[BUTTON_UP]) printf("UP Released!\n");
}
