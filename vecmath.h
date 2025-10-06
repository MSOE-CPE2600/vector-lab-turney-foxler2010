/*
 * Filename: vecmath.h
 * Description: Header file for vecmath.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#include "vector_struct.h"

int addvec(Vector *c, Vector *a, Vector *b);

int subvec(Vector *c, Vector *a, Vector *b);

int dotvec(Vector *c, Vector *a, Vector *b);

int crossvec(Vector *c, Vector *a, Vector *b);

int scalar_mult(Vector *c, Vector *a, double scalar);

int new_vec(Vector *new_vec, double x, double y, double z);
