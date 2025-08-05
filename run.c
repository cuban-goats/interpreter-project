#include "run.h"
#include "sort.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run(char program[MAX_INSTRUCTIONS][MAX_INSTRUCTION_LENGTH],
         stack mystack) {
  
  char *endptr;
  int pc = 0;
  for (int i = 0; i < MAX_INSTRUCTIONS; i++) {
    if (strcmp(program[i], "HALT") == 0) {
      break;
    } else if (strcmp(program[i], "PUSH") == 0) {
      int number = strtol(program[i+1], &endptr, 10);
      push(&mystack, number);
    } else if (strcmp(program[i], "POP") == 0) {
      pop(&mystack);
    } else if (strcmp(program[i], "SUB") == 0) {
      int one = pop(&mystack);
      int two = pop(&mystack);
      int subtracted = one - two;
      printf("subtracted value: %i \n", subtracted);
      push(&mystack, subtracted);
    } else if (strcmp(program[i], "ADD") == 0) {
      int one = pop(&mystack);
      int two = pop(&mystack);
      int added = one + two;
      printf("added value: %i \n", added);
      push(&mystack, added);
    } else if (strcmp(program[i], "PRINT") == 0) {
      char *str = program[i+1];
      printf("%s \n", str);
    } else if (strcmp(program[i], "READ") == 0) {
      // read user input, push it to stack
    }
  }
}
