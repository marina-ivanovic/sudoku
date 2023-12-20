#include "Sudoku.h"
#include "Game.h"
#include "Constants.h"
#include <vector>
#include <bitset>

Game::Game(): sudoku(&Sudoku()) {}

const bool Game::validateBoard() {
	std::vector<std::bitset<9>> rows(9), cols(9), blocks(9);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (sudoku->getMatrix()[i][j] != 0) {
				int val = sudoku->getMatrix()[i][j] - 1;
				int blockIdx = (i / 3) * 3 + j / 3;

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
	for (int i = 0; i < 9; ++i) {
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
	int startRow = row - (row % 3);
	int startCol = col - (col % 3);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
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
	//todo
}

void Game::generateSudoku() {
	fillSudoku();
	int i, j = 0;
	int removed = 0;
	while (solveSudoku(0, 0)) {
		i = rand() % 9;
		j = rand() % 9;

		removed = sudoku->getMatrix()[i][j];
		sudoku->setValue(i, j, 0);
	}
	sudoku->setValue(i, j, removed);
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
