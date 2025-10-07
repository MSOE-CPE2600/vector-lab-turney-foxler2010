/*
 * Filename: vecmath.c
 * Description: Function definitions of non-math operations.
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 10/6/25
 * Compile with: make
 */

#include "commands.h"

int quit(bool *quitting)
{
    printf("goodbye!\n");
    *quitting = true;
    return 0;
}

int display(Vector *vec)
{
    printf("%-5s %-7.2f %-7.2f %-7.2f\n", vec->name, vec->x, vec->y, vec->z);
    return 0;
}

int list(Vector *vector_list)
{
    for (int i = 0; i < 10; i++) {
        // strcmp returns 0 if the strings match; since we want the opposite, no "!" operator is required
        if (strcmp((vector_list+i)->name, "")) {
            display(vector_list+i);
        }
    }
    return 0;
}

int clear(Vector *vector_list)
{
    // fill names with empty strings to denote unused slots
    for (int i = 0; i < 10; i++) {
        strcpy((vector_list+i)->name, "");
    }
    return 0;
}

int help()
{
    // TODO
    printf("TODO help message\n");
    return 0;
}
