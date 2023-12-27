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

	void displayMenu();
	// Constructor to initialize the Game object with a Sudoku object (defaults to nullptr)
	Game(Sudoku* sudokuObj, std::string fileInput, std::string fileOutput);

	// Function that gets the filename and enables loading the sudoku puzzle from a file
	bool loadGame();

	void generateNewGame(Computer& computer);

	// Function that gets the filename and enables saving the sudoku puzzle
	bool saveSudoku();

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

	void calculateStats();
};

#endif // GAME_H
