#include "stack.h"
#include <stdlib.h>

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
