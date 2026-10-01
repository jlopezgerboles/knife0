#ifndef VIDEO_H
#define VIDEO_H

#include <SDL3/SDL.h>

typedef struct video_t {
	int video_width;
	int video_height;
	SDL_Window* window;
	SDL_GLContext context;
} video_t;

void video_initialization(video_t* video);
void video_update(video_t* video);
void video_shutdown(video_t* video);

#endif
