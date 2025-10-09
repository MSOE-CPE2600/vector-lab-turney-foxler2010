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
#include "operation.h"
#include "vecmath.h"
#include "commands.h"

int read(int tokenc, char token[10][10]);

int parse_var(Vector **arg, Operation *operation, char *token, Vector *vector_list, bool skip_error_message);

int parse_new_vec(Vector **arg, Operation *operation, char *token, Vector *vector_list);

int execute(bool *quitting, Command command, Vector *vector_list);
