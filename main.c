#include "node.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void free_list(list_t *list)
{
    while(list_size(list) > 0)
    {
        list_delete(list_size(list), list);
    }
}

int main()
{
    list_t *list = create_list();
    
    node_t *n1 = create_node(1);

    list_add(n1, list);
    assert(list_get(0, list) == n1);
    assert(list_size(list) == 1);
    list_delete(0, list);
    assert(list_get(0, list) == NULL);
    assert(list_size(list) == 0);

    node_t *n2 = create_node(2);
    node_t *n3 = create_node(3);
    node_t *n4 = create_node(4);

    list_add(n2, list);
    list_add(n3, list);
    list_add(n4, list);

    assert(list_size(list) == 3);

    assert(list_get(1, list) == n3);

    list_delete(1, list);

    assert(list_get(1, list) == n2);
    assert(list_get(0, list) == n4 );

    free_list(list);

    assert(list_size(list) == 0);


    free(list);
    return 0;
}