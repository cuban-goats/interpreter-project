#include "parse.h"
#include "list.h"
#include "run.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list_node_t *parse(char opcode[ROWS][MAX_OPCODE][COLS], int label_tracker[MAX_LABELS],
           int token_counter) {
  // count number of tokens (to get indexes) (not in use)
  // to get the index of the label
  // int token_counter = 0;

  // to track on which index a label is (not in use)
  // int label_tracker[MAX_LABELS] = {};

  char *endptr;

  char string_literal[MAX_STR_LENGTH];
  char valueof_string_literal[MAX_STR_LENGTH - 2];
  char label[MAX_STR_LENGTH];

  list_node_t *head = NULL;
  list_node_t *temp;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < MAX_OPCODE; j++) {
      if (strcmp(opcode[i][j], "\0") == 1) {
        printf("null terminator at: i=%i, j=%i", i, j);
        continue;
      } else if (strchr(opcode[i][j], ':') != NULL) {
        // label_tracker[opcode without ":"] = token_counter
        // value of opcode as key to get values for specific labels
        continue;
      }

      if (strcmp(opcode[i][j], "PUSH") == 0) {
        int number = strtol(opcode[i][j + 1], &endptr, 10);
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        temp = add_node(opcode[i][j + 1]);
        append_node(&head, temp);
        token_counter++;

      } else if (strcmp(opcode[i][j], "PRINT") == 0) {
        strcpy(string_literal, opcode[i][j + 1]);
        char *result = string_literal + 1;
        result[strlen(result) - 1] = '\0';
        strcpy(valueof_string_literal, result);
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        temp = add_node(opcode[i][j + 1]);
        append_node(&head, temp);
        token_counter++;

      } else if (strcmp(opcode[i][j], "JUMP.EQ.0") == 0) {
        strcpy(label, opcode[i][j + 1]);
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        temp = add_node(opcode[i][j + 1]);
        append_node(&head, temp);
        token_counter++;

      } else if (strcmp(opcode[i][j], "JUMP.GT.0") == 0) {
        strcpy(label, opcode[i][j + 1]);
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
        temp = add_node(opcode[i][j + 1]);
        append_node(&head, temp);
        token_counter++;
      } else if (strcmp(opcode[i][j], "STOP") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
      } else if (strcmp(opcode[i][j], "POP") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
      } else if (strcmp(opcode[i][j], "READ") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
      } else if (strcmp(opcode[i][j], "ADD") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
      } else if (strcmp(opcode[i][j], "SUB") == 0) {
        temp = add_node(opcode[i][j]);
        append_node(&head, temp);
      }
    }
  }
  return head;
}
