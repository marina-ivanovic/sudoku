#ifndef GAME_H
#define GAME_H
#include "Sudoku.h"
class Game {
protected:
	Sudoku* sudoku;
public:
	Game(Sudoku* sudokuObj=nullptr);
	virtual int startGame();
	void endGame();

	void eraseSudoku();
};
#endif // GAME_H