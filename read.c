#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char inputGrid[50][50];
    char solvedGrid[50][50];
    char inputString[50];
    char ch;

    int inputRow = 0;
    int rowLength = 0;
    int i = 0;

    size_t r;
    size_t c;

    scanf("%[^\n]%*c", inputString);
    rowLength = strlen(inputString);

    for (r = 0, c = 0; r <= rowLength; r++) {
        if (inputString[r] == '\n') {
            scanf("%[^\n]%*c", inputString);

            inputRow++;

            if (inputString[r] != ' ') {
                inputGrid[inputRow][c] = inputString[r];
                c++;
            }
        } else
        if (inputString[r] != ' ') {
            inputGrid[inputRow][c] = inputString[r];
            c++;
        }
    }

    // Print the array
    for (r = 0; r < strlen(inputString); r++) {
        for (c = 0; c < strlen(inputString); c++) {
            printf("%c", inputGrid[r][c]);
        }
        printf("\n");
    }
}
