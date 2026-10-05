#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL.h>

typedef struct input_t {
	int key_held[SDL_SCANCODE_COUNT];
	int key_pressed[SDL_SCANCODE_COUNT];
	int key_released[SDL_SCANCODE_COUNT];
} input_t;

void input_initialization(input_t* input);
void input_update(input_t* input);

#endif
