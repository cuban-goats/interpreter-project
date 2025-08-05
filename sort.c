#include "sort.h"
#include <stdio.h>
#include <string.h>

void get_labels(char labels[MAX_LABELLENGTH][MAX_LABELS],
                char opcode[ROWS][MAX_OPCODE][COLS]) {
  // To keep track of where to store the labels in the array
  int labels_index = 0;

  // just stores Labels, not their position in relation to their name
  int label_tracker[MAX_LABELS] = {};
  int label_count = 0;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < MAX_OPCODE; j++) {
      for (int k = 0; k < COLS; k++) {
        if (opcode[i][j][k] == ':') {
          // printf("%s\n", opcode[i][j]);
          if (labels_index < MAX_LABELS) {
            strncpy(labels[labels_index], opcode[i][j], MAX_LABELLENGTH - 1);
            labels[labels_index][MAX_LABELLENGTH - 1] = '\0'; // Null-terminate
            labels_index++;

            label_tracker[label_count] = i;
            label_count++;
          } else {
            printf("Too many Labels, size overstepped\n");
          }
        }
      }
    }
  }
  // Print all stored labels
  /*
  printf("\nStored Labels:\n");
  for (int m = 0; m < labels_index; m++) {
    printf("%s (index %d)\n", labels[m], label_tracker[m]);
  }
  printf("\n");
  */
}

void get_tokens(char tokens[MAX_TOKENLENGTH][MAX_TOKENS],
                char opcode[ROWS][MAX_OPCODE][COLS]) {
  int token_counter = 0;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < MAX_OPCODE; j++) {
      // printf("Checking: [%d][%d] = '%s'\n", i, j, opcode[i][j]);
      if (strchr(opcode[i][j], ':') == NULL && strcmp(opcode[i][j], "") != 0) {
        // printf("%s\n", opcode[i][j]);
        // Ensure not to overwrite the tokens array's bounds and copy the
        // strings
        if (token_counter < MAX_TOKENS) {
          strncpy(tokens[token_counter], opcode[i][j], MAX_TOKENLENGTH - 1);
          tokens[token_counter][MAX_TOKENLENGTH - 1] = '\0'; // Null-terminate
          token_counter++;
          // printf("%d\n", token_counter);
        } else {
          printf("Too many Tokens, size overstepped\n");
        }
      }
    }
  }
  // Print all stored Tokens
  /*
  printf("\nStored Tokens:\n");
  for (int l = 0; l < token_counter; l++) {
    printf("%s\n", tokens[l]);
  }
  printf("\n");
  */
}
