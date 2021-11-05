#include "breadboard.h"

int check_direction(int** breadboard, int bb_cols, int row, int col) {
    /* If we're not in the outer edges of the breadboard, look for matching 
       resistor legs in either direction and return the direction to calling
       function. */
    if ((col > 0) && (breadboard[row][col] == breadboard[row][col-1]\
        || breadboard[row][col-1] == -1)) 
        return LEFT; 
    else if((col < bb_cols) && (breadboard[row][col] == breadboard[row][col+1]\
        || breadboard[row][col+1] == -1))
        return RIGHT; 
    return 0;
}   