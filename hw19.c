#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "hw19.h"

bool construct_array(int grid[N][N], int n, char * filename)
{
  FILE *fp = fopen(filename,"r");
  int i;
  int j; 
  if (fp == NULL)
  {
    return false; 
  }
  char str[15];
  for (i = 0; i < n; i++)
  {
    fgets(str, 15, fp);
    for (j = 0; j < n; j++)
    {
      if (str[j] != '\n' && str[j] != '\0' && str[j] != ' ')
      {
        if (str[j] == '-')
        {
          str[j] = '0';
        }
        grid[i][j] = str[j] - '0';
      }
    }
  }
  fclose(fp);
  return true;
}

int exist_row(int grid[N][N], int row, int nu)
{
  for (int col = 0; col < 9; col++)
  {
    if (grid[row][col] == nu) 
    {
      return 1;
    }
  }
  return 0;
}

int exist_col(int grid[N][N], int col, int nu)
{
  for (int row = 0; row < 9; row++) 
  {
    if (grid[row][col] == nu)
    {
      return 1;
    }
  }
  return 0;
}

int exist_box(int grid[N][N], int startRow, int startCol, int nu) 
{
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      if (grid[row + startRow][col + startCol] == nu)
      {
        return 1;
      } 
    }
  }
  return 0;
}

int safe_num(int grid[N][N], int row, int col, int nu)
{
  return !exist_row(grid, row, nu) && !exist_col(grid, col, nu) && !exist_box(grid, row - (row % 3), col - (col %3), nu);
}

int find_unassigned(int grid[N][N], int *row, int *col) 
{
  for (*row = 0; *row < N; (*row)++) 
  {
    for (*col = 0; *col < N; (*col)++) 
    {
      if (grid[*row][*col] == 0) 
      {
        return 1;
      } 
    }
  }
  return 0;
}

int solve(int grid[N][N])
{

  int row = 0;
  int col = 0;
  if (!find_unassigned(grid, &row, &col))
  {
    return 1;
  }
  for (int nu = 1; nu <= N; nu++ )
  {
    if (safe_num(grid, row, col, nu)) 
    {
      grid[row][col] = nu;
      if (solve(grid)) 
      {
        return 1;
      }
      grid[row][col] = UNASSIGNED;
    }
  }
	
  return 0;
}

void print_grid(int grid[N][N])
{
  for (int row = 0; row < N; row++)
  {
    for (int col = 0; col < N; col++) 
    {
      printf("%d", grid[row][col]);
    }
    printf("\n");
  }
}
