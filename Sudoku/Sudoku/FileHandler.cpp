#include "Sudoku.h"
#include "FileHandler.h"
#include <string>
#include <iostream>
#include <fstream>

bool FileHandler::loadSudokuFromFile(const std::string& filename, Sudoku& sudoku) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Unable to open file " << filename << std::endl;
		return false;
	}

	std::vector<std::vector<int>> board;
	int value;
	for (int i = 0; i < 9; ++i) {
		std::vector<int> row;
		for (int j = 0; j < 9; ++j) {
			if (!(file >> value)) {
				std::cerr << "Error reading Sudoku values from file" << std::endl;
				return false;
			}
			row.push_back(value);
		}
		board.push_back(row);
	}

	sudoku = Sudoku(board); // Update the Sudoku object with the loaded board

	file.close();
	return true;
}