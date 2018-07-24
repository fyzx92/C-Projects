#include <stdio.h>
#include <stdlib.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

typedef int bool;
#define true 1
#define false 0

int arraySize(int array[]);
void printBoard(char board[][]);

int main() {

	int boardSize = 10;
	char board[boardSize][boardSize];
	int i=0; 
	int j=0;

	/// Initialize Board
	for (i=0; i<boardSize; i++) {	
		for (j=0; j<boardSize; j++) {
			board[i][j]= 'O';
		}
	}

	printBoard(board);

	/// place a battleship
	int shipAlive = true;
	int ship[2];
	ship[0] = rand()%boardSize;
	ship[1] = rand()%boardSize;
	
	/// take user guesses
	int uGuess[2];
	int numGuesses = 3;
	int guessesRemaining = numGuesses;

	/// check guesses against location and print results
	for (i=0; i<numGuesses; i++) {
		
		scanf("%d", &uGuess[0]);
		scanf("%d", &uGuess[1]);

		if ( (uGuess[0]>=boardSize) || (uGuess[1]>=boardSize) ) {
			printf("You missed the ocean. Idiot. Try again");
			continue;
		}
		if (board[uGuess[0]][uGuess[1]]== 'X') {
			printf("you already guessed that. Try again");
			continue;
		}
		if ((uGuess[0]==ship[0]) && (uGuess[1]==ship[1])) {
			shipAlive = false;
			printf("Hit! you win");
			break;
		}
		if ((uGuess[0]!=ship[0]) || (uGuess[1]!=ship[1])) {
			guessesRemaining--;
			board[uGuess[0]][uGuess[1]]= 'X';
			if (guessesRemaining < 0) {
				printf("you lose");
				break;
			}
			printf("Miss! You have %d guesses left",guessesRemaining);
			printBoard(board);
		}
		
	}
}


void printBoard(char board[][]) {
	int boardSize = arraySize(board);
	for (int i=0; i<boardSize; i++) {	///Print board
		for (int j=0; j<boardSize; j++) {
			printf("%c ", board[i][j] );		
		}
		printf("\n");	
	}
}


