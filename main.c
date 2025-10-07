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
    vector_list[3].x = 4;
    vector_list[3].y = 5;
    vector_list[3].z = 6;

    strcpy(vector_list[2].name, "ef");
    vector_list[2].x = 7;
    vector_list[2].y = 8;
    vector_list[2].z = 9;

    Command command;
    bool quitting = false;
    while (!quitting) {
        /*
         * Read command
         */
        if (tokenc == 0) { // if the program doesn't have any input tokens yet, prompt the user
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
            /*
             * Non-math ops
             */
            if (!strcmp(token[0], "clear")) {
                command.operation = CLEAR;
            } else if (!strcmp(token[0], "list")) {
                command.operation = LIST;
            } else if (!strcmp(token[0], "quit")) {
                command.operation = QUIT;
            } else {
                command.operation = DISPLAY;
                // TODO debug
                printf("parsing var %s\n", token[0]);
                parse_var(&(command.a), &(command.operation), token[0], vector_list);
                printf("parse_var returned. pointer to command.a: %p\n", command.a);
            }
        } else if (tokenc == 5 && !strcmp(token[1], "=")) {
            /*
             * Math op & output to vec, or new_vec
             */
            if (!strcmp(token[3], "+")) {
                command.operation = ADDVEC;
                parse_var(&(command.c), &(command.operation), token[0], vector_list);
                parse_var(&(command.a), &(command.operation), token[2], vector_list);
                parse_var(&(command.b), &(command.operation), token[4], vector_list);
            } else if (!strcmp(token[3], "-")) {
                command.operation = SUBVEC;
                parse_var(&(command.c), &(command.operation), token[0], vector_list);
                parse_var(&(command.a), &(command.operation), token[2], vector_list);
                parse_var(&(command.b), &(command.operation), token[4], vector_list);
            } else if (!strcmp(token[3], "*")) {
                // TODO scalar in "a" arg
                command.operation = DOTVEC;
                parse_var(&(command.c), &(command.operation), token[0], vector_list);
                parse_var(&(command.a), &(command.operation), token[2], vector_list);
                parse_var(&(command.b), &(command.operation), token[4], vector_list);
                if (command.operation == NO_OP) { // last arg is not a var, could be a scalar
                    if (1) { // TODO check that last arg is a double
                        command.operation = SCALAR_MULT;
                    } // else not dotvec or scalar_mult, leave it at NO_OP
                }
            } else if (!strcmp(token[3], "x")) {
                command.operation = CROSSVEC;
                parse_var(&(command.c), &(command.operation), token[0], vector_list);
                parse_var(&(command.a), &(command.operation), token[2], vector_list);
                parse_var(&(command.b), &(command.operation), token[4], vector_list);
            } else { // 5 tokens and not a math op means new_vec
                if (1) { // TODO still need to check that tokens are all doubles
                    command.operation = NEW_VEC;
                }
            }
        } else if (tokenc == 4) {
            Vector ans = {"ans"};
            command.c = &ans;
            if (!strcmp(token[1], "+")) {
                command.operation = ADDVEC;
                parse_var(&(command.a), &(command.operation), token[0], vector_list);
                parse_var(&(command.b), &(command.operation), token[2], vector_list);
            } else if (!strcmp(token[1], "-")) {
                command.operation = SUBVEC;
                parse_var(&(command.a), &(command.operation), token[0], vector_list);
                parse_var(&(command.b), &(command.operation), token[2], vector_list);
            } else if (!strcmp(token[1], "*")) {
                // TODO scalar in "a" arg
                command.operation = DOTVEC;
                parse_var(&(command.a), &(command.operation), token[0], vector_list);
                parse_var(&(command.b), &(command.operation), token[2], vector_list);
                if (command.operation == NO_OP) { // last arg is not a var, could be a scalar
                    if (1) { // TODO check that last arg is a double
                        command.operation = SCALAR_MULT;
                    } // else not dotvec or scalar_mult, leave it at NO_OP
                }
            } else if (!strcmp(token[1], "x")) {
                command.operation = CROSSVEC;
                parse_var(&(command.a), &(command.operation), token[0], vector_list);
                parse_var(&(command.b), &(command.operation), token[2], vector_list);
            }
        } else {
            printf("invalid command.\n");
            command.operation = NO_OP;
        }

        // ensures old input tokens are discarded upon next iteration
        tokenc = 0;

        // TODO debug
        printf("parsing complete!!\n");

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

int parse_var(Vector **arg, Operation *operation, char *token, Vector *vector_list)
{
    // see if the token is a varname, and if so assign it to command.a.
    // otherwise, print error and set operation to NO_OP
    bool var_found = false;
    int i = 0;
    while(!var_found && i < 10) {
        // TODO debug
        printf("checking %s against vector_list[%d] (%s)\n", token, i, vector_list[i].name);
        if (!strcmp(token, vector_list[i].name)) {
            // TODO debug
            printf("Match!\n");
            printf("pointer to list entry: %p\n", &(vector_list[i]));
            *arg = &(vector_list[i]);
            // TODO debug
            printf("assign success!\n");
            printf("pointer to arg: %p\n", *arg);
            var_found = true;
        }
        i++;
    }
    if (!var_found) {
        printf("no var named \"%s\" found.\n", token);
        // skip execution this time around, and just prompt the user again immediately
        *operation = NO_OP;
    }
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
            // TODO debug
            printf("operation = DISPLAY\n");
            printf("to display: %p\n", command.a);
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
            // TODO debug
            printf("operation = NO_OP\n");
            // do nothing
            break;
        default:
            // TODO debug
            printf("ERROR: default case used!!!\n");
            // do nothing
    }
    return 0;
}
