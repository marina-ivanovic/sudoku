#ifndef GAME_H
#define GAME_H
#include "Sudoku.h"
class Game {
public:
	Sudoku* sudoku;
	Game(Sudoku* sudokuObj);

	virtual void startGame();
	void endGame();

	//Validation (input checking) methods
	const bool validateBoard();
	const bool isSafe(int row, int col, int val);
	const bool checkRow(int row, int val);
	const bool checkColumn(int col, int val);
	const bool checkBlock(int row, int col, int val);

	//Generative functions
	void eraseSudoku();
	void fillSudoku();
	void fillDiagonalBoxes();
	bool fillRemainingBoxes(int row, int col);
	void fillBox(int startRow, int startCol);
	void generateSudoku();
	const bool solveSudoku(int row, int col);

	//Helper functions
	const bool isEmpty(int row, int col);
	const int numOfEmptySpacesBlock(int row, int col);
	const bool numOfEmptySpaces(int minNumOfEmptySpaces);
};
#endif // GAME_H