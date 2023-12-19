#ifndef GAME_H
#define GAME_H
#include "Sudoku.h"
class Game {
protected:
	Sudoku* sudoku;
public:
	virtual void startGame();
	void endGame();
	void validateGame();

	//Validation (input checking) methods
	const bool validateBoard();
	const bool checkRow(int row);
	const bool checkColumn(int col);
	const bool checkBlock(int startRow, int startCol);

	//Generative functions
	void eraseSudoku();
	void generateSudoku();

	//Helper functions
	const bool isEmpty(int row, int col);
};
#endif // GAME_H