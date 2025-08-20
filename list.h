#ifndef LIST_H
#define LIST_H

#define MAX_INSTRUCTION_LENGTH 200

typedef struct list_node {
  char list_node_value[MAX_INSTRUCTION_LENGTH];
  struct list_node *next;
} list_node_t;
// head points to the beginning of the list
void print_list(list_node_t *head);
list_node_t *add_node(char list_node_value[MAX_INSTRUCTION_LENGTH]);
list_node_t *append_node(list_node_t **head, list_node_t *list_node);
list_node_t *prefix_node(list_node_t *head, list_node_t *list_node);
int get_list_len(list_node_t *head);
list_node_t *get_next_node(list_node_t *head);
char *get_next_node_value(list_node_t *head);
list_node_t *find_node(list_node_t *head, char value[MAX_INSTRUCTION_LENGTH]);
list_node_t *reverse_list(list_node_t *head);
list_node_t *get_node_by_index(list_node_t *head, int list_index);

#endif // !LIST_H
