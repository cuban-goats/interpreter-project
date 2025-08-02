#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse(char opcode[ROWS][MAX_OPCODE][COLS]) {
  // count number of tokens (to get indexes) (not in use)
  // to get the index of the label
  int token_counter = 0;

  // to track on which index a label is (not in use)
  int label_tracker[MAX_LABELS] = {};

  char *endptr;

  char string_literal[MAX_STR_LENGTH];
  char label[MAX_STR_LENGTH];

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < MAX_OPCODE; j++) {
      if (strcmp(opcode[i][j], "\0") == 1) {
        printf("empty value at: i=%i, j=%i", i, j);
        continue;
      }
      // Labels (no solutin yet)
      if (strchr(opcode[i][j], ':') != NULL) {
        // label_tracker[opcode without ":"] = token_counter
        // value of opcode as key to get values for specific labels
      }
      // PUSH, the next token must be a number
      if (strcmp(opcode[i][j], "PUSH") == 0) {
        // save the value of the number
        int number = strtol(opcode[i][j + 1], &endptr, 10);
        printf("Number after PUSH: %i \n", number);
      }
      // PRINT, the next token must be a string
      else if (strcmp(opcode[i][j], "PRINT") == 0) {
        strcpy(string_literal, opcode[i][j + 1]);
        // save the value of the string_literal
        printf("String after PRINT: %s \n", string_literal);
      } else if (strcmp(opcode[i][j], "JUMP.EQ.0") == 0) {
        strcpy(label, opcode[i][j + 1]);
        printf("Label after JUMP.EQ.0: %s \n", label);
      } else if (strcmp(opcode[i][j], "JUMP.GT.0") == 0) {
        strcpy(label, opcode[i][j + 1]);
        printf("Label after JUMP.GT.0: %s \n", label);
      }
    }
  }
}
