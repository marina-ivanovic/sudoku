#ifndef VALIDATION_H
#define VALIDATION_H
#include "Sudoku.h"

class Validation{
public:
	static const bool validateBoard(const Sudoku& sudoku);
	static const bool isSafe(const Sudoku& sudoku, int row, int col, int val);
	static const bool checkRow(const Sudoku& sudoku, int row, int val);
	static const bool checkColumn(const Sudoku& sudoku, int col, int val);
	static const bool checkBlock(const Sudoku& sudoku, int row, int col, int val);
	static const bool isEmpty(const Sudoku& sudoku, int row, int col);
};
#endif // VALIDATION_H