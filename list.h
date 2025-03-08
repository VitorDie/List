#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <stdbool.h>

typedef struct list list_t;
list_t *create_list();
void list_add(node_t *node, list_t *list);
void list_add_at(node_t *node, int position, list_t *list);
bool list_is_empty(list_t *list);
node_t *list_get(int position, list_t *list);
void list_set(node_t *node, int position, list_t *list);
void list_delete(int position, list_t *list);
int list_size(list_t *list);

#endif