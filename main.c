#include <stdio.h>
#include <stdlib.h>
#include "breadboard.h"

int main(void) {

    int bb_rows, bb_cols, start, end, row, column_a, column_b;
    int res_id = 1;
    int *res_ptr = &res_id;
    
    while(1) {
    printf("Input breadboard size (rows, columns). Min: 2 Max: 30.\n");
    if(scanf(" %d, %d", &bb_rows, &bb_cols) != 2) {
        printf("Invalid input.\n");
        while ((getchar()) != '\n');
        continue;
    }
    if(bb_rows < 2 || bb_rows > 30 || bb_cols < 2 || bb_cols > 30) {
        printf("Size out of range, try again.\n");
        continue;
        }
    break;
    }
    int** breadboard = malloc(bb_rows * sizeof(int*));
      for(int i = 0; i < bb_rows; i++) {
        breadboard[i] = malloc(bb_cols * sizeof(int));
      }
    /* Initializes an empty breadboard. */
    for(int i = 0; i < bb_rows; i++) {
        for(int j = 0; j < bb_cols; j++) {
            breadboard[i][j] = 0;
        }
    }

    while(1) {
        printf("**********************\n");
        printf("*1) Add resistor     *\n");
        printf("*2) Remove resistor  *\n");
        printf("*3) Print breadboard *\n");
        printf("*4) Check connection *\n");
        printf("*5) Exit program     *\n");
        printf("**********************\n");

        char choice;
        
        scanf(" %c*c", &choice);
        getc(stdin);
        
        switch(choice) {

        case '1':

            printf("Enter spot for first leg leg (row, column): \n");
            if(scanf(" %d, %d", &row, &column_a) != 2) {
                printf("Invalid input.\n");
                while ((getchar()) != '\n');
                break;
            }
            printf("Input column of second leg placement:\n");
            if(scanf(" %d", &column_b) != 1) {
                printf("Invalid input.\n");
                while ((getchar()) != '\n');
                break;
            }
            if(place_resistor(breadboard, res_ptr, bb_rows, bb_cols,
                              row, column_a, column_b))
                printf("Resistor placed succesfully.\n");
            else 
                printf("Failed to place resistor.\n");
            break;

        case '2':   
            printf("Remove resistor from (row, column): \n");
            if(scanf(" %d, %d", &row, &column_a) != 2) {
                printf("Invalid input.\n");
                while ((getchar()) != '\n');
                break;
            }
            if(remove_resistor(breadboard, bb_rows, bb_cols, 
                               row, column_a)) 
                printf("Resistor removed successfully.\n"); 
            else
                printf("No resistor leg in that spot.\n");
            while ((getchar()) != '\n');
            break;

        case '3':
            print_breadboard(bb_rows, bb_cols, breadboard);
            break;

        case '4':
            printf("Input columns (start, end): ");
            if(scanf(" %d, %d", &start, &end) != 2) {
                while ((getchar()) != '\n');
                printf("Invalid input.\n");
                break;
            }
            start--;
            end--;
            /* Creates array "visited" to remember visited columns while searching
            for a connection between columns */
            int* visited = malloc(bb_cols * sizeof(int*));
            for(int i = 0; i < bb_cols; i++)
                visited[i] = 0;
            visited[start] = 1;    
            if(find_connection(breadboard, bb_rows, bb_cols, visited,
                               start, end))
                printf("Connection found.\n");
            else 
                printf("No connection found.\n"); 
            free(visited);     
            break; 
        case '5':
            for(int i = 0; i < bb_rows; i++)
                free(breadboard[i]);
            free(breadboard);
            exit(1);
        default:      
            break;
        }
    }
    return 0;
}