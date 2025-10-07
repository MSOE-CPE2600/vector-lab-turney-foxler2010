/*
 * Filename: commands.h
 * Description: Header file for commands.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 10/6/25
 * Compile with: make
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "vector_struct.h"

int quit(bool *quitting);

int display(Vector *vec);

int list(Vector *vector_list);

int clear(Vector *vector_list);

int help();
