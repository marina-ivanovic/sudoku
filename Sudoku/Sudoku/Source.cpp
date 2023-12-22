#include "Sudoku.h"
#include "Game.h"

int main() {
	Sudoku sudoku;
	Game newGame(&sudoku);
	do {
	} while (newGame.startGame() == 1);
	//const std::string filename = "../data/sudoku_puzzle1.txt";
	//Sudoku sudoku;

	//FileHandler fileHandler;
	//if (fileHandler.loadSudokuFromFile(filename, sudoku)) {
	//	// Display the loaded Sudoku board
	//	sudoku.displayBoard();

	//	// Example: Set a value in the Sudoku board
	//	sudoku.setValue(5, 7, 7);
	//	std::cout << "==========================" << std::endl;

	//	// Example: Display the updated board
	//	sudoku.displayBoard();
	//}
	//else {
	//	std::cout << "Failed to load Sudoku from file." << std::endl;
	//}

	//return 0;
}
