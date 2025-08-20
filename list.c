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
}

list_node_t *add_node(char list_node_value[MAX_INSTRUCTION_LENGTH]) {
  list_node_t *result = malloc(sizeof(list_node_t));
  strncpy(result->list_node_value, list_node_value, MAX_INSTRUCTION_LENGTH);
  result->list_node_value[MAX_INSTRUCTION_LENGTH - 1] = '\0';
  result->next = NULL;
  return result;
}

list_node_t *append_node(list_node_t **head, list_node_t *node_to_append) {
  node_to_append->next = *head;
  *head = node_to_append;
  return node_to_append;
}

list_node_t *prefix_node(list_node_t *head, list_node_t *new_node) {
  char head_indicator[200] = "#";
  list_node_t *node_to_insert_after = find_node(head, head_indicator);
  new_node->next = node_to_insert_after->next;
  node_to_insert_after->next = new_node;
  return new_node;
}

int get_list_len(list_node_t *head) {
  int list_len = 0;

  list_node_t *temp = head;
  while (temp != NULL) {
    list_len++;
    temp = temp->next;
  }
  // printf("%i\n", list_len);
  return list_len;
}

list_node_t *get_next_node(list_node_t *head) {
  list_node_t *temp = head;
  list_node_t *next_node = temp->next;
  // printf("%s\n", next_node->list_node_value);
  return next_node;
}

char *get_next_node_value(list_node_t *head) {
  list_node_t *temp = head;
  char *next_value = malloc(strlen(temp->next->list_node_value) + 1);
  strcpy(next_value, temp->next->list_node_value);
  return next_value;
}

list_node_t *find_node(list_node_t *head, char value[MAX_INSTRUCTION_LENGTH]) {
  list_node_t *temp = head;
  while (temp != NULL) {
    if (strcmp(temp->list_node_value, "#") == 0)
      return temp;
  }
  return NULL;
}

list_node_t *reverse_list(list_node_t *head) {
  list_node_t *prev = NULL;
  list_node_t *current = head;
  list_node_t *next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  // new head
  return prev;
}

list_node_t *get_node_by_index(list_node_t *head, int list_index) {
  list_node_t *temp = head;
  int counter = 0;
  while (temp != NULL) {
    if (counter == list_index)
      return temp;
    temp = temp->next;
  }
  return NULL;
}
