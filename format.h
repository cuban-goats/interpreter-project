#ifndef FORMAT_H
#define FORMAT_H

#define ROWS 50
#define COLS 100

#define MAX_OPCODE 20 // Maximum opcode per row
// for clean opcode
#define CLEAN_ROWS 50
#define MAX_CLEAN_OPCODE 20
#define CLEAN_COLS 100

void split_and_store(char program[ROWS][COLS], int line_count,
                     char opcode[ROWS][MAX_OPCODE][COLS]);
void remove_spaces(char opcode[ROWS][MAX_OPCODE][COLS],
                   char clean_opcode[CLEAN_ROWS][MAX_CLEAN_OPCODE][CLEAN_COLS]);
#endif
