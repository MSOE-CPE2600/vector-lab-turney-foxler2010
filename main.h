/*
 * Filename: main.h
 * Description: Header file for main.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "vecmath.h"
#include "command_struct.h"

int execute(bool *quitting, Command command, Vector *vector_list);

int quit(bool *quitting);

int display(Vector *vec);

int list(Vector *vector_list);

int clear(Vector *vector_list);

int help();
