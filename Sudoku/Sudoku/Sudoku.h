#ifndef SUDOKU_H
#define SUDOKU_H
#include "Constants.h"
#include <vector>

class Sudoku {
private:
	std::vector<std::vector<int>> matrix;
	int correctInput;
	int incorrectInput;
	int gamesPlayed;

public:
	// Constructors
	Sudoku();
	Sudoku(const std::vector<std::vector<int>>& m);

	// Getters and setters
	const std::vector<std::vector<int>>& getMatrix() const;
	void setValue(int row, int col, int value);
	int getCorrectInput() const;
	int getIncorrectInput() const;
	int getGamesPlayed() const;

	void displayBoard();
};
#endif // SUDOKU_H
