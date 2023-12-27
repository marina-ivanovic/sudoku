#ifndef VALIDATION_H
#define VALIDATION_H

#include "Sudoku.h"

// Class responsible for validating a Sudoku puzzle
class Validation {
public:
	// Static function to validate the entire Sudoku board
	// Returns the number of invalid cells
	static const int validateBoard(const Sudoku& sudoku);

	// Static function to check if a value can be placed in a specific cell
	static const bool isSafe(const Sudoku& sudoku, int row, int col, int val);

	// Static functions to check constraints in rows, columns, and blocks

	// Check if a value already exists in a specific row
	static const bool checkRow(const Sudoku& sudoku, int row, int val);

	// Check if a value already exists in a specific column
	static const bool checkColumn(const Sudoku& sudoku, int col, int val);

	// Check if a value already exists in a specific block
	static const bool checkBlock(const Sudoku& sudoku, int row, int col, int val);

	// Static function to check if a cell is empty
	static const bool isEmpty(const Sudoku& sudoku, int row, int col);

	// Static functions to count empty spaces in blocks and the entire board

	// Helper function used in numOfEmptySpaces - Count the number of empty spaces in a specific block
	static const int numOfEmptySpacesBlock(const Sudoku& sudoku, int row, int col);

	// Count the total number of empty spaces in the Sudoku board
	static const int numOfEmptySpaces(const Sudoku& sudoku);

	// Static function to check if there are a minimum number of empty spaces in the board, in each block
	static const bool emptySpaces(const Sudoku& sudoku, int minNumOfEmptySpaces);

	// Static function to check if the sudoku puzzle is filled
	static const bool isFilled(const Sudoku& sudoku);

	// Static function to check if user provided the solution to the correct base puzzle
	static const bool completedCorrectPuzzle(const Sudoku& baseSudoku, const Sudoku& solvedSudoku);
};

#endif // VALIDATION_H
