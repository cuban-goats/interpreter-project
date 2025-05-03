#include <stdio.h>
#include <string.h>
#include "format.h"

void split_and_store(char program[ROWS][COLS], int line_count,
                     char opcode[ROWS][MAX_OPCODE][COLS]) {
  for (int i = 0; i < line_count; i++) {
    char temp[COLS];
    strcpy(temp, program[i]); // Copy each line to a temporary buffer

    int instruction_index = 0;
    char *instruction = strtok(temp, " "); // split by space

    // Store opcode in the array
    while (instruction != NULL && instruction_index < MAX_OPCODE) {
      // Copy the instruction into the fixed-size array
      strncpy(opcode[i][instruction_index], instruction, COLS - 1);
      opcode[i][instruction_index][COLS - 1] = '\0'; // Ensure null-termination
      instruction_index++;
      instruction = strtok(NULL, " "); // Get next instruction
    }
  }
}

// function to clean up the opcode array from '/0' values
// this function is usless, the massive gaps are made because of the max opcode
// value not being reached, therefore tons of 0 values are printed.
void remove_spaces(
    char opcode[ROWS][MAX_OPCODE][COLS],
    char clean_opcode[CLEAN_ROWS][MAX_CLEAN_OPCODE][CLEAN_COLS]) {
  int newRowIndexes[ROWS] = {0};

  int k = 0, l = 0;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < MAX_OPCODE; j++) {
      if (opcode[i][j] != NULL && opcode[i][j] != (void *)0) {
        if (newRowIndexes[i] < MAX_OPCODE) {
          strncpy(clean_opcode[k][newRowIndexes[k]], opcode[i][j],
                  CLEAN_COLS - 1);
          clean_opcode[k][newRowIndexes[k]][CLEAN_COLS - 1] = '\0';
          newRowIndexes[k]++;
          ;
        } else {
          printf("MAX_OPCODE exceeded: %d \n", i);
          break;
        }
      }
    }
  }
  for (int m = 0; m < CLEAN_ROWS; m++) {
    printf("%s \n", *clean_opcode[m]);
  }
}
