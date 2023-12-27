#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Sudoku.h"
#include <string>

// Class responsible for handling file operations related to Sudoku puzzles
class FileHandler {
public:
	// Static function to load a Sudoku puzzle from a file
	// Parameters:
	//   - filename: the name of the file to load the Sudoku from
	//   - sudoku: reference to a Sudoku object where the loaded puzzle will be stored
	// Returns:
	//   - true if the Sudoku puzzle was successfully loaded from the file, false otherwise
	static bool loadSudokuFromFile(const std::string& filename, Sudoku& sudoku);

	// Static function to save a Sudoku puzzle to a file
	// Parameters:
	//   - filename: the name of the file to save the Sudoku to
	//   - sudoku: const reference to the Sudoku object to be saved
	// Returns:
	//   - true if the Sudoku puzzle was successfully saved to the file, false otherwise
	static bool saveSudokuToFile(const std::string& filename, const Sudoku& sudoku);
};

#endif // FILEHANDLER_H