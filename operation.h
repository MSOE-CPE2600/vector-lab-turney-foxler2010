/*
 * Filename: operation.h
 * Description: Operation enum definition
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 9/30/25
 * Compile with: make
 */

#ifndef OPERATION_H
#define OPERATION_H

typedef enum Operation {
    ADDVEC,
    SUBVEC,
    DOTVEC,
    CROSSVEC,
    SCALAR_MULT,
    NEW_VEC,
    DISPLAY,
    LIST,
    CLEAR,
    HELP,
    QUIT,
    NO_OP
} Operation;

#endif // OPERATION_H
