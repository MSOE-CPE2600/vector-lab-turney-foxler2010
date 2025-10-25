/*
 * Filename: vector_list_tools.c
 * Description: Tools for managing the vector list
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 10/24/25
 * Compile with: make
 */

#include <stdlib.h>
#include <string.h>
#include "vector_list_tools.h"

int init_node(VectorList **node, VectorList *prev, char *name)
{
    *node = malloc(sizeof(VectorList));
    (*node)->vec = malloc(sizeof(Vector));
    strcpy((*node)->vec->name, name);
    (*node)->next = NULL;
    (*node)->prev = prev;
    return 0;
}

int free_vec(VectorList **node)
{
    free((*node)->vec);
    free(*node);
    return 0;
}
