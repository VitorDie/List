#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// vou seguir o mesmo raciocinio de vetor size 1, mas começa o indice no zero

void list_add_last(node_t *node, list_t *list);
node_t *search_node(int position, list_t *list);

struct list 
{
    int size;
    node_t *first;
    node_t *last;
};

list_t *create_list()
{
    list_t *new_list = malloc(sizeof(list_t));

    new_list->first = NULL;
    new_list->last = NULL;
    new_list->size = 0;

    return new_list;
}

void list_add(node_t *node, list_t *list)
{
    if(list_size(list) == 0)
    {
        list->first = node;
        list->last = list->first;
        list->size++;
    }
    else
    {
        node_set_next_node(node, list->first);
        node_set_back_node(list->first, node);
        list->first = node;
        list->size++;
    }
}

void list_add_at(node_t *node, int position, list_t *list)
{
    if (position < 0)
    {
        return;
    }

    if (position > list->size)
    {
        return;
    }

    if (position == 0)
    {
        list_add(node, list);
        return;
    }
    
    if (position == list->size)
    {
        list_add_last(node, list);
        return;
    }

    node_t *left_node = search_node(position, list);

    node_t *right_node = node_get_next_node(left_node);

    node_set_next_node(node, left_node);
    node_set_back_node(node, right_node);
    list->size++;
}

node_t *search_node(int position, list_t *list)
{
    node_t *node = list->first;

    for (int i = 0; i < position; ++i)
    {
        node = node_get_back_node(node);
    }

    return node;
}

void list_add_last(node_t *node, list_t *list)
{
    node_set_back_node(node, list->last);
    node_set_next_node(list->last, node);
    list->last = node;
    list->size++;
}

node_t *list_get(int position, list_t *list)
{
    if (position < 0)
    {
        return NULL;
    }

    if (position > list->size)
    {
        return NULL;
    }

    return search_node(position, list);
}

void list_set(node_t *node, int position, list_t *list)
{
    node_t *swap_it = search_node(position, list);

    node_t *left_node = node_get_back_node(swap_it);
    node_t *right_node = node_get_next_node(swap_it);

    node_set_back_node(left_node, node);
    node_set_next_node(right_node, node);
    node_set_next_node(node, left_node);
    node_set_back_node(node, right_node);

    free(swap_it);
}

void list_delete(int position, list_t *list)
{
    if (position < 0)
    {
        return;
    }

    if (position > list->size)
    {
        return;
    }

/*
    if (list->size == 1 && position != 0)
    {
        return;
    }
*/
    if (position == 0 && list->size == 1)
    {
        node_t *delete_it = list->first;
        list->first = NULL;
        list->last = NULL;
        list->size--;

        free(delete_it);
        return;
    }

    if (position == 1 && list->size == 1)
    {
        node_t *delete_it = list->first;
        list->first = NULL;
        list->last = NULL;
        list->size--;

        free(delete_it);
        return;
    }

    if (position == 0)
    {
        node_t *delete_it = search_node(position, list);

        node_t *left_node = node_get_back_node(delete_it);
        node_set_next_node(NULL,left_node);
        list->first = left_node;

        free(delete_it);
        list->size--;
        return;
    }

    if (position == list->size)
    {
        node_t *delete_it = list->last;

        node_t *right_node = node_get_next_node(delete_it);

        node_set_back_node(NULL, right_node);
        list->last = right_node;

        list->size--;
        free(delete_it);
        return;
    }

    node_t *delete_it = search_node(position, list);

    node_t *left_node = node_get_back_node(delete_it);
    node_t *right_node = node_get_next_node(delete_it);

    node_set_next_node(right_node, left_node);
    node_set_back_node(left_node, right_node);

    free(delete_it);
    list->size--;
}

int list_size(list_t *list)
{
    return list->size;
}

bool list_is_empty(list_t *list)
{
    return list->size == 0;
}