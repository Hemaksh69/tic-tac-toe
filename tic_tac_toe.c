#include <stdio.h>

char a[3][3];


void initializeBoard() {
    for (int m = 0; m < 3; m++) {
        for (int k = 0; k < 3; k++) {
            a[m][k] = '-';
        }
    }
}


void printBoard() {
    for (int m = 0; m < 3; m++) {
        for (int k = 0; k < 3; k++) {
            printf("%c ", a[m][k]);
        }
        printf("\n");
    }
}


int checkWinner() {
    
    for (int i = 0; i < 3; i++) {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != '-')
            return 1; 
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != '-')
            return 1;
    }

  
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != '-')
        return 1; 
    if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][2] != '-')
        return 1; 

    return 0; 
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == '-') {
                return 0; 
            }
        }
    }
    return 1; 
}

int main() {
    int row, col, turn = 0;
    char currentPlayer;
    int gameStatus = 1; 
    initializeBoard(); 

    while (gameStatus) {
        printBoard(); 
        
        currentPlayer = (turn % 2 == 0) ? 'X' : 'O';
        printf("Player %c, enter the row and column (0-2):\n", currentPlayer);
        scanf("%d%d", &row, &col);

       
        if (row < 0 || row > 2 || col < 0 || col > 2 || a[row][col] != '-') {
            printf("Invalid move. Try again.\n");
            continue;
        }

       
        a[row][col] = currentPlayer;

        if (checkWinner()) {
            printBoard(); 
            printf("Player %c wins!\n", currentPlayer);
            gameStatus = 0; 
            break;
        }

       
        if (isBoardFull()) {
            printBoard(); 
            printf("It's a tie!\n");
            gameStatus = 0; 
            break;
        }

        
        turn++;
    }

    return 0;
}
