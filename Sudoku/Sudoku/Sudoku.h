#ifndef SUDOKU_H
#define SUDOKU_H

#include "Constants.h"
#include <vector>

// Class representing a Sudoku puzzle
class Sudoku {
private:
	std::vector<std::vector<int>> matrix; // 2D vector to store the Sudoku grid
	int correctInput; // Counter for correct inputs
	int incorrectInput; // Counter for incorrect inputs
	int gamesPlayed; // Counter for the number of games played

public:
	// Constructors

	// Default constructor to create an empty Sudoku grid
	Sudoku();

	// Constructor to initialize Sudoku with a provided matrix
	Sudoku(const std::vector<std::vector<int>>& m);

	// Getters and setters for class members

	// Getter for retrieving the Sudoku matrix
	const std::vector<std::vector<int>>& getMatrix() const;

	// Setter to assign a value to a specific cell in the Sudoku grid
	void setValue(int row, int col, int value);

	// Getter for the count of correct inputs
	int getCorrectInput() const;

	// Setter to increment the count of correct inputs
	void setCorrectInput(int correct);

	// Getter for the count of incorrect inputs
	int getIncorrectInput() const;

	// Setter to increment the count of incorrect inputs
	void setIncorrectInput(int mistakes);

	// Getter for the count of games played
	int getGamesPlayed() const;

	// Setter to increment the count of games played
	void setGamesPlayed();

	// Function to initialize statistics (correctInput, incorrectInput, gamesPlayed)
	void initStats();

	// Function to display the Sudoku board
	void displayBoard();

	// Function to display statistics (correctInput, incorrectInput, gamesPlayed)
	void displayStats();
};

#endif // SUDOKU_H
