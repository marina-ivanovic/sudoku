#include "Sudoku.h"
#include "Game.h"

int main() {
	Sudoku sudoku;
	Game newGame(&sudoku);
	do {
	} while (newGame.startGame() == 1);
}