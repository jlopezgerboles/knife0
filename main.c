#include "core.h"

int main(int argc, char* argv[]) {

	core_t core;
	
	core_initialization(&core);
	
	while(core.running == 1) {
		core_update(&core);
	}

	core_shutdown(&core);
	return 0;
}
