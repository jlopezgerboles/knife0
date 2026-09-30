#include "core.h"

int main(int argc, char* argv[]) {

	/* Declare the core variable here as the lifetime of the variable
	 * is equal to the lifetime of this function.
	 */
	core_t core;
	
	/* Initialize the values of the core struct
	 */
	core_initialization(&core);
	
	/* Perform the core game loop
	 */
	while(core.running == 1) {
		core_update(&core);
	}

	/* Shutdown the elements of core that require clearing
	 */
	core_shutdown(&core);
	return 0;
}
