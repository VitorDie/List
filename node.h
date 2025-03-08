#ifndef NODE_H
#define NODE_H

typedef struct node node_t;
node_t *create_node(int value);
void node_set_value(int value, node_t *node);
void node_set_next_node(node_t *next_node, node_t *node);
int node_get_value(node_t *node);
node_t *node_get_next_node(node_t *node);
void node_set_back_node(node_t *back_node, node_t *node);
node_t *node_get_back_node(node_t *node);

#endif