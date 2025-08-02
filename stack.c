#include "stack.h"
#include <stdlib.h>

/*
bool push(stack *mystack, int value) {
  if (mystack->top >= STACK_LENGTH - 1)
    return false;

  mystack->top++;
  mystack->stack_values[mystack->top] = value;
  return true;
}

bool pop(stack *mystack) {
  if (mystack->top == EMPTY)
    return false;

  int result = mystack->stack_values[mystack->top];
  mystack->top--;
  return true;
}
*/

typedef node *stack;

bool push(stack *mystack, int value) {
  node *newnode = malloc(sizeof(node));
  if (newnode == NULL)
    return false;
  newnode->value = value;
  newnode->next = *mystack;
  *mystack = newnode;
  return true;
}

int pop(stack *mystack) {
  if (*mystack == NULL)
    return STACK_EMPTY;

  int result = (*mystack)->value;
  node *tmp = *mystack;
  *mystack = (*mystack)->next;
  free(tmp);
  return result;
}

/*
int main() {
  stack stack_one = NULL;
  push(&stack_one, 20);
  return 0;
}
*/
