#ifndef COMPUTER_H
#define COMPUTER_H

// Class that represents the computer's Sudoku solver/generator
class Computer {
private:
	Sudoku* sudoku; // Pointer to Sudoku object

	// Private functions for Sudoku solving and generation

	// Solves Sudoku recursively, parameters are starting row and colummn
	const bool solveSudoku(int row, int col);

	// Checks if a cell is empty, parameters are row and column number
	const bool isEmpty(int row, int col);

	// Fills the Sudoku grid with pseudorandom numbers
	void fillSudoku();

	// Fills diagonal boxes of the Sudoku grid, needed for the generating algorithm
	void fillDiagonalBoxes();

	// Fills remaining boxes of the Sudoku grid
	bool fillRemainingBoxes(int row, int col);

	// Helper function, used in fillDiagonal/RemainingBoxes - Fills a specific box of the Sudoku grid
	void fillBox(int startRow, int startCol);

	// Clears the Sudoku grid
	void eraseSudoku();

public:
	// Constructor to initialize with a Sudoku object
	Computer(Sudoku* sudokuObj);

	// Generates a new Sudoku puzzle
	void generateSudoku();

	// Public function to solve Sudoku
	// Calls the private solveSudoku(int row, int col)
	const bool solveSudoku();

};
#endif // COMPUTER_H
