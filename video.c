#include "video.h"
#include <stdio.h>
#include <SDL3/SDL_opengl.h>

void video_initialization(video_t* video) {
	SDL_Init(SDL_INIT_VIDEO);
	video->video_width = 1280;
	video->video_height = 720;
	video->window = SDL_CreateWindow(
				"OK",
				video->video_width,
				video->video_height,
				SDL_WINDOW_OPENGL);
	video->context = SDL_GL_CreateContext(video->window);
}

void video_update(video_t *video) {
	glClearColor(0.1f, 0.3f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (!SDL_GL_SwapWindow(video->window)) {
		fprintf(stderr, "Presentation failed: %s\n", SDL_GetError());
	}
}

void video_shutdown(video_t* video) {
	SDL_DestroyWindow(video->window);
}
