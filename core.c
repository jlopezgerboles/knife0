#include "core.h"
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#define FIXED_TIMESTEP 0.016666667

void core_initialization(core_t* core) {
	core->running = 1;
	core->previous_time = SDL_GetTicks();
	core->accumulator = 0.0;
}

void core_update(core_t* core) {
	const double current_time = SDL_GetTicks();
	core->accumulator =+ current_time - core->previous_time;
	core->previous_time = SDL_GetTicks();
	/*input_update()*/
	while(core->accumulator >= FIXED_TIMESTEP) {
		/*logic_update();*/
		printf("Game advances one step.\n");
		core->accumulator =- FIXED_TIMESTEP;
	}
	/*render_update(remderstate_t* renderstate);*/
}

void core_shutdown(core_t* core) {
}
