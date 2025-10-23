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
    /*
     * Parse program arguments
     */
    bool help_flag = false;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
                help_flag = true;
            }
        }
    }

    /*
     * Vars that are reused every iteration
     */
    int tokenc;
    char token[MAX_TOKENS][TOKEN_LENGTH];
    Command command;
    bool quitting = false;
    // TODO malloc-ify
    Vector vector_list[10];
    // call clear() to make sure that empty slots are marked correctly
    clear(vector_list);

    /*
     * Main loop
     */
    while (!quitting) {
        /*
         * Read command
         */
        read(&tokenc, &token, help_flag);

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
            } else if (!strcmp(token[0], "help") || help_flag) {
                command.operation = HELP;
                help_flag = false;
            } else {
                command.operation = DISPLAY;
                parse_var(&(command.a), &(command.operation), token[0], vector_list, false);
            }
        } else if (tokenc == 5 && !strcmp(token[1], "=")) {
            /*
             * Math op & output to vec, or new_vec
             */
            if (!strcmp(token[3], "+")) {
                command.operation = ADDVEC;
                parse_new_vec(&(command.c), &(command.operation), token[0], vector_list);
                parse_var(&(command.a), &(command.operation), token[2], vector_list, false);
                parse_var(&(command.b), &(command.operation), token[4], vector_list, false);
            } else if (!strcmp(token[3], "-")) {
                command.operation = SUBVEC;
                parse_new_vec(&(command.c), &(command.operation), token[0], vector_list);
                parse_var(&(command.a), &(command.operation), token[2], vector_list, false);
                parse_var(&(command.b), &(command.operation), token[4], vector_list, false);
            } else if (!strcmp(token[3], "*")) {
                bool first_token_scalar = false;
                command.operation = DOTVEC;
                parse_var(&(command.a), &(command.operation), token[2], vector_list, true);
                if (command.operation == NO_OP) { // first arg token is not a var, could be a scalar
                    int return_value = sscanf(token[2], "%lf", &(command.x));
                    if (return_value > 0) {
                        // if sscanf was successful (i.e. not 0 or EOF),
                        // then this is a scalar_mult
                        command.operation = SCALAR_MULT;
                        // set this bool, so that if both argument tokens are scalars it realizes the error
                        first_token_scalar = true;
                    } else {
                        printf("invalid command.\n");
                        // and leave operation as NO_OP
                    }
                }
                if (first_token_scalar) {
                    parse_var(&(command.a), &(command.operation), token[4], vector_list, true);
                } else {
                    parse_var(&(command.b), &(command.operation), token[4], vector_list, true);
                }
                if (command.operation == NO_OP) { // last token is not a var, could be a scalar
                    int return_value = sscanf(token[4], "%lf", &(command.x));
                    if (return_value > 0 && !first_token_scalar) {
                        // if last token is scalar and first token is NOT scalar (must be a var),
                        // then this is a scalar_mult
                        command.operation = SCALAR_MULT;
                    } else {
                        printf("invalid command.\n");
                        // and leave operation as NO_OP
                    }
                }
                parse_new_vec(&(command.c), &(command.operation), token[0], vector_list);
            } else if (!strcmp(token[3], "x")) {
                command.operation = CROSSVEC;
                parse_new_vec(&(command.c), &(command.operation), token[0], vector_list);
                parse_var(&(command.a), &(command.operation), token[2], vector_list, false);
                parse_var(&(command.b), &(command.operation), token[4], vector_list, false);
            } else { // 5 tokens and not a math op means new_vec
                command.operation = NEW_VEC;
                int return_value = sscanf(token[2], "%lf", &(command.x));
                if (return_value <= 0) {
                    printf("invalid command.\n");
                    command.operation = NO_OP;
                }
                return_value = sscanf(token[3], "%lf", &(command.y));
                if (return_value <= 0) {
                    printf("invalid command.\n");
                    command.operation = NO_OP;
                }
                return_value = sscanf(token[4], "%lf", &(command.z));
                if (return_value <= 0) {
                    printf("invalid command.\n");
                    command.operation = NO_OP;
                }
                parse_new_vec(&(command.c), &(command.operation), token[0], vector_list);
            }
        } else if (tokenc == 3) {
            Vector ans = {"ans"};
            command.c = &ans;
            if (!strcmp(token[1], "+")) {
                command.operation = ADDVEC;
                parse_var(&(command.a), &(command.operation), token[0], vector_list, false);
                parse_var(&(command.b), &(command.operation), token[2], vector_list, false);
            } else if (!strcmp(token[1], "-")) {
                command.operation = SUBVEC;
                parse_var(&(command.a), &(command.operation), token[0], vector_list, false);
                parse_var(&(command.b), &(command.operation), token[2], vector_list, false);
            } else if (!strcmp(token[1], "*")) {
                bool first_token_scalar = false;
                command.operation = DOTVEC;
                parse_var(&(command.a), &(command.operation), token[0], vector_list, true);
                if (command.operation == NO_OP) { // first token is not a var, could be a scalar
                    int return_value = sscanf(token[0], "%lf", &(command.x));
                    if (return_value > 0) {
                        // if sscanf was successful (i.e. not 0 or EOF),
                        // then this is a scalar_mult
                        command.operation = SCALAR_MULT;
                        // set this bool, so that if both argument tokens are scalars it realizes the error
                        first_token_scalar = true;
                    } else {
                        printf("invalid command.\n");
                        // and leave operation as NO_OP
                    }
                }
                if (first_token_scalar) {
                    parse_var(&(command.a), &(command.operation), token[2], vector_list, true);
                } else {
                    parse_var(&(command.b), &(command.operation), token[2], vector_list, true);
                }
                if (command.operation == NO_OP) { // last token is not a var, could be a scalar
                    int return_value = sscanf(token[2], "%lf", &(command.x));
                    if (return_value > 0 && !first_token_scalar) {
                        // if last token is scalar and first token is NOT scalar (must be a var),
                        // then this is a scalar_mult
                        command.operation = SCALAR_MULT;
                    } else {
                        printf("invalid command.\n");
                        // and leave operation as NO_OP
                    }
                }
            } else if (!strcmp(token[1], "x")) {
                command.operation = CROSSVEC;
                parse_var(&(command.a), &(command.operation), token[0], vector_list, false);
                parse_var(&(command.b), &(command.operation), token[2], vector_list, false);
            } else {
                printf("invalid command.\n");
                command.operation = NO_OP;
            }
        } else {
            printf("invalid command.\n");
            command.operation = NO_OP;
        }

        /*
         * Execute command
         */
        execute(&quitting, command, vector_list);
    }

    return EXIT_SUCCESS;
}

