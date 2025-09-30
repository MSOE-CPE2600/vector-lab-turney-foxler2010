/*
 * Filename: command_struct.h
 * Description: Command struct definition
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#include "vector_struct.h"
#include "operation.h"

typedef struct Command {
    Operation operation;
    Vector a;
    Vector b;
    double x;
    double y;
    double z;
} Command;
