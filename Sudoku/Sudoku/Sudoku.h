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
	void setCorrectInput();
	int getIncorrectInput() const;
	void setIncorrectInput();
	int getGamesPlayed() const;
	void setGamesPlayed();

	void initStats();

	void displayBoard();
	void displayStats();
};
#endif // SUDOKU_H
