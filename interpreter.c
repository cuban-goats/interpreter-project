#include <stddef.h>
#include <stdio.h>
#include <stdlib.h> // For malloc
#include <string.h>

#define ROWS 50
#define MAX_OPCODE 20 // Maximum opcode per row
#define COLS 100
// for clean opcode
#define CLEAN_ROWS 50
#define MAX_CLEAN_OPCODE 20
#define CLEAN_COLS 100

#define MAX_LABELLENGTH 10
#define MAX_LABELS 10
#define MAX_TOKENS 200
#define MAX_TOKENLENGTH 200
#define MAX_INSTRUCTIONS 200

#define MAX_STR_LENGTH 10

// Function prototypes
int open_file(const char *fileName, FILE **filepointer);
void read_file(FILE *filepointer, char program[ROWS][COLS], int *line_count);
void split_and_store(char program[ROWS][COLS], int line_count,
                     char opcode[ROWS][MAX_OPCODE][COLS]);
void remove_spaces(char opcode[ROWS][MAX_OPCODE][COLS],
                   char clean_opcode[CLEAN_ROWS][MAX_CLEAN_OPCODE][CLEAN_COLS]);
void get_labels(char labels[MAX_LABELLENGTH][MAX_LABELS],
                char opcode[ROWS][MAX_OPCODE][COLS]);
void get_tokens(char tokens[MAX_TOKENLENGTH][MAX_TOKENS],
                char opcode[ROWS][MAX_OPCODE][COLS]);
void parse(char opcode[ROWS][MAX_OPCODE][COLS]);
void print_opcode(char opcode[ROWS][MAX_OPCODE][COLS], int line_count);

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

// Function to open the file and check for errors
int open_file(const char *fileName, FILE **filepointer) {
  *filepointer = fopen(fileName, "r");
  if (*filepointer == NULL) {
    perror("Error opening file");
    return 1;
  }
  return 0;
}

// Function to read the file line by line into the program array
void read_file(FILE *filepointer, char program[ROWS][COLS], int *line_count) {
  while (fgets(program[*line_count], COLS, filepointer) != NULL) {
    // Remove newline if present
    size_t len = strlen(program[*line_count]);
    if (len > 0 && program[*line_count][len - 1] == '\n') {
      program[*line_count][len - 1] = '\0';
    }
    (*line_count)++;

    if (*line_count >= ROWS) {
      printf("Warning: More lines than ROWS. Some data might be truncated.\n");
      break;
    }
  }
}

// Function to split and store the content of the program array
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
// function to copy labels into new array

void get_labels(char labels[MAX_LABELLENGTH][MAX_LABELS],
                char opcode[ROWS][MAX_OPCODE][COLS]) {
  // To keep track of where to store the labels in the array
  int labels_index = 0;

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
  printf("\nStored Labels:\n");
  for (int m = 0; m < labels_index; m++) {
    printf("%s (index %d)\n", labels[m], label_tracker[m]);
  }
  printf("\n");
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
  // Print all stored labels
  printf("\nStored Tokens:\n");
  for (int l = 0; l < token_counter; l++) {
    printf("%s\n", tokens[l]);
  }
  printf("\n");
}

void parse(char opcode[ROWS][MAX_OPCODE][COLS]) {
  // count number of tokens (to get indexes)
  int token_counter = 0;

  // to track on which index a label is
  int label_tracker[MAX_LABELS] = {};

  int label_count = 0;

  char program[] = {};
  
  char *endptr;

  char string_literal[MAX_STR_LENGTH];
  char label[MAX_STR_LENGTH];

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < MAX_OPCODE; j++) {
      // skip empty values
      if (strcmp(opcode[i][j], "\0") == 1) {
        printf("empty value at: i=%i, j=%i", i, j);
        continue;
      }
      // Labels (no solutin yet)
      if (strchr(opcode[i][j], ':') != NULL) {
        // label_tracker[opcode without ":"] = index
        // value of opcode as key to get values for specific labels
      }
      // PUSH, the next token must be a number
      if (strcmp(opcode[i][j], "PUSH") == 0) {
        int number = strtol(opcode[i][j+1], &endptr, 10);
        printf("Number after PUSH: %i \n", number);
      }
      // PRINT, the next token must be a string 
      else if (strcmp(opcode[i][j], "PRINT") == 0) {
        strcpy(string_literal, opcode[i][j+1]);
        printf("String after PRINT: %s \n", string_literal);
      }
      else if (strcmp(opcode[i][j], "JUMP.EQ.0") == 0) {
        strcpy(label, opcode[i][j+1]);
        printf("Label after JUMP.EQ.0: %s \n", label);
      }
      else if (strcmp(opcode[i][j], "JUMP.GT.0") == 0) {
        strcpy(label, opcode[i][j+1]);
        printf("Label after JUMP.GT.0: %s \n", label);
      }
    }
  }
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
