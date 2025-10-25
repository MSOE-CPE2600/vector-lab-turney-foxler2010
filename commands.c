/*
 * Filename: vecmath.c
 * Description: Function definitions of non-math operations.
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 10/6/25
 * Compile with: make
 */

#include "commands.h"
#include "vector_list_tools.h"

int quit(bool *quitting, VectorList *vector_list)
{
    printf("goodbye!\n");
    clear(vector_list);
    *quitting = true;
    return 0;
}

int display(Vector *vec)
{
    printf("%-5s %-7.2f %-7.2f %-7.2f\n", vec->name, vec->x, vec->y, vec->z);
    return 0;
}

int list(VectorList *vector_list)
{
    bool list_traversed = false;
    VectorList *current_node = vector_list;
    if (current_node != NULL) {
        while (!list_traversed) {
            // strcmp returns 0 if the strings match; since we want the opposite, no "!" operator is required
            if (strcmp(current_node->vec->name, "")) {
                display(current_node->vec);
            }
        }
    } // else list is empty, don't print anything
    else {
        // TODO debug
        printf("DEBUG: (*)vector_list == null\n");
    }
    return 0;
}

int clear(VectorList *vector_list)
{
    bool done_clearing = false;
    VectorList *current_node = vector_list;
    VectorList *next_node = NULL;
    if (current_node != NULL) {
        while (!done_clearing) {
            if (current_node->next != NULL) {
                next_node = current_node->next;
            } else {
                done_clearing = true;
            }
            free_vec(&(current_node));
            if (next_node != NULL) {
                current_node = next_node;
                next_node = NULL;
            }
        }
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