int read(int *tokenc, char (*token)[MAX_TOKENS][TOKEN_LENGTH], bool help_flag)
{
    *tokenc = 0;
    if (!help_flag) {
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
                (*token)[i-1][strlen((*token)[i-1])-1] = '\0';
            } else {
                // latest token is a string; store it to the tokens array
                strcpy((*token)[i], buf);
                (*tokenc)++;
            }
            i++;
        }
    } else { // help flag set
        // set tokenc to 1 to make sure that the parser gets to the help flag condition check
        // this is a quick fix to prevent me having to mess with the parser
        *tokenc = 1;
    }
    return 0;
}

int parse_var(Vector **arg, Operation *operation, char *token, Vector *vector_list, bool skip_error_message)
{
    // see if the token is a varname, and if so assign it to command.a.
    // otherwise, print error and set operation to NO_OP
    bool var_found = false;
    int i = 0;
    while(!var_found && i < 10) {
        if (!strcmp(token, vector_list[i].name)) {
            *arg = &(vector_list[i]);
            var_found = true;
        }
        i++;
    }
    if (!var_found) {
        if (!skip_error_message) {
            printf("no var named \"%s\" found.\n", token);
        }
        // skip execution this time around, and just prompt the user again immediately
        *operation = NO_OP;
    }
    return 0;
}

int parse_new_vec(Vector **arg, Operation *operation, char *token, Vector *vector_list)
{
    bool var_found = false;
    int i = 0;
    while(!var_found && i < 10) {
        if (!strcmp(token, vector_list[i].name)) {
            *arg = &(vector_list[i]);
            var_found = true;
        }
        i++;
    }
    if (!var_found) {
        var_found = false;
        i = 0;
        while(!var_found && i < 10) {
            if (!strcmp(vector_list[i].name, "")) {
                *arg = &(vector_list[i]);
                strcpy((*arg)->name, token);
                var_found = true;
            }
            i++;
        }
        if (!var_found) {
            printf("no more space in memory.\n");
            // skip execution this time around, and just prompt the user again immediately
            *operation = NO_OP;
        }
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
