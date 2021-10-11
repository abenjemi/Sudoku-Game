#ifndef HW19_H
#define HW19_H
#include<stdbool.h>

#define N 9
#define UNASSIGNED 0

bool construct_array(int grid[N][N], int n, char * filename);
int exist_row(int grid[N][N], int row, int num);
int exist_col(int grid[N][N], int col, int num);
int exist_box(int grid[N][N], int startRow, int startCol, int num);
int is_safe_num(int grid[N][N], int row, int col, int num);
int find_unassigned(int grid[N][N], int *row, int *col);
int solve(int grid[N][N]);
void print_grid(int grid[N][N]);

#endif
