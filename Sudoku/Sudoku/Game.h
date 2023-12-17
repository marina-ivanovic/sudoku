#include "Sudoku9.h"
class Game {
private:
	Sudoku* sudoku;
public:
	void startGame();
	void endGame();
	void displayBoard();
	void computerPlaying();
	void userPlaying();
	void validateGame();
};