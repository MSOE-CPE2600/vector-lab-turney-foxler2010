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
    // declare token array/count and copy program arguments to it
    char token[10][10];
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

            // tokenize
            int i = 0;
            bool eof = false;
            while (!eof) {
                // store token to buffer so we can check for NULL
                char *buf;
                if (i == 0) {
                    buf = strtok(input, " ");
                } else {
                    buf = strtok(NULL, " ");
                }
                if (buf == NULL) {
                    // no more tokens in input string; break the loop.
                    eof = true;
                    // remove newline from the last token
                    token[i-1][strlen(token[i-1])-1] = '\0';
                } else {
                    // latest token is a string; store it to the tokens array
                    strcpy(token[i], buf);
                    tokenc++;
                }
                i++;
            }
        }

        /*
         * Parse command
         */
        if (tokenc == 1) {
            if (!strcmp(token[0], "clear")) {
                command.operation = CLEAR;
            } else if (!strcmp(token[0], "list")) {
                command.operation = LIST;
            } else if (!strcmp(token[0], "quit")) {
                command.operation = QUIT;
            } else {
                bool var_found = false;
                int i = 0;
                while(!var_found && i < 10) {
                    if (!strcmp(token[0], vector_list[i].name)) {
                        command.operation = DISPLAY;
                        command.a = &(vector_list[i]);
                        var_found = true;
                    }
                    i++;
                }
                if (!var_found) {
                    printf("no var named \"%s\" found.\n", token[0]);
                    // skip execution this time around, and just prompt the user again immediately
                    command.operation = NO_OP;
                }
            }
        }

        // ensures old input tokens are discarded upon next iteration
        tokenc = 0;        

        /*
         * Execute command
         */
        execute(&quitting, command, vector_list);

        // set command.operation to NO_OP to prevent anything from being repeated,
        // if operation does not get set during the next parsing stage.
        command.operation = NO_OP;
    }

    return EXIT_SUCCESS;
}

int read(int tokenc, char token[10][10])
{
    // TODO
    return 0;
}

int parse(int *tokenc, char token[10][10], Command *command, Vector vector_list[])
{
    // TODO
    return 0;
}

int execute(bool *quitting, Command command, Vector *vector_list)
{
    // determine what to do based on the operation specified
    switch(command.operation) {
        case ADDVEC:
            addvec(command.c, command.a, command.b);
            display(command.c);
            break;
        case SUBVEC:
            subvec(command.c, command.a, command.b);
            display(command.c);
            break;
        case DOTVEC:
            dotvec(command.c, command.a, command.b);
            display(command.c);
            break;
        case CROSSVEC:
            crossvec(command.c, command.a, command.b);
            display(command.c);
            break;
        case SCALAR_MULT:
            scalar_mult(command.c, command.a, command.x);
            display(command.c);
            break;
        case NEW_VEC:
            new_vec(command.c, command.x, command.y, command.z);
            display(command.c);
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
        case NO_OP:
            // do nothing
            break;
        default:
            // do nothing
    }
    return 0;
}
