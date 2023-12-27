#include "Testing.h"
#include "Validation.h"
#include "Computer.h"
#include "FileHandler.h"
#include "Sudoku.h"
#include <iostream>
#include <string>

void Testing::testAll() {
	testGeneratePuzzle();
	testSolvePuzzle();
	testBoardValidation();
	testRowValidation();
	testColumnValidation();
	testBlockValidation();
	testLoadFile();
	testSaveFile();
}

void Testing::testGeneratePuzzle() {
	Sudoku sudoku;
	Computer computer(&sudoku);

	computer.generateSudoku();
	bool result = Validation::validateBoard(sudoku);
	// Since validateBoard returns an int (mistakes), if it returns 0, it means there are no mistakes
	// on the board, therefore, the result is false
	if (!result) {
		std::cout << ">> Puzzle generating test:	PASSED"<<std::endl;
	}
	else {
		std::cout << ">> Puzzle generating test:	FAILED"<<std::endl;
	}
}

void Testing::testSolvePuzzle() {
	//TEST 1 - checking if sudoku puzzle (with exactly one solution) will get solved as expected
	Sudoku sudoku;
	Sudoku sudoku2;
	std::string unsolved_puzzle = "../data/test/test_unsolved1.txt";
	std::string solved_puzzle = "../data/test/test_solved1.txt";

	FileHandler::loadSudokuFromFile(unsolved_puzzle, sudoku);
	FileHandler::loadSudokuFromFile(solved_puzzle, sudoku2);

	Computer computer(&sudoku);
	computer.solveSudoku();

	std::vector<std::vector<int>> board1 = sudoku.getMatrix();
	std::vector<std::vector<int>> board2 = sudoku2.getMatrix();

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (board1[i][j] != board2[i][j]) {
				std::cout << ">> Sudoku solving test1:	FAILED" << std::endl;
				return;
			}
		}
	}
	std::cout << ">> Sudoku solving test1:	PASSED" << std::endl;

	//TEST 2 - Unsolvable puzzle
	bool expectedResult = false;
	std::string unsolvableFilename = "../data/test/test_unsolvable.txt";

	FileHandler::loadSudokuFromFile(unsolvableFilename, sudoku);
	bool result = computer.solveSudoku();
	if (expectedResult == result) {
		std::cout << ">> Sudoku solving test2:	PASSED" << std::endl;
	}
	else {
		std::cout << ">> Sudoku solving test2:	FAILED" << std::endl;
	}
}

void Testing::testSolutionForTheBaseGame() {
	Sudoku sudoku;
	Sudoku sudoku2;
	bool expected1 = true;
	bool expected2 = false;
	std::string unsolved_puzzle = "../data/test/test_unsolved1.txt";
	std::string solved_puzzle = "../data/test/test_solved1.txt";
	std::string wrong_solved_puzzle = "../data/test/test_wrong_puzzle.txt";

	FileHandler::loadSudokuFromFile(unsolved_puzzle, sudoku);
	FileHandler::loadSudokuFromFile(solved_puzzle, sudoku2);

	bool result1 = Validation::completedCorrectPuzzle(sudoku, sudoku2);

	FileHandler::loadSudokuFromFile(wrong_solved_puzzle, sudoku2);
	bool result2 = Validation::completedCorrectPuzzle(sudoku, sudoku2);

	if (result1 == expected1 && result2 == expected2) {
		std::cout << ">> Correct sudoku base test:	PASSED" << std::endl;
	}
	else {
		std::cout << ">> Correct sudoku base test:	FAILED" << std::endl;
	}
}

void Testing::testBoardValidation() {
	//Validating two boards, one valid and one invalid
	bool expectedSolution1 = false;
	bool expectedSolution2 = true;
	Sudoku sudoku;
	Sudoku sudoku2;
	std::string solvedCorrectly = "../data/test/test_solved1.txt";
	std::string solvedIncorrectly = "../data/test/test_solved2.txt";

	FileHandler::loadSudokuFromFile(solvedCorrectly, sudoku);
	FileHandler::loadSudokuFromFile(solvedIncorrectly, sudoku2);

	bool solution1 = Validation::validateBoard(sudoku);
	bool solution2 = Validation::validateBoard(sudoku2);

	if (solution1 == expectedSolution1 && solution2 == expectedSolution2) {
		std::cout << ">> Sudoku validation test:	PASSED" << std::endl;
	}
	else {
		std::cout << ">> Sudoku validation test:	FAILED" << std::endl;
	}
}

