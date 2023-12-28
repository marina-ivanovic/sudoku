#include "Sudoku.h"
#include "Game.h"
#include "Computer.h"
#include "Validation.h"
#include "FileHandler.h"
#include <iostream>
#include <string>

Game::Game(Sudoku* sudokuObj, std::string fileInput, std::string fileOutput): sudoku(sudokuObj), fileInput(fileInput),fileOutput(fileOutput) {}

void Game::displayMenu() {
	std::cout << "====================================================================" << std::endl;
	std::cout << "                              SUDOKU                                " << std::endl;
	std::cout << "====================================================================" << std::endl;
	std::cout << ">> CHOOSE AN OPTION: " << std::endl;
	std::cout << "[ 1 ] Load a sudoku game\n[ 2 ] Generate a new sudoku puzzle\n[ 0 ] Exit" << std::endl;
}

int Game::startGame() {
	Computer computer(sudoku);
	sudoku->initStats();
	displayMenu();
	int choice;
	std::cin >> choice;

	switch (choice) {
	case 1:
		loadGame();
		break;
	case 2:
		generateNewGame(computer);
		break;
	case 0:
		return 0;
	default:
		std::cout << "Invalid choice. Please choose a valid option." << std::endl;
		break;
	}

	// If we loaded in a complete puzzle - show stats
	if (Validation::isFilled(*sudoku)) {
		calculateStats();
		return 1;
	}
	startSolving(computer);

	return 1;
}

bool Game::loadGame() {
	return FileHandler::loadSudokuFromFile(fileInput, *sudoku);
}

bool Game::saveSudoku() {
	return (FileHandler::saveSudokuToFile(fileInput, *sudoku));
}

void Game::generateNewGame(Computer& computer) {
	std::cout << "Generating puzzle..." << std::endl;
	computer.generateSudoku();
	std::cout << "Puzzle generated" << std::endl;
	saveSudoku();
}


void Game::startSolving(Computer& computer) {
	sudoku->displayBoard();
	int choice;
	std::cout << "Would you like to solve the puzzle or let the computer solve it?\n[ 1 ] I want to solve it\n[ 2 ] Let the computer solve it" << std::endl;
	std::cin >> choice;

	switch (choice) {
	case 1:
		playerSolving();
		break;
	case 2:
		computerSolving(computer);
		break;
	default:
		std::cout << "Invalid choice. Please choose a valid option." << std::endl;
		break;
	}
}

void Game::computerSolving(Computer& computer) {
	std::cout << "Solving the puzzle..." << std::endl;
	if (computer.solveSudoku()) {
		std::cout << "Successfully solved!" << std::endl;
		
		calculateStats();
		FileHandler::saveSudokuToFile(fileOutput, *sudoku);
	}
	else {
		std::cout << "ERROR: Puzzle unsolvable" << std::endl;
	}
}

void Game::playerSolving() {
	Sudoku tempSudoku;
	FileHandler::loadSudokuFromFile(fileOutput, tempSudoku);

	if (!Validation::completedCorrectPuzzle(*sudoku, tempSudoku)) {
		std::cout << "Provided solution is not the solution to the puzzle. Please try again after solving." << std::endl;
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sudoku->setValue(i, j, tempSudoku.getMatrix()[i][j]);
		}
	}
	if (!Validation::isFilled(*sudoku)) {
		std::cout << "Provided solution is not finished. Please try again after solving." << std::endl;
		return;
	}

	else {
		calculateStats();
	}
}

void Game::calculateStats() {
	sudoku->displayBoard();

	// Validating the board + counting the number of mistakes the player/computer has made
	int mistakes = Validation::validateBoard(*sudoku);

	sudoku->setGamesPlayed();
	sudoku->setIncorrectInput(mistakes);
	sudoku->setCorrectInput(81 - mistakes);

	sudoku->displayStats();
}