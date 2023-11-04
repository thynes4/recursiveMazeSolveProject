#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FIXHEADER.h"

int size;

int main(void)
{
  char *line;
  int s, j, p, i, curline;
  char c;
  char** maze;
  
  line = malloc(sizeof(char)+1);
  line[1]='\0';
  s = 0;
  j = 0;
  curline = 1;

  while((c = getchar()) != '\n')
  {
    line[s]=c;
    s++;
    line = (char*) realloc(line,s+1);
  }
  
  size = s;

  maze = (char**)malloc(size * sizeof(char*));
  for (p = 0; p < size; p++) maze[p] = (char*)malloc(size+1);
  
  memcpy(maze[0],line,size);
  
  while((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      j = 0;
      memcpy(maze[curline],line,size);
      curline++;
     }
    else
    {
      line[j]=c;
      j++;
    }
  }

  solve(0,0,maze);

  if (maze[size-1][size-1] == '+')
  {
    printf("PATH FOUND!\n");
    cleanSolution(maze);
  }
  else
  {
    printf("no path found.");
  }

  for(i=0; i < size; i++) free(maze[i]);
  free(maze);
  free(line);
  return 0;
}
