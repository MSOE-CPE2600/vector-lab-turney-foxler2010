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
    Vector vector_list[10];

    Command command;
    bool quitting = false;
    while(!quitting) {
    
        /*
         * Read & Parse command
         */
        char input[100];
        printf("veclab> ");
        fgets(input, sizeof(input), stdin);
        char *token[10];
        int i = 0;
        token[i] = strtok(input, " ");
        while (token[i] != NULL) {
            printf("%s", token[i]);
            i++;
            strtok(NULL, " ");
        }

        command.operation = LIST;


        /*
         * Execute command
         */
        execute(&command, &quitting);

    }
    return EXIT_SUCCESS;
}

int execute(Command *command, bool *quitting)
{
    switch(command->operation) {
        case ADDVEC:
            addvec(&command->a, &command->b);
            break;
        case SUBVEC:
            subvec(&command->a, &command->b);
            break;
        case DOTVEC:
            dotvec(&command->a, &command->b);
            break;
        case CROSSVEC:
            crossvec(&command->a, &command->b);
            break;
        case SCALAR_MULT:
            scalar_mult(&command->a, &command->b);
            break;
        case NEW_VEC:
            new_vec(&command->a, command->x, command->y, command->z);
            break;
        case LIST:
            list();
            break;
        case CLEAR:
            clear();
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
    return 0;
}

int quit(bool *quitting)
{
    printf("quitting...\n");
    *quitting = true;
    return 0;
}

int list()
{
    // TODO
    printf("list\n");
    return 0;
}

int clear()
{
    // TODO
    printf("clear\n");
    return 0;
}

int help()
{
    // TODO
    printf("help\n");
    return 0;
}
