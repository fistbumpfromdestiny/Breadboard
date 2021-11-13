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

int remove_resistor(int** breadboard, int bb_rows, int bb_cols,
                    int row, int column) {

    if(row < 1 || row > bb_rows || column < 1 || column > bb_cols)
        return 0;
    if(breadboard[row-1][column-1] <= 0) 
        return 0;
    /* If spot to the rightor left of chosen leg has the same resistor id or -1, 
    clear row in set direction until matching resistor leg is cleared. */
    else if(check_direction(breadboard, bb_cols, row-1, column-1) == LEFT) {
        int i = column-1;
        while(breadboard[row-1][i] != 0) {
            breadboard[row-1][i] = 0;
            if(i > 0) 
                i--;
            }   
        }
    else if(check_direction(breadboard, bb_cols, row-1, column-1) == RIGHT) {
        int i = column-1;
        while(breadboard[row-1][i] != 0) {
            breadboard[row-1][i] = 0;
            i++;
            }
        }   
    return 1;
}

void print_breadboard(int bb_rows, int bb_cols, int** breadboard) {

   /* Prints column numbers above the breadboard, formatted for 1/2 digits */
    if(bb_rows > 10)
        printf("   ");
    else printf("  ");
    for(int i = 1; i <= bb_cols; i++) {
        if(i > 0 && i < 9)
            printf("%d  ", i);
        else
            printf("%d ", i);
    }
    printf("\n");

    for(int i = 0; i < bb_rows; i++) {
        if(bb_rows < 10)
            printf("%d ", i+1);
        else  {
            if(i >= 0 && i < 9)         // Prints row numbers to the
            printf("%d  ", i+1);        // left of the breadboard.
        else                            // Formatted to fit 1 and 2
            printf("%d ", i+1);         // digit numbers.
        }
        for(int j = 0; j < bb_cols; j++) {
            if(breadboard[i][j] == 0)
                printf("0  ");
            else if(breadboard[i][j] > 0)
                printf("=  ");
            else if(breadboard[i][j] == -1)
                printf("-  ");
        }
        printf("\n");
    }
    printf("\n");
}