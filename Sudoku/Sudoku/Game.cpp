#include "Sudoku.h"
#include "Game.h"
#include "Computer.h"
#include "Validation.h"
#include "FileHandler.h"
#include <iostream>

Game::Game(Sudoku* sudokuObj): sudoku(sudokuObj) {}

int Game::startGame() {
	Computer computer(sudoku);
	sudoku->initStats();
	std::cout << "====================================================================" << std::endl;
	std::cout << "                              SUDOKU                                " << std::endl;
	std::cout << "====================================================================" << std::endl;
	std::cout << ">> CHOOSE AN OPTION: " << std::endl;
	std::cout << "[ 1 ] Choose a file to load a sudoku game from\n[ 2 ] Generate a new sudoku puzzle\n[ 0 ] Exit" << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		std::string filename;
		std::cout << "Input the file name (without extention) from which you want to load the puzzle >>";
		std::cin >> filename;
		FileHandler::loadSudokuFromFile("../data/" + filename + ".txt", *sudoku);
		sudoku->displayBoard();
	}
	else if (choice == 2) {
		std::cout << "Generating puzzle..." << std::endl;
		computer.generateSudoku();
		std::cout << "Puzzle generated" << std::endl;
		sudoku->displayBoard();
		std::cout << "Would you like to save this generated puzzle to a file?\n[ 1 ] Yes\n[ 2 ] No" << std::endl;
		std::cin >> choice;

		if (choice == 1) {
			std::string filename;
			std::cout << "Insert the name of the file where you want to save the puzzle in (without extention) >>";
			std::cin >> filename;
			FileHandler::saveSudokuToFile("../data/"+filename+".txt", *sudoku);
		}
	}
	else {
		return 0;
	}
	std::cout << "Would you like to solve this puzzle or another one?\n[ 1 ] This one\n[ 2 ] Another puzzle" << std::endl;
	std::cin >> choice;
	if (choice == 2) {
		return 0;
	}
	startSolving(computer);

	return 1;
}

int Game::startSolving(Computer& computer) {
	sudoku->displayBoard();
	int choice;
	std::cout << "Would you like to solve the puzzle or let the computer solve it?\n[ 1 ] I want to solve it\n[ 2 ] Let the computer solve it" << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		playerSolving();
	}
	else if (choice == 2) {
		std::cout << "Solving the puzzle..." << std::endl;
		if (computer.solveSudoku()) {
			std::cout << "Successfully solved!" << std::endl;
			sudoku->displayBoard();
			sudoku->setGamesPlayed();
			sudoku->displayStats();
			return 0;
		}
		else {
			std::cout << "ERROR: Puzzle unsolvable" << std::endl;
			return 1;
		}
	}
	return 0;
}

void Game::playerSolving() {
	while(true){
		if (Validation::numOfEmptySpaces(*sudoku) == 0) {
			break;
		}
		int i, j, val;
		std::cout << "Input coordinates and value of the number you want to place - row (1-9) column (1-9) value (1-9) (seperated by space) >>";
		std::cin >> i >> j >> val;
		if (i < 1 || i > 9 || j < 1 || j > 9 || val < 1 || val>9) {
			std::cout << "Incorrect coordinates or value, numbers need to be 1-9" << std::endl;
			continue;
		}
		i--;
		j--;
		if (!Validation::isEmpty(*sudoku, i, j)) {
			std::cout << "Must choose an empty space" << std::endl;
			continue;
		}
		if (!Validation::isSafe(*sudoku, i, j, val)) {
			sudoku->setIncorrectInput();
		}
		else {
			sudoku->setCorrectInput();
		}
		sudoku->setValue(i, j, val);
		sudoku->displayBoard();
	}
	sudoku->setGamesPlayed();
	sudoku->displayStats();
}