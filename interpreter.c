#include "file.h"
#include "format.h"
#include "sort.h"
#include "parse.h"


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

  // char clean_opcode[CLEAN_ROWS][MAX_CLEAN_OPCODE][CLEAN_COLS] = {};
  // remove_spaces(opcode, clean_opcode);

  // get labels and print it
  char labels[MAX_LABELLENGTH][MAX_LABELS];
  char tokens[MAX_TOKENLENGTH][MAX_TOKENS];

  // is just the pointer to opcode
  char *instruction[ROWS][MAX_OPCODE][COLS];
  get_labels(labels, opcode);
  get_tokens(tokens, opcode);

  parse(opcode);

  printf("\n");
  // Print the full opcode
  // print_opcode(opcode, line_count);

  // Close the file
  fclose(filepointer);

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
