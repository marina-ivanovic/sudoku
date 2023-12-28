#include "Validation.h"
#include "Constants.h"
#include "Sudoku.h"

const int Validation::validateBoard(const Sudoku& sudoku) {
	int mistakes = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			int val = sudoku.getMatrix()[i][j];

			if (val == EMPTY){
				continue;
			}

			bool hasMistake = false;

			// Checks the whole block
			int startRow = (i / B) * B;
			int startCol = (j / B) * B;

			for (int row = startRow; row < startRow + B; ++row) {
				for (int col = startCol; col < startCol + B; ++col) {
					if (row != i && col != j && sudoku.getMatrix()[row][col] == val) {
						mistakes++;
						hasMistake = true;
					}
					// To get rid of double counting of mistakes
					else if (row == i && col!=j && sudoku.getMatrix()[row][col] == val) {
						mistakes--;
					}
					else if (col == j && row != i && sudoku.getMatrix()[row][col] == val) {
						mistakes--;
					}
				}
			}

			for (int k = 0; k < N; ++k) {
				if (k != j && sudoku.getMatrix()[i][k] == val) {
					if (hasMistake) {
						mistakes--;
					}
					else{
						mistakes++;
					}
				}
			}

			for (int k = 0; k < N; ++k) {
				if (k != i && sudoku.getMatrix()[k][j] == val) {
					if (hasMistake) {
						mistakes--;
					}
					else {
						mistakes++;
					}
				}
			}
		}
	}
	return mistakes/2;
}


const bool Validation::checkRow(const Sudoku& sudoku, int row, int val){
	for (int i = 0; i < N; ++i) {
		if (sudoku.getMatrix()[row][i] == val) {
			return false;
		}
	}
	return true;
}

const bool Validation::checkColumn(const Sudoku& sudoku,int col, int val) {
	for (int i = 0; i < N; ++i) {
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
	if (sudoku.getMatrix()[row][col] == EMPTY) {
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
			if (sudoku.getMatrix()[i + startRow][j + startCol] == EMPTY) {
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
			if (sudoku.getMatrix()[i][j] == EMPTY) {
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

const bool Validation::isFilled(const Sudoku& sudoku) {
	if (numOfEmptySpaces(sudoku) == 0) {
		return true;
	}
	return false;
}

const bool Validation::completedCorrectPuzzle(const Sudoku& baseSudoku, const Sudoku& solvedSudoku) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (baseSudoku.getMatrix()[i][j] != EMPTY) {
				if (baseSudoku.getMatrix()[i][j] != solvedSudoku.getMatrix()[i][j]) {
					return false;
				}
			}
		}
	}
	return true;
}