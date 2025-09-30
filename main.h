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

int execute(Command *command, bool *quitting);

int quit(bool *quitting);

int list();

int clear();

int help();
