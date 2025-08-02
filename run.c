#include <string.h>
#include "run.h"
#include "sort.h"
#include "stack.h"

void run(char program[MAX_INSTRUCTIONS][MAX_INSTRUCTION_LENGTH], stack *mystack) {

  char opcode[MAX_OPCODE][MAX_OPCODE_LENGTH];
  int pc = 0;
  for (int i = 0; i < MAX_INSTRUCTIONS; i++) {
    if (strcmp(program[i], "HALT") != 0) {
      strcpy(opcode[i], program[i]);
      pc++;
      if (strcmp(opcode[i], "PUSH")) {

      }
    }
  }
}
