#include <stdio.h>

#ifndef FILE_H

#define ROWS 50
#define COLS 100

int open_file(const char *fileName, FILE **filepointer);
void read_file(FILE *filepointer, char program[ROWS][COLS], int *line_count);

#endif
