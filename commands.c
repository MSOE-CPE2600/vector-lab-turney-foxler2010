/*
 * Filename: vecmath.c
 * Description: Function definitions of non-math operations.
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 10/6/25
 * Compile with: make
 */

#include "commands.h"
#include "vector_list_tools.h"

int quit(bool *quitting, VectorList **vector_list)
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

int list(VectorList **vector_list)
{
    bool list_traversed = false;
    VectorList *current_node = *vector_list;
    if (current_node != NULL) {
        while (!list_traversed) {
            display(current_node->vec);
            if (current_node->next != NULL) {
                current_node = current_node->next;
            } else {
                list_traversed = true;
            }
        }
    } // else list is empty, don't print anything
    return 0;
}

int clear(VectorList **vector_list)
{
    bool done_clearing = false;
    VectorList *current_node = *vector_list;
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
        *vector_list = NULL;
    }
    return 0;
}

int help()
{
    printf("Usage: veclab [-h|--help]\n");
    printf("\n");
    printf("Veclab will print the help message, if the help flag is passed,\n");
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
    printf("  Saving/Loading Variables from CSV files:\n");
    printf("   memory is saved to/loaded from files in the CSV format. each row is of the form: \"varname,x,y,z\".\n");
    printf("    save [filename] : saves current memory to the file at \"filename\".\n");
    printf("    load [filename] : loads the file at [filename] into memory. current memory is cleared.\n");

    return 0;
}

int save(char *filename, VectorList **vector_list) {
    bool list_traversed = false;
    VectorList *current_node = *vector_list;
    if (current_node != NULL) {
        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            printf("error opening file\n");
            return 1;
        }
        while (!list_traversed) {
            fprintf(file, "%s,%lf,%lf,%lf\n", current_node->vec->name,
                current_node->vec->x,
                current_node->vec->y,
                current_node->vec->z);
            
            if (current_node->next != NULL) {
                current_node = current_node->next;
            } else {
                list_traversed = true;
            }
        }
        fclose(file);
    } else {
        // else list is empty, don't write anything
        printf("vector list empty; file not written.\n");
    }
    return 0;
}

int load(char *filename, VectorList **vector_list) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("error opening file\n");
        return 1;
    }
    clear(vector_list);

    bool eof = false;
    VectorList **current_node = vector_list;
    VectorList *prev_node = NULL;
    char buf[50];
    while (!eof) {
        if (fgets(buf, sizeof buf, file) == NULL) {
            eof = true;
        } else {
            char *token = strtok(buf, ",");
            init_node(current_node, prev_node, token);
            token = strtok(NULL, ",");
            if (token == NULL) {
                printf("error parsing .csv file.\n");
                clear(vector_list);
                return 1;
            }
            int return_value = sscanf(token, "%lf", &((*current_node)->vec->x));
            if (return_value <= 0) {
                printf("error parsing .csv file.\n");
                clear(vector_list);
                return 1;
            }
            token = strtok(NULL, ",");
            if (token == NULL) {
                printf("error parsing .csv file.\n");
                clear(vector_list);
                return 1;
            }
            return_value = sscanf(token, "%lf", &((*current_node)->vec->y));
            if (return_value <= 0) {
                printf("error parsing .csv file.\n");
                clear(vector_list);
                return 1;
            }
            token = strtok(NULL, ",");
            if (token == NULL) {
                printf("error parsing .csv file.\n");
                clear(vector_list);
                return 1;
            }
            return_value = sscanf(token, "%lf", &((*current_node)->vec->z));
            if (return_value <= 0) {
                printf("error parsing .csv file.\n");
                clear(vector_list);
                return 1;
            }
            // move to next node
            prev_node = *current_node;
            current_node = &((*current_node)->next);
        }
    }
    fclose(file);
    return 0;
}
