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
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
 
int isValidPiece(char piece) 
{
    return piece == 'x' || piece == 'o';
}

int isValidPosition(int pos) 
{
    return pos >= 0 && pos < ROWS;
}

int isCellEmpty(int row, int col) 
{
    return board[row][col] == '-';
}

int isBoardFull() 
{
    for(int i = 0; i < ROWS; i++) 
    {
        for(int j = 0; j < COLS; j++) 
        {
            if(board[i][j] == '-') 
            {
                return 0;
            }
        }
    }
    return 1;
}

void gamePlay() 
{
    char choice;
    int row, col;

    while(1) 
    {
        printf("Choose a piece (x or o) or q to quit: ");
        scanf(" %c", &choice);
        if(choice == 'q') 
        {
            break;
        }

        while(!isValidPiece(choice)) 
        {
            printf("Invalid choice. Choose a piece (x or o) or q to quit: ");
            scanf(" %c", &choice);
            if(choice == 'q') 
            {
                return;
            }
        }

        printf("Choose a row (0-4): ");
        scanf("%d", &row);
        while(!isValidPosition(row)) 
        {
            printf("Invalid choice. Choose a row (0-4): ");
            scanf("%d", &row);
        }

        printf("Choose a column (0-4): ");
        scanf("%d", &col);
        while(!isValidPosition(col)) 
        {
            printf("Invalid choice. Choose a column (0-4): ");
            scanf("%d", &col);
        }

        if(!isCellEmpty(row, col)) 
        {
            printf("Invalid choice. That space is already occupied.\n");
            print();
            continue;
        }

        board[row][col] = choice;

        if(isBoardFull()) 
        {
            printf("Congratulations, you have filled the board!\n");
            print();
            break;
        }

        print();
    }
}

int main() 
{
    print();
    gamePlay();
    return 0;
}

