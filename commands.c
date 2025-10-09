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
    printf("Usage: veclab [-h|--help] [command]\n");
    printf("    where \"command\" is a valid veclab command.\n");
    printf("\n");
    printf("Veclab will run the command given in the program arguments, if there is one,\n");
    printf("and then open a prompt where more commands can be entered interactively.\n");
    printf("\n");
    printf("Commands:\n");
    printf("  Informational:\n");
    printf("    list  : lists variables in memory (max 10)\n");
    printf("    clear : clears memory\n");
    printf("    quit  : exits the program\n");
    printf("    help  : displays this message\n");
    printf("  Assigning Variables:\n");
    printf("    varname = x y z\n");
    printf("    varname = expression\n");
    printf("  Expressions:\n");
    printf("   all expressions print the result to the console,\n");
    printf("   unless prefixed with an assignment.\n");
    printf("    a + b : add two vectors\n");
    printf("    a - b : subtract two vectors\n");
    printf("    a * b : dot product of two vectors\n");
    printf("    a x b : cross product of two vectors\n");
    printf("    a * scalar : product of a vector and a scalar quantity\n");
    return 0;
}
