#include <stdio.h>
#define ROWS 5
#define COLS 5

char board[ROWS][COLS] = 
{
    {'x', 'x', 'x', '-', 'o'}, 
    {'o', 'x', 'x', 'o', 'o'}, 
    {'o', 'x', '-', 'x', 'x'}, 
    {'o', '-', 'x', 'x', '-'}, 
    {'x', 'o', 'x', 'o', 'o'}
};

void print()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j =0; j < COLS; j++)
        {
            printf("%c" + board[i][j]);
        }
    }
}

/* Hint:

scanf(" %c", &choice); //this command will erase whitespace in the token selection

*/

int main() 
{
    print();
    return 0;
}

