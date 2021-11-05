#include <stdio.h>
#include "breadboard.h"

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

