#include <stdio.h>
#include "breadboard.h"

int place_resistor(int** breadboard, int* res_ptr, int bb_rows, int bb_cols,
                   int row, int column_a, int column_b) {

    int temp;

    /* Checks that input is not out of range of breadboard size, that a spot
    doesn't have a resistor in it or that the placement would overlap an
    existing connetion. */
    if(column_a == column_b || row < 1 || row > bb_rows || column_a < 1 || column_a > bb_cols ||\
    column_b < 1 || column_b > bb_cols || breadboard[row-1][column_b-1] != 0\
    || breadboard[row-1][column_a-1] != 0)
        return 0;
       
    breadboard[row-1][column_a-1] = *res_ptr;
    breadboard[row-1][column_b-1] = *res_ptr;
    *res_ptr += 1;
    /*Rearranges the columns in case user input the "bigger" column value first.*/
    if (column_a > column_b) {
        temp = column_b;
        column_b = column_a;
        column_a = temp;
    }
    /* Adds a -1 to "busy" columns to prevent overlapping resistors. */
    for(int i = column_a; i < column_b-1; i++) {
        breadboard[row-1][i] = -1;
    }
    return 1;
}