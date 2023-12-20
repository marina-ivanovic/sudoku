#ifndef GAME_H
#define GAME_H
#include "Sudoku.h"
class Game {
protected:
	Sudoku* sudoku;
public:
	Game();

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
	void generateSudoku();
	const bool Game::solveSudoku(int row, int col);

	//Helper functions
	const bool isEmpty(int row, int col);
};
#endif // GAME_H