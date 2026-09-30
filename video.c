#include "video.h"
#include <stdio.h>


void video_initialization(video_t* video) {
	SDL_Init(SDL_INIT_VIDEO);
	video->video_width = 1280;
	video->video_height = 720;
	video->window = SDL_CreateWindow(
				"OK",
				video->video_width,
				video->video_height,
				0);
}

void video_update(video_t* video) {

}

void video_shutdown(video_t* video) {
	SDL_DestroyWindow(video->window);
}
