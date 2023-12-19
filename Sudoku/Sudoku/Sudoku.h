#ifndef SUDOKU_H
#define SUDOKU_H
#include "Constants.h"

class Sudoku {
private:
	int matrix[N][N];
	int correctInput;
	int incorrectInput;
	int gamesPlayed;

public:
	//Constructors
	Sudoku();
	Sudoku(int m[N][N]);

	//Getters and setters
	const int(&getMatrix() const)[N][N];
	void setValue(int row, int col, int value);
	int getCorrectInput() const;
	int getIncorrectInput() const;
	int getGamesPlayed() const;

    const void displayBoard();
};
#endif // SUDOKU_H