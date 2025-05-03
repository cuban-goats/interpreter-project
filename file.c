#include <stdio.h>
#include <string.h>
#include "file.h"


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
