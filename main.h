/*
 * Filename: main.h
 * Description: Header file for main.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

int execute(Command *command, bool *quitting);

int quit(bool *quitting);

int list();

int clear();

int help();
