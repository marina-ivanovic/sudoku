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
// Helper function that calls the solveSudoku(int row, int col), for simplicity
const bool Computer::solveSudoku() {
	return solveSudoku(0, 0);
}

const bool Computer::solveSudoku(int row, int col) {
	// If we have reached the end of the grid, the Sudoku is solved
	if (row == N - 1 && col == N) {
		return true;
	}

	// If we have reached the end of the row, move to the next row
	if (col == N) {
		row++;
		col = 0;
	}

	// If the cell is already filled, proceed to the next cell
	if (sudoku->getMatrix()[row][col] != EMPTY) {
		return solveSudoku(row, col + 1);
	}

	// Try placing values from 1 to N in the current cell
	for (int val = 1; val <= N; val++) {
		// Check if the value can be safely placed in the current cell
		if (Validation::isSafe(*sudoku, row, col, val)) {
			sudoku->setValue(row, col, val);

			// Recursively attempt to solve the Sudoku starting from the next cell
			if (solveSudoku(row, col + 1)) {
				return true; // If a solution is found, return true
			}

			// If placing doesn't lead to a solution, backtrack
			sudoku->setValue(row, col, EMPTY);
		}
	}

	// If no value from 1 to N can be placed in the current cell, backtrack
	return false; // Backtrack to the previous cell
}



//==============SUDOKU GENERATOR FUNCTIONS=======================
void Computer::generateSudoku() {
	eraseSudoku();
	fillSudoku();

	int i, j = 0;
	int minNumsToRemove = 3;

	// Seed the random number generator using current time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Randomly remove cells while maintaining solvability
	do {
		// Randomly select a cell and remove its value
		i = std::rand() % N;
		j = std::rand() % N;
		sudoku->setValue(i, j, EMPTY);

		// Continue removing cells until the neccessary number of cells have been removed
	} while (!Validation::emptySpaces(*sudoku, minNumsToRemove));

	std::vector<std::vector<int>> tempMatrix = sudoku->getMatrix();

	// If no unique solution exists, regenerate the Sudoku puzzle
	if (!solveSudoku()) {
		eraseSudoku();
		generateSudoku();
	}
	else {
		// If a unique solution exists, restore the original puzzle state
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
	// Fill a box with unique values
	for (int i = row; i < row + B; ++i) {
		for (int j = col; j < col + B; ++j) {
			int num;
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			// Keep trying to add a number until we find one that fulfils all necessary criteria
			do {
				num = std::rand() % N + 1;
			} while (!Validation::checkBlock(*sudoku, i, j, num));
			sudoku->setValue(i, j, num);
		}
	}
}


bool Computer::fillRemainingBoxes(int i, int j)
{
	// If we went over the column limit, go to the next row and column
	if (j >= N && i < N - 1) {
		i = i + 1;
		j = 0;
	}

	// If we filled the entire grid, return true
	if (i >= N && j >= N) {
		return true;
	}
	// Checks if we're in the first box, which has already been filled
	if (i < B) {
		if (j < B) {
			j = B;
		}
	}
	// Check if we're in the center blox, which has already been filled
	else if (i < N - B) {
		if (j == (int)(i / B) * B) {
			j = j + B;
		}
	}
	else {
		if (j == N - B) {
			i = i + 1;
			j = 0;
			// Checks if we finished filling up the grid
			if (i >= N) {
				return true;
			}
		}
	}
	// Loop to find a suitable number to fill in the current cell
	for (int num = 1; num <= N; num++) {
		if (Validation::isSafe(*sudoku, i, j, num)) {
			sudoku->setValue(i, j, num);
			if (fillRemainingBoxes(i, j + 1)) {
				return true;
			}
			sudoku->setValue(i, j, EMPTY);
		}
	}
	return false;
}
const bool Computer::isEmpty(int row, int col) {
	if (sudoku->getMatrix()[row][col] == EMPTY){
		return true;
	}
	return false;
}

void Computer::eraseSudoku() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sudoku->setValue(i, j, EMPTY);
		}
	}
}