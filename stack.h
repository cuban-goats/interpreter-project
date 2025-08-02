#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH 20
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct node {
  int value;
  struct node *next;
} node;

typedef node *stack;

bool push(stack *mystack, int value);
int pop(stack *mystack);

#endif
