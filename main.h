/*
 * Filename: main.h
 * Description: Header file for main.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "command_struct.h"
#include "vector_struct.h"
#include "vector_list_struct.h"
#include "vector_list_tools.h"
#include "operation.h"
#include "vecmath.h"
#include "commands.h"

#define MAX_TOKENS 6
#define TOKEN_LENGTH 17

int read(int *tokenc, char (*token)[MAX_TOKENS][TOKEN_LENGTH], bool help_flag);

int parse_var(Vector **arg, Operation *operation, char *token, VectorList *vector_list, bool skip_error_message);

int parse_new_vec(Vector **arg, char *token, VectorList *vector_list);

int execute(bool *quitting, Command command, VectorList *vector_list);
