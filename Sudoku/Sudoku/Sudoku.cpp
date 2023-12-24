#include "Sudoku.h"
#include <iostream>
#include "Constants.h"

Sudoku::Sudoku() : correctInput(0), incorrectInput(0), gamesPlayed(0) {
	matrix = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
}

Sudoku::Sudoku(const std::vector<std::vector<int>>& m) : correctInput(0), incorrectInput(0), gamesPlayed(0) {
	matrix = m;
}

const std::vector<std::vector<int>>& Sudoku::getMatrix() const {
	return matrix;
}

void Sudoku::setValue(int row, int col, int value) {
	matrix[row][col] = value;
}

int Sudoku::getCorrectInput() const {
	return correctInput;
}

int Sudoku::getIncorrectInput() const {
	return incorrectInput;
}

int Sudoku::getGamesPlayed() const {
	return gamesPlayed;
}

void Sudoku::setCorrectInput() {
	correctInput++;
}

void Sudoku::setGamesPlayed() {
	gamesPlayed++;
}

void Sudoku::setIncorrectInput() {
	incorrectInput++;
}

void Sudoku::initStats() {
	correctInput = 0;
	incorrectInput = 0;
}

void Sudoku::displayStats() {
	std::cout << "Games played: " << gamesPlayed << std::endl;
	std::cout << "Correct moves played: " << correctInput << std::endl;
	std::cout << "Incorrect moves played: " << incorrectInput << std::endl;
}

void Sudoku::displayBoard() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (matrix[i][j] == 0){
				std::cout << "  ";
			}
			else {
				std::cout << matrix[i][j] << " ";
			}
			if (j % 3 == 2 && j != 8) {
				std::cout << "| ";
			}
		}
		std::cout << std::endl;
		if (i % 3 == 2 && i != 8) {
			std::cout << "- - - + - - - + - - -";
			std::cout << std::endl;
		}
	}
}
