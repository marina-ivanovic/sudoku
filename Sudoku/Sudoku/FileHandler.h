#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Sudoku.h"
#include <string>

class FileHandler {
public:
	bool loadSudokuFromFile(const std::string& filename, Sudoku& sudoku);
	bool saveSudokuToFile(const std::string& filename, const Sudoku& sudoku);
};

#endif // FILEHANDLER_H