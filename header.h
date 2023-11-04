/***************************************************
*
* Thomas Hynes
*
* Program reads in a maze, solves it, and prints it.
* If there is no possible solution prints no soluion
* found.
* 
***************************************************/

#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int size;

void cleanSolution(char** maze);
void printArray(char** maze);
int solve(int x, int y, char** maze);
int findMoves(int x, int y,char** maze);

#endif
