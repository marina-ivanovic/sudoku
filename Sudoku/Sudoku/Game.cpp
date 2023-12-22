#include "Sudoku.h"
#include "Game.h"
#include "Computer.h"
#include "Validation.h"
#include <iostream>

Game::Game(Sudoku* sudokuObj): sudoku(sudokuObj) {}

int Game::startGame() {
	Computer computer(sudoku);

	std::cout << "====================================================================" << std::endl;
	std::cout << "                              SUDOKU                                " << std::endl;
	std::cout << "====================================================================" << std::endl;
	std::cout << ">> CHOOSE AN OPTION: " << std::endl;
	std::cout << "[ 1 ] Choose a file to load a sudoku game from\n[ 2 ] Generate a new sudoku puzzle\n[ 0 ] Exit" << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "Not yet implemented" << std::endl;
	}
	else if (choice == 2) {
		std::cout << "Generating puzzle..." << std::endl;
		computer.generateSudoku();
		std::cout << "Puzzle generated" << std::endl;
		sudoku->displayBoard();
	}
	else {
		return 0;
	}
	return 1;
	/*std::cout << "Solving the puzzle..." << std::endl;
	if (computer.solveSudoku()) {
		std::cout << "Successfully solved!" << std::endl;
		sudoku->displayBoard();
	}
	else {
		std::cout << "ERROR: Puzzle unsolvable" << std::endl;
	}*/
	
}