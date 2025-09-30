/*
 * Filename: vecmath.h
 * Description: Header file for vecmath.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

int addvec(Vector *a, Vector *b);

int subvec(Vector *a, Vector *b);

int dotvec(Vector *a, Vector *b);

int crossvec(Vector *a, Vector *b);

int scalar_mult(Vector *a, Vector *b);

int new_vec(Vector *a, double x, double y, double z);
