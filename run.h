#ifndef RUN_H
#define RUN_H

#include "list.h"
#include "stack.h"

#define MAX_INSTRUCTIONS 200
#define MAX_INSTRUCTION_LENGTH 200
#define MAX_OPCODE_LENGTH 20

typedef node *stack;

void run(char program[MAX_INSTRUCTIONS][MAX_INSTRUCTION_LENGTH], stack mystack);
void run_ll(list_node_t *head, stack mystack);

#endif
