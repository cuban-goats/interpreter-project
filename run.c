#include "run.h"
#include "sort.h"
#include "stack.h"
#include <string.h>

void run(char program[MAX_INSTRUCTIONS][MAX_INSTRUCTION_LENGTH],
         stack mystack) {

  char opcode[MAX_OPCODE][MAX_OPCODE_LENGTH];
  int pc = 0;
  for (int i = 0; i < MAX_INSTRUCTIONS; i++) {
    if (strcmp(program[i], "HALT") == 0) {
      break;
    } else if (strcmp(opcode[i], "PUSH") == 0) {
      // NOTE: change to be the next element, which is expected to be a number
      int number = 0;
      push(&mystack, number);
    } else if (strcmp(opcode[i], "POP") == 0) {
      pop(&mystack);
    } else if (strcmp(opcode[i], "SUB") == 0) {
      // subtraction
    } else if (strcmp(opcode[i], "ADD") == 0) {
      // addition
    } else if (strcmp(opcode[i], "PRINT") == 0) {
      // get next element and print it
    } else if (strcmp(opcode[i], "READ") == 0) {
      // read user input, push it to stack
    }
  }
}
