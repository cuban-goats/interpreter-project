#include <stdio.h>
#include <string.h>
#include "file.h"
#include "format.h"
#include "parse.h"
#include "sort.h"
#include "stack.h"
#include "run.h"
#include "list.h"

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
  
  // not done yet because of copying into program array
  char runner[MAX_INSTRUCTIONS][MAX_INSTRUCTION_LENGTH];
  int label_tracker[MAX_LABELS];
  int token_counter;
  parse(opcode, runner, label_tracker, token_counter);

  printf("\n");
  // Print the full opcode
  // print_opcode(opcode, line_count);

  // initialize a stack
  stack s1 = NULL;

  // run(tokens, s1);
  
  list_node_t *head = NULL;
  list_node_t *temp;
  strcpy(runner[0], "0");
  strcpy(runner[1], "1");

  temp = add_node(runner[0]);
  append_node(&head, temp);
  temp = add_node(runner[1]);
  append_node(&head, temp);
  print_list(head);

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
