#include <stdio.h>
#include "breadboard.h"

void print_breadboard(int bb_rows, int bb_cols, int** breadboard) {

   /* Prints column numbers above the breadboard, formatted for 1/2 digits */
    if(bb_cols > 10 && bb_rows > 10)
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
