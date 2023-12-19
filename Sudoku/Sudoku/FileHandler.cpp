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

	int value;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (!(file >> value)) {
				std::cerr << "Error reading Sudoku values from file" << std::endl;
				return false;
			}
			sudoku.setValue(i, j, value);
		}
	}

	file.close();
	return true;
}