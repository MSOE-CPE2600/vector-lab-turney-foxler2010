/*
 * Filename: main.c
 * Description: VecLab: Vector math program that supports up to 10 3-dimensional vectors
 *              and various mathematical operations.
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#include "main.h"

int main(int argc, char *argv[])
{
    // declare token array and copy program arguments to it
    char *token[10];
    int tokenc = 0;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            strcpy(token[i-1], argv[i]);
            tokenc++;
        }
    }

    // declare vector list and call clear() to make sure that empty slots are marked correctly
    Vector vector_list[10];
    clear(vector_list);

    // TODO remove this debugging code once newvec() works
    strcpy(vector_list[0].name, "abc");
    vector_list[0].x = 1;
    vector_list[0].y = 2;
    vector_list[0].z = 3;

    strcpy(vector_list[3].name, "d");
    vector_list[1].x = 4;
    vector_list[1].y = 5;
    vector_list[1].z = 6;

    strcpy(vector_list[2].name, "ef");
    vector_list[2].x = 7;
    vector_list[2].y = 8;
    vector_list[2].z = 9;

    Command command;
    bool quitting = false;
    while(!quitting) {
    
        /*
         * Read command
         */

        // if the program doesn't have any input tokens yet, prompt the user
        if (tokenc == 0) {
            char input[100];
            printf("veclab> ");
            fgets(input, sizeof(input), stdin);
            int i = 0;
            token[i] = strtok(input, " ");
            while (token[i] != NULL) {
                i++;
                token[i] = strtok(NULL, " ");
            }
        }
        

        /*
         * Parse command
         */
        

        // ensures old input tokens are discarded upon next iteration
        tokenc = 0;

        /*
         * Execute command
         */
        execute(&quitting, command, vector_list);

    }
    return EXIT_SUCCESS;
}

int execute(bool *quitting, Command command, Vector *vector_list)
{
    // determine what to do based on the operation specified
    switch(command.operation) {
        case ADDVEC:
            addvec(command.c, command.a, command.b);
            break;
        case SUBVEC:
            subvec(command.c, command.a, command.b);
            break;
        case DOTVEC:
            dotvec(command.c, command.a, command.b);
            break;
        case CROSSVEC:
            crossvec(command.c, command.a, command.b);
            break;
        case SCALAR_MULT:
            scalar_mult(command.c, command.a, command.x);
            break;
        case NEW_VEC:
            new_vec(command.c, command.x, command.y, command.z);
            break;
        case DISPLAY:
            display(command.a);
            break;
        case LIST:
            list(vector_list);
            break;
        case CLEAR:
            clear(vector_list);
            break;
        case HELP:
            help();
            break;
        case QUIT:
            quit(quitting);
            break;
        default:
            help();
    }

    // after executing, display the output
    // could be either "varname = 1 2 3", or "ans = 1 2 3" depending on if the user specified an output varname.
    display(command.c);
    return 0;
}

int quit(bool *quitting)
{
    printf("quitting...\n");
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
