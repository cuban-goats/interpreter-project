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

void run_ll(list_node_t *head, stack mystack, char label_tracker[ROWS][COLS]) {
  list_node_t *temp = head;
  char *end_ptr;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (strcmp(&label_tracker[i][j], ":") == 0) {
        label_tracker[i][j] = '\0';
      }
    }
  }

  int number;
  while (temp != NULL) {
    if (strcmp(temp->list_node_value, "STOP") == 0) {
      printf("Toaster now finished running");
      break;
    } else if (strcmp(temp->list_node_value, "PUSH") == 0) {
      list_node_t *next_node = get_next_node(temp);
      // printf("%s\n", next_node->list_node_value);
      number = (int)strtol(next_node->list_node_value, &end_ptr, 10);
      push(&mystack, number);
    } else if (strcmp(temp->list_node_value, "POP") == 0) {
      number = pop(&mystack);
      // printf("popped value: %i \n", number);
    } else if (strcmp(temp->list_node_value, "SUB") == 0) {
      int one = pop(&mystack);
      int two = pop(&mystack);
      number = two - one;
      printf("subtracted value: %i \n", number);
      push(&mystack, number);
    } else if (strcmp(temp->list_node_value, "ADD") == 0) {
      int one = pop(&mystack);
      int two = pop(&mystack);
      number = one + two;
      printf("added value: %i \n", number);
      push(&mystack, number);
    } else if (strcmp(temp->list_node_value, "PRINT") == 0) {
      list_node_t *next_node = get_next_node(temp);
      // printf("%s\n", next_node->list_node_value);
      char *str = next_node->list_node_value;
      printf("%s \n", str);
    } else if (strcmp(temp->list_node_value, "READ") == 0) {
      scanf("%d", &number);
      push(&mystack, number);
    } else if (strcmp(temp->list_node_value, "JUMP.EQ.0") == 0) {
      number = pop(&mystack);
      // printf("popped number: %i\n", number);
      list_node_t *next_node = get_next_node(temp);
      char *label_declaration = next_node->list_node_value;
      // printf("This is the label declaration: %s\n", label_declaration);

      if (number == 0) {
        // printf("is 0\n");
        for (int i = 0; i < ROWS; i++) {
          if (strcmp(label_declaration, label_tracker[i]) == 0) {
            // printf("label to jump to: %s -- \n", label_tracker[i]);
            int index = i-1;
            // printf("Index to jump to: %i\n", index);
            temp = get_node_by_index(head, index);
          }
        }
      }
      push(&mystack, number);
    } else if (strcmp(temp->list_node_value, "JUMP.GT.0") == 0) {
      number = pop(&mystack);
      // printf("popped number: %i\n", number);
      list_node_t *next_node = get_next_node(temp);
      char *label_declaration = next_node->list_node_value;
      // printf("This is the label declaration: %s\n", label_declaration);

      if (number > 0) {
        // printf("is >0\n");
        for (int i = 0; i < ROWS; i++) {
          if (strcmp(label_declaration, label_tracker[i]) == 0) {
            // printf("label to jump to: %s -- \n", label_tracker[i]);
            int index = i-1;
            // printf("Index to jump to: %i\n", index);
            temp = get_node_by_index(head, index);
          }
        }
      }
      push(&mystack, number);
    }
    temp = temp->next;
  }
}
