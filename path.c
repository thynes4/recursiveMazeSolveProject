#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

int findMoves(int x, int y,char maze[size][size+1])
{
  int value = 1;
  if (y != (size - 1) && maze[y+1][x] == '1') value *= 3;
  if (x != (size - 1) && maze[y][x+1] == '1') value *= 2;
  return value;
}

int solve(int x, int y, char maze[size][size+1])
{
  int possibleMoves = findMoves(x,y,maze);
  int canRight = 1;
  int canDown = 1;
  if (possibleMoves % 2 == 0) canRight = 0;
  if (possibleMoves % 3 == 0) canDown = 0;
  
  if (maze[size-1][size-1] == '+')
  {
    return 1;
  }  
  if (maze[y][x] == '+' && x == 0 && y == 0)
  {
    return 0;
  }
  maze[y][x] = '+';
  if ((canRight == 0 && (solve(x+1,y,maze) == 1)) || (canDown == 0 && solve(x,y+1,maze) == 1))
    {
      return 1;
    }
  else
  {
    return 0;
  }
  return 1;
}

void cleanSolution(char maze[size][size+1])
{
  int i, j;
  
  if (maze[size-1][size-2]=='+' && maze[size-2][size-1] == '+') maze[size-1][size-2] = '0';
  
  for(i = size-1; i >= 0; i--)
  {
    for (j = size-1; j >= 0; j--)
    {
      if (i == size-1 && j == size-1) continue;
      if (maze[i][j]=='+')
      {
	if (((j+1 != size) && maze[i][j+1]=='+') || ((i+1 != size) && maze[i+1][j]=='+'))
	  {
	    continue;
	  }
	maze[i][j]='0';
      }
    }
  }
  printArray(maze);
}

void printArray(char maze[size][size+1])
{
  int i, j;
  
  for(i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if(maze[i][j]=='+') maze[i][j] = '1';
      else maze[i][j]='0';
      printf("%c",maze[i][j]);
    }
    printf("\n");
  }
}
