#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "input.h"
#include "logic.h"

void controller_initialization();
void controller_update(input_t* input, logic_t* logic);

#endif
