#ifndef PARSE_H

#define ROWS 50
#define COLS 100

#define MAX_OPCODE 20 // Maximum opcode per row

#define MAX_LABELLENGTH 10
#define MAX_LABELS 10
#define MAX_TOKENS 200
#define MAX_TOKENLENGTH 200
#define MAX_INSTRUCTIONS 200

#define MAX_STR_LENGTH 10

void parse(char opcode[ROWS][MAX_OPCODE][COLS]);

#endif // !PARSE_H
