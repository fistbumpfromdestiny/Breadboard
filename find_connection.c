#include "breadboard.h"

int find_connection(int** breadboard, int bb_rows, int bb_cols, int* visited,
                    int start, int end) {
    
    int x;
    /*If current column is the same one we're looking for, return 1*/ 
    if(visited[end] == 1)
        return 1;

    /* Loops through every row of column 'i' and looks for a resistor 
    If one is found, moves in either direction until matching resistor
    leg is found. If column has already been visited, continue loop, 
    otherwise set it to visited and call the function again with 
    with the new column as the new starting point. */
    for(int i = 0; i < bb_rows; i++) {
        if((breadboard[i][start] > 0 ) &&\
        (check_direction(breadboard, bb_cols, i, start) == LEFT)) {
            x = start-1;
            while(breadboard[i][x] != breadboard[i][start])
                x--;
            if(visited[x])
                continue;
            visited[x] = 1;
            if(find_connection(breadboard, bb_rows, bb_cols, visited, x, end)) 
                return 1;
        }
        else if((breadboard[i][start] > 0 ) &&\
        (check_direction(breadboard, bb_cols, i, start) == RIGHT)) { 
            x = start+1;
            while(breadboard[i][x] != breadboard[i][start])
                x++;
            if(visited[x])
                continue;
            visited[x] = 1;
            if(find_connection(breadboard, bb_rows, bb_cols, visited, x, end)) 
                return 1;
        }         
    }
    return 0;
}