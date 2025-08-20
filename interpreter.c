#include "file.h"
#include "format.h"
#include "list.h"
#include "parse.h"
#include "run.h"
#include "sort.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    return 1;
  }

  const char *fileName = argv[1]; // Get filepath
  char program[ROWS][COLS];       // Declare the array
  FILE *filepointer = NULL;

  // Open the file
  if (open_file(fileName, &filepointer) != 0) {
    return 1;
  }

  // Read the file and store lines
  int line_count = 0;
  read_file(filepointer, program, &line_count);

  // split and store the contents of the file
  char opcode[ROWS][MAX_OPCODE][COLS] = {0}; // Fixed-size 3D array
  split_and_store(program, line_count, opcode);

  // Close the file
  fclose(filepointer);

  // list of all labels and tokens
  char labels[MAX_LABELLENGTH][MAX_LABELS];
  char tokens[MAX_TOKENLENGTH][MAX_TOKENS];

  // is just the pointer to opcode
  char *instruction[ROWS][MAX_OPCODE][COLS];

  // store labels and tokens in an array;
  get_labels(labels, opcode);
  get_tokens(tokens, opcode);

  // char runner[MAX_INSTRUCTIONS][MAX_INSTRUCTION_LENGTH];
  int label_tracker[MAX_LABELS];
  int token_counter = 0;

  printf("\n");

  // initialize a stack
  stack s1 = NULL;

  // run(tokens, s1);
  list_node_t *head = parse(opcode, label_tracker, token_counter);
  print_list(head);
  run_ll(head, s1);

  return 0;
}

// Function to print the full opcode and labels
void print_opcode(char opcode[ROWS][MAX_OPCODE][COLS], int line_count) {
  printf("Full Opcode and Labels: \n");
  for (int i = 0; i < line_count; i++) {
    for (int j = 0; j < MAX_OPCODE; j++) {
      if (opcode[i][j][0] != '\0') { // Only print if the instruction exists
        printf("%s\n", opcode[i][j]);
      }
    }
  }
}
