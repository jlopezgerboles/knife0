#include "controller.h"

static SDL_Scancode keymap[BUTTON_COUNT];

void controller_initialization() {
	keymap[BUTTON_LEFT] = SDL_SCANCODE_LEFT;
	keymap[BUTTON_UP] = SDL_SCANCODE_UP;
	keymap[BUTTON_DOWN] = SDL_SCANCODE_DOWN;
	keymap[BUTTON_RIGHT] = SDL_SCANCODE_RIGHT;
	keymap[BUTTON_SELECT] = SDL_SCANCODE_S;
	keymap[BUTTON_START] = SDL_SCANCODE_R;
	keymap[BUTTON_A] = SDL_SCANCODE_Q;
	keymap[BUTTON_B] = SDL_SCANCODE_E;
}

void controller_update(input_t* input, logic_t* logic) {
	SDL_Scancode key;
	int i = 0;
	
	/*
	 * Bridge between input system and logic system
	 */
	for(i = 0; i < BUTTON_COUNT; i++) {
		
		key = keymap[i];

		logic->button_held[i] = input->key_held[key];
		logic->button_pressed[i] = input->key_pressed[key];
		logic->button_released[i] = input->key_released[key];
	}

	/*
	 * Clearing edges of the input system once per tick
	 */
	for(i = 0; i < SDL_SCANCODE_COUNT; i++) {
		input->key_pressed[i] = 0;
		input->key_released[i] = 0;
	}
}
