#include "Sudoku.h"
#include <iostream>
#include "Constants.h"

Sudoku::Sudoku() : correctInput(0), incorrectInput(0), gamesPlayed(0) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			matrix[i][j] = 0;
		}
	}
}

Sudoku::Sudoku(int m[N][N]) : correctInput(0), incorrectInput(0), gamesPlayed(0) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			matrix[i][j] = m[i][j];
		}
	}
};

// Implementation of getters and setters
const int(&Sudoku::getMatrix() const)[9][9]{
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

// Implementation of displayBoard method
const void Sudoku::displayBoard() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cout << matrix[i][j] << " ";
			if (j % 3 == 2 && j != 8) {
				std::cout << "| ";
			}
		}
		std::cout << std::endl;
		if (i%3==2 && i != 8) {
			std::cout << "- - - + - - - + - - -";
			std::cout << std::endl;
		}
	}
}
