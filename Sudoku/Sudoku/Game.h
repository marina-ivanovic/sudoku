#ifndef GAME_H
#define GAME_H
#include "Sudoku.h"
#include "Computer.h"
class Game {
protected:
	Sudoku* sudoku;
public:
	Game(Sudoku* sudokuObj=nullptr);
	int startGame();
	int startSolving(Computer& computer);
	void playerSolving();

	void eraseSudoku();
};
#endif // GAME_H