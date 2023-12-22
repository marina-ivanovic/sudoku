#include "Sudoku.h"
#include "Computer.h"
#include "Constants.h"
#include "Validation.h"
#include <vector>
#include <bitset>
#include <cstdlib>
#include <ctime>

Computer::Computer(Sudoku* sudokuObj) : sudoku(sudokuObj) {}

//==============SUDOKU SOLVER - BACKTRACKING ALGHORITHM=======================
const bool Computer::solveSudoku() {
	return solveSudoku(0, 0);
}
const bool Computer::solveSudoku(int row, int col) {
	if (row == N - 1 && col == N) {
		return true;
	}
	if (col == N) {
		row++;
		col = 0;
	}
	if (sudoku->getMatrix()[row][col] != 0) {
		return solveSudoku(row, col + 1);
	}

	for (int val = 1; val <= N; val++) {
		if (Validation::isSafe(*sudoku, row, col, val)) {
			sudoku->setValue(row, col, val);
			if (solveSudoku(row, col + 1)) {
				return true;
			}
			sudoku->setValue(row, col, 0);
		}
	}
	return false;
}


//==============SUDOKU GENERATOR FUNCTIONS=======================
void Computer::generateSudoku() {
	eraseSudoku();
	fillSudoku();
	int i, j = 0;
	int minNumsToRemove = 3;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	do {
		i = std::rand() % 9;
		j = std::rand() % 9;

		sudoku->setValue(i, j, 0);
	} while (!numOfEmptySpaces(minNumsToRemove));
	std::vector<std::vector<int>> tempMatrix = sudoku->getMatrix();
	if (!solveSudoku()) {
		eraseSudoku();
		generateSudoku();
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sudoku->setValue(i, j, tempMatrix[i][j]);
			}
		}
	}
}

void Computer::fillSudoku() {
	fillDiagonalBoxes();
	fillRemainingBoxes(0, 3);
}

void Computer::fillDiagonalBoxes() {
	for (int i = 0; i < N; i = i + B) {
		fillBox(i, i);
	}
}

void Computer::fillBox(int row, int col) {
	for (int i = row; i < row + B; ++i) {
		for (int j = col; j < col + B; ++j) {
			int num;
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			do {
				num = std::rand() % N + 1;
			} while (!Validation::checkBlock(*sudoku, i, j, num));
			sudoku->setValue(i, j, num);
		}
	}
}

bool Computer::fillRemainingBoxes(int i, int j)
{
	if (j >= N && i < N - 1) {
		i = i + 1;
		j = 0;
	}
	if (i >= N && j >= N) {
		return true;
	}
	if (i < B) {
		if (j < B) {
			j = B;
		}
	}
	else if (i < N - B) {
		if (j == (int)(i / B) * B) {
			j = j + B;
		}
	}
	else {
		if (j == N - B) {
			i = i + 1;
			j = 0;
			if (i >= N) {
				return true;
			}
		}
	}
	for (int num = 1; num <= N; num++) {
		if (Validation::isSafe(*sudoku, i, j, num)) {
			sudoku->setValue(i, j, num);
			if (fillRemainingBoxes(i, j + 1)) {
				return true;
			}
			sudoku->setValue(i, j, 0);
		}
	}
	return false;
}

const int Computer::numOfEmptySpacesBlock(int row, int col) {
	int startRow = row - (row % B);
	int startCol = col - (col % B);
	int counter = 0;
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < B; ++j) {
			if (sudoku->getMatrix()[i + startRow][j + startCol] == 0) {
				counter++;
			}
		}
	}
	return counter;
}

const bool Computer::numOfEmptySpaces(int minNumOfEmptySpaces) {
	for (int i = 0; i < N; i += 3) {
		for (int j = 0; j < N; j += 3) {
			if (numOfEmptySpacesBlock(i, j)<minNumOfEmptySpaces) {
				return false;
			}
		}
	}
	return true;
}

const bool Computer::isEmpty(int row, int col) {
	if (sudoku->getMatrix()[row][col] == 0){
		return true;
	}
	return false;
}

void Computer::eraseSudoku() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sudoku->setValue(i, j, 0);
		}
	}
}