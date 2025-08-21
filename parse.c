#include "parse.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ROWS are just the program lines

list_node_t *parse(char opcode[ROWS][MAX_OPCODE][COLS],
                   char label_tracker[ROWS][COLS], int token_counter) {
  char *endptr;

  char string_literal[MAX_STR_LENGTH];
  char valueof_string_literal[MAX_STR_LENGTH - 2];
  char label[MAX_STR_LENGTH];

  list_node_t *head = NULL;
  list_node_t *temp;

  // char head_indicator[200] = "#";
  // temp = add_node(placeholder);
  // append_node(&head, temp);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < MAX_OPCODE; j++) {
      if (strcmp(opcode[i][j], "\0") == 1) {
        printf("null terminator at: i=%i, j=%i", i, j);
        continue;
      } else if (strchr(opcode[i][j], ':') != NULL) {
        // Copy without the ':'
        strcpy(label_tracker[token_counter], opcode[i][j]);
        // printf("Here is the linenumber of where to jump: %i\n", token_counter);
        continue;
      }

      if (strcmp(opcode[i][j], "TOASTERPUSH") == 0) {
        int number = strtol(opcode[i][j + 1], &endptr, 10);
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        temp = add_node(opcode[i][j + 1]);
        append_node(&head, temp);
        token_counter++;
        token_counter++;

      } else if (strcmp(opcode[i][j], "TOASTERPRINT") == 0) {
        strcpy(string_literal, opcode[i][j + 1]);
        char *result = string_literal + 1;
        result[strlen(result) - 1] = '\0';
        strcpy(valueof_string_literal, result);
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        temp = add_node(opcode[i][j + 1]);
        append_node(&head, temp);
        token_counter++;
        token_counter++;

      } else if (strcmp(opcode[i][j], "TOASTERJUMP.EQ.0") == 0) {
        strcpy(label, opcode[i][j + 1]);
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        temp = add_node(opcode[i][j + 1]);
        append_node(&head, temp);
        token_counter++;
        token_counter++;

      } else if (strcmp(opcode[i][j], "TOASTERJUMP.GT.0") == 0) {
        strcpy(label, opcode[i][j + 1]);
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        temp = add_node(opcode[i][j + 1]);
        append_node(&head, temp);
        token_counter++;
        token_counter++;
      } else if (strcmp(opcode[i][j], "TOASTERSTOP") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        token_counter++;
      } else if (strcmp(opcode[i][j], "TOASTERPOP") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        token_counter++;
      } else if (strcmp(opcode[i][j], "TOASTERREAD") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        token_counter++;
      } else if (strcmp(opcode[i][j], "TOASTERADD") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        token_counter++;
      } else if (strcmp(opcode[i][j], "TOASTERSUB") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        token_counter++;
      }
    }
  }
  head = reverse_list(head);
  return head;
}
