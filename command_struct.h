/*
 * Filename: command_struct.h
 * Description: Command struct definition
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#include "vector_struct.h"
#include "operation.h"

#ifndef COMMAND_H
#define COMMAND_H

typedef struct Command {
    Operation operation;
    // these are pointers so that any writes go straight to vector_list and not some intermediary
    Vector *a;
    Vector *b;
    Vector *c;
    double x;
    double y;
    double z;
    char filename[30];
} Command;

#endif // COMMAND_H
