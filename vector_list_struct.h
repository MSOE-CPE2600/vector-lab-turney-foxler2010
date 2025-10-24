/*
 * Filename: vector_list_struct.h
 * Description: Vector List struct definition
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 10/23/25
 * Compile with: make
 */

#include "vector_struct.h"

#ifndef VECTOR_LIST_H
#define VECTOR_LIST_H

typedef struct VectorList {
    Vector *vec;
    struct VectorList *next;
    struct VectorList *prev;
} VectorList;

#endif // VECTOR_LIST_H
