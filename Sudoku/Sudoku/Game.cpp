#include "Sudoku.h"
#include "Game.h"
#include "Constants.h"
#include <vector>
#include <bitset>
#include <cstdlib>
#include <ctime>

Game::Game(Sudoku* sudokuObj): sudoku(sudokuObj) {}

const bool Game::validateBoard() {
	std::vector<std::bitset<N>> rows(N), cols(N), blocks(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (sudoku->getMatrix()[i][j] != 0) {
				int val = sudoku->getMatrix()[i][j] - 1;
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

const bool Game::checkRow(int row, int val) {
	for (int i = 0; i < N; ++i) {
		if (sudoku->getMatrix()[row][i] == val) {
			return false;
		}
	}
	return true;
}

const bool Game::checkColumn(int col, int val) {
	for (int i = 0; i < 9; ++i) {
		if (sudoku->getMatrix()[i][col] == val) {
			return false;
		}
	}
	return true;
}

const bool Game::checkBlock(int row, int col, int val) {
	int startRow = row - (row % B);
	int startCol = col - (col % B);
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < B; ++j) {
			if (sudoku->getMatrix()[i + startRow][j + startCol] == val) {
				return false;
			}
		}
	}
	return true;
}

const bool Game::isSafe(int row, int col, int val) {
	if (checkRow(row, val) && checkColumn(col, val) && checkBlock(row, col, val) && isEmpty(row, col)) {
		return true;
	}
	return false;
}

void Game::startGame() {

}
void Game::fillSudoku() {
	fillDiagonalBoxes();
	fillRemainingBoxes(0,3);
}

void Game::fillDiagonalBoxes() {
	for (int i = 0; i < N; i = i + B) {
		fillBox(i, i);
	}
}

void Game::fillBox(int row, int col) {
	for (int i = row; i < row + B; ++i) {
		for (int j = col; j < col + B; ++j) {
			int num;
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			do {
				num = std::rand()%N + 1;
			} while (!checkBlock(i, j, num));
			sudoku->setValue(i, j, num);
		}
	}
}

bool Game::fillRemainingBoxes(int i, int j)
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
		if (isSafe(i, j, num)) {
			sudoku->setValue(i,j,num);
			if (fillRemainingBoxes(i, j + 1)) {
				return true;
			}
			sudoku->setValue(i, j, 0);
		}
	}
	return false;
}

const int Game::numOfEmptySpacesBlock(int row, int col) {
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

const bool Game::numOfEmptySpaces(int minNumOfEmptySpaces) {
	for (int i = 0; i < N; i+=3) {
		for (int j = 0; j < N; j+=3) {
			if (numOfEmptySpacesBlock(i,j)<minNumOfEmptySpaces) {
				return false;
			}
		}
	}
	return true;
}

void Game::generateSudoku() {
	fillSudoku();
	int i, j = 0;
	int minNumsToRemove = 3;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	do {
		i = std::rand() % 9;
		j = std::rand() % 9;

		sudoku->setValue(i, j, 0);
	} while (!numOfEmptySpaces(minNumsToRemove));

}

const bool Game::solveSudoku(int row, int col) {
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
		if (isSafe(row, col, val)) {
			sudoku->setValue(row, col, val);
			if (solveSudoku(row, col + 1)) {
				return true;
			}
			sudoku->setValue(row, col, 0);
		}
	}
	return false;
}

const bool Game::isEmpty(int row, int col) {
	// Your implementation goes here
	// ...
	return true;
}
