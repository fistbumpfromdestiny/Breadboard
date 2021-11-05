#pragma once
#define LEFT 1
#define RIGHT 2

void print_breadboard(int bb_rows, int bb_cols, int** breadboard);
int place_resistor(int** breadboard, int* res_ptr, int bb_rows, int bb_cols,
                   int row, int column_a, int column_b);
int remove_resistor(int** breadboard, int bb_rows, int bb_cols,
                    int row, int column);
int find_connection(int** breadboard, int bb_rows, int bb_cols, int* visited,
                    int x, int end_col);
int check_direction(int ** breadboard, int bb_cols, int row, int col);