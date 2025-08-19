#include "run.h"
#include "list.h"
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
    if (strcmp(program[i], "TOASTERSTOP") == 0) {
      printf("Toaster now finished running");
      break;
    } else if (strcmp(program[i], "TOASTERPUSH") == 0) {
      int number = strtol(program[i + 1], &endptr, 10);
      push(&mystack, number);
    } else if (strcmp(program[i], "TOASTERPOP") == 0) {
      int popped = pop(&mystack);
      printf("popped value: %i \n", popped);
    } else if (strcmp(program[i], "TOASTERSUB") == 0) {
      int one = pop(&mystack);
      int two = pop(&mystack);
      int subtracted = one - two;
      printf("subtracted value: %i \n", subtracted);
      push(&mystack, subtracted);
    } else if (strcmp(program[i], "TOASTERADD") == 0) {
      int one = pop(&mystack);
      int two = pop(&mystack);
      int added = one + two;
      printf("added value: %i \n", added);
      push(&mystack, added);
    } else if (strcmp(program[i], "TOASTERPRINT") == 0) {
      char *str = program[i + 1];
      printf("%s \n", str);
    } else if (strcmp(program[i], "READ") == 0) {
      // read user input, push it to stack
    }
  }
}

void run_ll(list_node_t *head, stack mystack) {
  list_node_t *temp = head;
  char *end_ptr;
  while (temp != NULL) {
    if (strcmp(temp->list_node_value, "STOP") == 0) {
      printf("Toaster now finished running");
      break;
    } else if (strcmp(temp->list_node_value, "PUSH") == 0) {
      list_node_t *next_node = get_next_node(temp);
      printf("%s\n", next_node->list_node_value);
      int number = (int) strtol(next_node->list_node_value, &end_ptr, 10);;
      push(&mystack, number);
    }
    temp = temp->next;
  }
}
