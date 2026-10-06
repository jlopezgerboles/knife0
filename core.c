#include "core.h"
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#define FIXED_TIMESTEP (1.0/60.0)

void core_initialization(core_t* core) {
	core->running = 1;
	core->previous_time = SDL_GetTicks() / 1000.0;
	core->accumulator = 0.0;

	input_initialization(&core->input);
	controller_initialization();
	video_initialization(&core->video);

}

void core_update(core_t *core) {
    SDL_Event event;
    double current_time;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            core->running = 0;
        }
    }

    if (!core->running) {
        return;
    }

    current_time = SDL_GetTicks() / 1000.0;
    core->accumulator += current_time - core->previous_time;
    core->previous_time = current_time;

    input_update(&core->input);

    while (core->accumulator >= FIXED_TIMESTEP) {
	controller_update(&core->input, &core->logic);
        logic_update(&core->logic);
        core->accumulator -= FIXED_TIMESTEP;
    }

    video_update(&core->video, &core->logic.render_state);
}

void core_shutdown(core_t* core) {
	video_shutdown(&core->video);
}
