#include "video.h"
#include <stdio.h>
#include <SDL3/SDL_opengl.h>

static void video_draw_background(int color);

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

void video_update(video_t *video, render_state_t* render_state) {
	video_draw_background(render_state->color);
	glClear(GL_COLOR_BUFFER_BIT);

	if (!SDL_GL_SwapWindow(video->window)) {
		fprintf(stderr, "Presentation failed: %s\n", SDL_GetError());
	}
}

void video_shutdown(video_t* video) {
	SDL_DestroyWindow(video->window);
}

static void video_draw_background(int color) {
	glClearColor(
		((color >> 16) & 0xFF) / 255.0f,
		((color >> 8) & 0xFF) / 255.0f,
		(color & 0xFF) / 255.0f,
		1.0f
	);
}
