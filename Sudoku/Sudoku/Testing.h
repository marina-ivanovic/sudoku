#ifndef TESTING_H
#define TESTING_H
class Testing {
public:
	// Runs all test functions
	static void testAll();

	// Sudoku generating test

	// Checks if generated sudoku puzzle is valid
	static void testGeneratePuzzle();
	// Checks if the puzzle has been solved correctly
	static void testSolvePuzzle();
	// Checks if the given solution is for the correct base game
	static void testSolutionForTheBaseGame();

	// Validation tests

	// Testing Validation::validateBoard
	static void testBoardValidation();
	// Testing Validation::checkRow
	static void testRowValidation();
	// Testing Validation::checkColumn
	static void testColumnValidation();
	// Testing Validation::checkBlock
	static void testBlockValidation();

	// File handler tests
	// Testing FileHandler::loadSudokuFromFile
	static void testLoadFile();
	// Testing FileHandler::saveSudokuToFile
	static void testSaveFile();
};
#endif // TESTING_H
