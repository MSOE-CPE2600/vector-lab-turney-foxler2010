/*
 * Filename: vecmath.c
 * Description: Function definitions of vector math operations.
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#include "vecmath.h"

int addvec(Vector *c, Vector *a, Vector *b)
{
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    c->z = a->z + b->z;
    return 0;
}

int subvec(Vector *c, Vector *a, Vector *b)
{
    c->x = a->x - b->x;
    c->y = a->y - b->y;
    c->z = a->z - b->z;
    return 0;
}

int dotvec(Vector *c, Vector *a, Vector *b)
{
    c->x = a->x * b->x;
    c->y = a->y * b->y;
    c->z = a->z * b->z;
    return 0;
}

int crossvec(Vector *c, Vector *a, Vector *b)
{
    c->x = (a->y * b->z) - (a->z * b->y);
    c->y = (a->z * b->x) - (a->x * b->z);
    c->z = (a->x * b->y) - (a->y * b->x);
    return 0;
}

int scalar_mult(Vector *c, Vector *a, double scalar)
{
    c->x = a->x * scalar;
    c->y = a->y * scalar;
    c->z = a->z * scalar;
    return 0;
}

int new_vec(Vector *new_vec, double x, double y, double z)
{
    new_vec->x = x;
    new_vec->y = y;
    new_vec->z = z;
    return 0;
}
