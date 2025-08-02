#ifndef RUN_H
#define RUN_H

#include "stack.h"

#define MAX_INSTRUCTIONS 200
#define MAX_INSTRUCTION_LENGTH 200
#define MAX_OPCODE_LENGTH 20

typedef node *stack;

void run(char program[MAX_INSTRUCTIONS][MAX_INSTRUCTION_LENGTH], stack mystack);

#endif
