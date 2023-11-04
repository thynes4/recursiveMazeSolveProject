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
