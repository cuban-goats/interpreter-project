#include <stdbool.h>

#define STACK_LENGTH 20
#define EMPTY (-1)

typedef struct {
  int stack_values[STACK_LENGTH];
  int top;
} stack;

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

int main() {
  stack stack_one;
  stack_one.top = -1;
  push(&stack_one, 20);
  return 0;
}
