/*
 * Filename: vecmath.c
 * Description: Function definitions of vector math operations.
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#include "vector_struct.h"

int addvec(Vector *a, Vector *b)
{
    // TODO
    printf("addvec: a: %f %f %f, b: %f %f %f\n", a->x, a->y, a->z, b->x, b->y, b->z);
    return 0;
}

int subvec(Vector *a, Vector *b)
{
    // TODO
    printf("subvec: a: %f %f %f, b: %f %f %f\n", a->x, a->y, a->z, b->x, b->y, b->z);
    return 0;
}

int dotvec(Vector *a, Vector *b)
{
    // TODO
    printf("dotvec: a: %f %f %f, b: %f %f %f\n", a->x, a->y, a->z, b->x, b->y, b->z);
    return 0;
}

int crossvec(Vector *a, Vector *b)
{
    // TODO
    printf("crossvec: a: %f %f %f, b: %f %f %f\n", a->x, a->y, a->z, b->x, b->y, b->z);
    return 0;
}

int scalar_mult(Vector *a, Vector *b)
{
    // TODO
    printf("scalar_mult: a: %f %f %f, b: %f %f %f\n", a->x, a->y, a->z, b->x, b->y, b->z);
    return 0;
}

int new_vec(Vector *a, double x, double y, double z)
{
    printf("newvec: %f %f %f", x, y, z);
    a->x = x;
    a->y = y;
    a->z = z;
    return 0;
}
