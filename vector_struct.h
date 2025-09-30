/*
 * Filename: vector_struct.h
 * Description: Vector struct definition
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    char name[30];
    double x;
    double y;
    double z;
} Vector;

#endif // VECTOR_H
