#ifndef GAME_H
#define GAME_H

#include "Sudoku.h"
#include "Computer.h"
#include <string>

// Class responsible for managing the Sudoku game
class Game {
private:
	Sudoku* sudoku; // Pointer to a Sudoku object
	std::string fileInput;
	std::string fileOutput;
public:
	
	// Constructor to initialize the Game object with a Sudoku object (defaults to nullptr)
	Game(Sudoku* sudokuObj, std::string fileInput, std::string fileOutput);

	// Prints out the basic menu layout
	void displayMenu();

	// Function that calls the generative function from the computer object
	void generateNewGame(Computer& computer);

	// Function that calls the saving function from FileHelper module
	bool saveSudoku();

	// Function that calls the loading function from FileHelper module
	bool loadGame();

	// Function to start the Sudoku game
	// Returns an integer representing the game status (1 - continue the game, 0 - end the game)
	int startGame();

	// Function to start solving the Sudoku puzzle using the Computer's solving capabilities
	// Parameters:
	//   - computer: reference to a Computer object used for solving the Sudoku
	void startSolving(Computer& computer);

	void computerSolving(Computer& computer);

	// Function for player interaction to solve the Sudoku puzzle
	void playerSolving();

	// Function for validation and calculating the number of errors that have been made
	void calculateStats();
};

#endif // GAME_H
