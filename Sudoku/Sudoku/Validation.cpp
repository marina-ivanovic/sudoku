#include "Validation.h"
#include "Constants.h"
#include "Sudoku.h"
#include <vector>
#include <bitset>

const bool Validation::validateBoard(const Sudoku& sudoku) {
	std::vector<std::bitset<N>> rows(N), cols(N), blocks(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (sudoku.getMatrix()[i][j] != 0) {
				int val = sudoku.getMatrix()[i][j] - 1;
				int blockIdx = (i / B) * B + j / B;

				if (rows[i].test(val) || cols[j].test(val) || blocks[blockIdx].test(val)) {
					return false;
				}

				rows[i].set(val);
				cols[j].set(val);
				blocks[blockIdx].set(val);
			}
		}
	}
	return true;
}

const bool Validation::checkRow(const Sudoku& sudoku, int row, int val){
	for (int i = 0; i < N; ++i) {
		if (sudoku.getMatrix()[row][i] == val) {
			return false;
		}
	}
	return true;
}

const bool Validation::checkColumn(const Sudoku& sudoku, int col, int val) {
	for (int i = 0; i < 9; ++i) {
		if (sudoku.getMatrix()[i][col] == val) {
			return false;
		}
	}
	return true;
}

const bool Validation::checkBlock(const Sudoku& sudoku, int row, int col, int val) {
	int startRow = row - (row % B);
	int startCol = col - (col % B);
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < B; ++j) {
			if (sudoku.getMatrix()[i + startRow][j + startCol] == val) {
				return false;
			}
		}
	}
	return true;
}

const bool Validation::isEmpty(const Sudoku& sudoku, int row, int col){
	if (sudoku.getMatrix()[row][col] == 0) {
		return true;
	}
	return false;
}

const bool Validation::isSafe(const Sudoku& sudoku, int row, int col, int val) {
	if (checkRow(sudoku, row, val) && checkColumn(sudoku, col, val) && checkBlock(sudoku, row, col, val) && isEmpty(sudoku, row, col)) {
		return true;
	}
	return false;
}

const int Validation::numOfEmptySpacesBlock(const Sudoku& sudoku, int row, int col) {
	int startRow = row - (row % B);
	int startCol = col - (col % B);
	int counter = 0;
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < B; ++j) {
			if (sudoku.getMatrix()[i + startRow][j + startCol] == 0) {
				counter++;
			}
		}
	}
	return counter;
}

const int Validation::numOfEmptySpaces(const Sudoku& sudoku) {
	int counter = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (sudoku.getMatrix()[i][j] == 0) {
				counter++;
			}
		}
	}
	return counter;
}

const bool Validation::emptySpaces(const Sudoku& sudoku, int minNumOfEmptySpaces) {
	for (int i = 0; i < N; i += 3) {
		for (int j = 0; j < N; j += 3) {
			if (numOfEmptySpacesBlock(sudoku, i, j)<minNumOfEmptySpaces) {
				return false;
			}
		}
	}
	return true;
}