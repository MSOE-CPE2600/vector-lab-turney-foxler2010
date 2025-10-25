/*
 * Filename: vector_list_tools.h
 * Description: Header file for vector_list_tools.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 10/24/25
 * Compile with: make
 */

#include "vector_list_struct.h"

int init_node(VectorList **node, VectorList *prev, char *name);

int free_vec(VectorList **node);
