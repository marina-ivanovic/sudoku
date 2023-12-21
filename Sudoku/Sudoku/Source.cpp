#include "Sudoku.h"
#include "FileHandler.h"
#include "Game.h"
#include <iostream>
#include <string>

void testSudokuGame() {
	// Create a Game object
	Sudoku sudoku;
	Game sudokuGame(&sudoku);

	// Fill the Sudoku puzzle
	sudokuGame.generateSudoku();

	// Display the initial Sudoku board
	std::cout << "Initial Sudoku Board:" << std::endl;
	sudokuGame.sudoku->displayBoard();

	// Validate the initial Sudoku board
	bool isValid = sudokuGame.validateBoard();
	if (isValid) {
		std::cout << "\nThe generated Sudoku board is valid." << std::endl;
	}
	else {
		std::cout << "\nThe generated Sudoku board is not valid." << std::endl;
	}

	// Attempt to solve the Sudoku
	bool solved = sudokuGame.solveSudoku(0,0);

	// Display the solved Sudoku board if solved
	if (solved) {
		std::cout << "\nSolved Sudoku Board:" << std::endl;
		sudokuGame.sudoku->displayBoard();
		std::cout << "\nThe Sudoku puzzle has been solved." << std::endl;
	}
	else {
		std::cout << "\nFailed to solve the Sudoku puzzle." << std::endl;
	}
	const std::string filename = "../data/sudoku_puzzle2.txt";
	FileHandler fileHandler;
	if (fileHandler.saveSudokuToFile(filename, sudoku)) {
		std::cout << "Successfully saved" << std::endl;
	}
}


int main() {
	testSudokuGame();
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
