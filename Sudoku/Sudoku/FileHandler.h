#include "Sudoku9.h"
#include <string>

class FileHandler {
public:
	bool loadSudokuFromFile(const std::string& filename, Sudoku& sudoku);
	bool saveSudokuToFile(const std::string& filename, const Sudoku& sudoku);
};