#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hw19.h"

#define N 9
int main(int argc, char * * argv)
{
  if (argc < 1)
  {
    return EXIT_FAILURE;
  }
  int grid[N][N];
  bool rtv; 
  rtv = construct_array(grid, N, argv[1]); 
  if (rtv == false)
  {
    return EXIT_FAILURE;
  }
  if (solve(grid) == true) 
  { 
    print_grid(grid); 
  } 
  else
  {
    printf("No solution exists");
  }   
  
  return EXIT_SUCCESS;
}
