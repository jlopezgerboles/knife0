#ifndef CORE_H
#define CORE_H

#include "video.h"
#include "input.h"
#include "controller.h"
#include "logic.h"

typedef struct core_t {
	int running;
	double previous_time;
	double accumulator;
	video_t video;
	input_t input;
	logic_t logic;
} core_t;

void core_initialization(core_t* core);
void core_update(core_t* core);
void core_shutdown(core_t* core);

#endif
