#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

 /*****************************************************************
 *
 * Given (x, y) cordinates and the maze,
 * will return a value divisable by 3 if its possible to move down
 * and a value divisable by 2 if its possible to move to the right
 *
 *****************************************************************/
int findMoves(int x, int y,char** maze)
{
  int value = 1;
  if (y != (size - 1) && maze[y+1][x] == '1') value *= 3;
  if (x != (size - 1) && maze[y][x+1] == '1') value *= 2;
  return value;
}

 /**************************************************************
 *
 * Moves through the maze and marks all possible moves as '+' 
 * towards the end by going first to the right then down.
 * once the end of the maze is reached, breaks out of function,
 * if all possible moves and reached then also breaks out of
 * function.
 *
 **************************************************************/

int solve(int x, int y, char** maze)
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

/************************************************************
*
* Given a maze where it is possible to reach the end,
* will move from the bottem right corner to the top left
* cleaning the '+' signs not included in the solution where
* you first go right and then down. after the path of '+'
* signs is cleaned, it turns all '+' to '1' and everything
* else to '0'
*
***********************************************************/

void cleanSolution(char** maze)
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

 /********************************************
 *
 * Prints the given maze as a grid.
 *
 *******************************************/

void printArray(char** maze)
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
