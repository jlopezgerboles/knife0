#ifndef CORE_H
#define CORE_H

typedef struct core_t {
	int running;
	double previous_time;
	double accumulator;
} core_t;

void core_initialization(core_t* core);
void core_update(core_t* core);
void core_shutdown(core_t* core);

#endif
