#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// in main() declare a list_node_t *temp
// declare list_node_t headpointer to NULL

void print_list(list_node_t *head) {
  list_node_t *temp = head;
  while (temp != NULL) {
    printf("%s - ", temp->list_node_value);
    temp = temp->next;
  }
  printf("\n");
};

list_node_t *add_node(char list_node_value[MAX_INSTRUCTION_LENGTH]) {
  list_node_t *result = malloc(sizeof(list_node_t));
  strncpy(result->list_node_value, list_node_value, MAX_INSTRUCTION_LENGTH);
  result->list_node_value[MAX_INSTRUCTION_LENGTH - 1] = '\0';
  result->next = NULL;
  return result;
};

list_node_t *append_node(list_node_t **head, list_node_t *node_to_append) {
  node_to_append->next = *head;
  *head = node_to_append;
  return node_to_append;
};
