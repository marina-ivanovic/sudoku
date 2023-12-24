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

	sudoku = Sudoku(board);

	file.close();
	return true;
}

bool FileHandler::saveSudokuToFile(const std::string& filename, const Sudoku& sudoku) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Unable to open file: " << filename << std::endl;
		return false;
	}

	for (const auto& row : (&sudoku)->getMatrix()) {
		for (int value : row) {
			file << value << " ";
		}
		file << "\n"; 
	}

	file.close();
	std::cout << "Sudoku matrix saved to file: " << filename << std::endl;
	return true;
}