void Testing::testBlockValidation() {
	//Checking if a submatrix has a value, one valid and one invalid
	bool expectedSolution1 = false;
	bool expectedSolution2 = true;
	Sudoku sudoku;
	std::string filename = "../data/test/test_unsolved1.txt";

	FileHandler::loadSudokuFromFile(filename, sudoku);

	bool solution1 = Validation::checkBlock(sudoku, 0, 0, 4);
	bool solution2 = Validation::checkBlock(sudoku, 0, 0, 1);

	if (solution1 == expectedSolution1 && solution2 == expectedSolution2) {
		std::cout << ">> Sudoku submatrix validation test:	PASSED" << std::endl;
	}
	else {
		std::cout << ">> Sudoku submatrix validation test:	FAILED" << std::endl;
	}
}
void Testing::testRowValidation() {
	//Checking if a row has a value, one valid and one invalid
	bool expectedSolution1 = false;
	bool expectedSolution2 = true;
	Sudoku sudoku;
	std::string filename = "../data/test/test_unsolved1.txt";

	FileHandler::loadSudokuFromFile(filename, sudoku);

	bool solution1 = Validation::checkRow(sudoku, 0, 1);
	bool solution2 = Validation::checkRow(sudoku, 5, 5);

	if (solution1 == expectedSolution1 && solution2 == expectedSolution2) {
		std::cout << ">> Sudoku row validation test:	PASSED" << std::endl;
	}
	else {
		std::cout << ">> Sudoku row validation test:	FAILED" << std::endl;
	}
}
void Testing::testColumnValidation() {
	//Checking if a column has a value, one valid and one invalid
	bool expectedSolution1 = false;
	bool expectedSolution2 = true;
	Sudoku sudoku;
	std::string filename = "../data/test/test_unsolved1.txt";

	FileHandler::loadSudokuFromFile(filename, sudoku);

	bool solution1 = Validation::checkColumn(sudoku, 1, 8);
	bool solution2 = Validation::checkColumn(sudoku, 3, 5);

	if (solution1 == expectedSolution1 && solution2 == expectedSolution2) {
		std::cout << ">> Sudoku column validation test:	PASSED" << std::endl;
	}
	else {
		std::cout << ">> Sudoku column validation test:	FAILED" << std::endl;
	}
}
void Testing::testLoadFile() {
	// Case 1: correctly loaded puzzle
	bool expectedResult1 = true;
	// Case 2: error - non-existent file
	bool expectedResult2 = false;
	// Case 3: error - corrupted file
	bool expectedResult3 = false;

	Sudoku sudoku;
	std::string correctFilename = "../data/test/test.txt";
	std::string incorrectFilename = "../data/test/doesntexist.txt";
	std::string corruptedFilename = "../data/test/corrupted_file.txt";

	bool result1 = FileHandler::loadSudokuFromFile(correctFilename, sudoku);
	bool result2 = FileHandler::loadSudokuFromFile(incorrectFilename, sudoku);
	bool result3 = FileHandler::loadSudokuFromFile(corruptedFilename, sudoku);

	if (result1 == expectedResult1 && result2 == expectedResult2 && result3 == expectedResult3) {
		std::cout << ">> File load test:	PASSED"<<std::endl;
	}
	else {
		std::cout << ">> File load test:	FAILED"<<std::endl;
	}
}

void Testing::testSaveFile() {
	// Correctly saved sudoku puzzle
	bool expectedResult = true;

	Sudoku sudoku;
	FileHandler::loadSudokuFromFile("../data/test/test.txt", sudoku);

	std::string correctFilename = "../data/test/test1.txt";

	FileHandler::saveSudokuToFile(correctFilename, sudoku);

	Sudoku sudoku2;
	FileHandler::loadSudokuFromFile(correctFilename, sudoku2);

	std::vector<std::vector<int>> board1 = sudoku.getMatrix();
	std::vector<std::vector<int>> board2 = sudoku2.getMatrix();

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (board1[i][j] != board2[i][j]) {
				std::cout << ">> File save test:	FAILED"<<std::endl;
				return;
			}
		}
	}
	std::cout << ">> File save test:	PASSED"<< std::endl;
}