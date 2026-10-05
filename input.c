#include "input.h"

void input_initialization(input_t* input) {
	int i = 0;
	for(i= 0; i < SDL_SCANCODE_COUNT; i++) {
	  input->key_held[i] = 0;
	  input->key_pressed[i] = 0;
	  input->key_released[i] = 0;
	}
}

void input_update(input_t* input) {
  SDL_PumpEvents();
  const _Bool* keys = SDL_GetKeyboardState(NULL);

  int i = 0;
  for (i = 0; i < SDL_SCANCODE_COUNT; i++) {
    int now = keys[i] ? 1 : 0;
    if (now && !input->key_held[i]) {
      input->key_pressed[i] = 1;
    } else if (!now && input->key_held[i]) {
      input->key_released[i] = 1;
    }
    input->key_held[i] = now;
  }
}
