#include "parse.h"
#include "run.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse(char opcode[ROWS][MAX_OPCODE][COLS],
           char program[MAX_INSTRUCTIONS][MAX_INSTRUCTION_LENGTH],
           int label_tracker[MAX_LABELS], int token_counter) {
  // count number of tokens (to get indexes) (not in use)
  // to get the index of the label
  // int token_counter = 0;

  // to track on which index a label is (not in use)
  // int label_tracker[MAX_LABELS] = {};

  char *endptr;

  char string_literal[MAX_STR_LENGTH];
  char valueof_string_literal[MAX_STR_LENGTH - 2];
  char label[MAX_STR_LENGTH];

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < MAX_OPCODE; j++) {
      if (strcmp(opcode[i][j], "\0") == 1) {
        printf("empty value at: i=%i, j=%i", i, j);
        continue;
      } else if (strchr(opcode[i][j], ':') != NULL) {
        // label_tracker[opcode without ":"] = token_counter
        // value of opcode as key to get values for specific labels
      } else {
        // append to program
      }

      if (strcmp(opcode[i][j], "PUSH") == 0) {
        int number = strtol(opcode[i][j + 1], &endptr, 10);
        // append the number to program
        // printf("Number after PUSH: %i \n", number);
        token_counter++;

      } else if (strcmp(opcode[i][j], "PRINT") == 0) {
        strcpy(string_literal, opcode[i][j + 1]);
        char *result = string_literal + 1;
        result[strlen(result) - 1] = '\0';
        strcpy(valueof_string_literal, result);
        // printf("%s\n", valueof_string_literal);
        // append the valueof_string_literal to program
        token_counter++;
        
      } else if (strcmp(opcode[i][j], "JUMP.EQ.0") == 0) {
        strcpy(label, opcode[i][j + 1]);
        printf("Label after JUMP.EQ.0: %s \n", label);
        token_counter++;

      } else if (strcmp(opcode[i][j], "JUMP.GT.0") == 0) {
        strcpy(label, opcode[i][j + 1]);
        printf("Label after JUMP.GT.0: %s \n", label);
        token_counter++;
      }
    }
  }
}
