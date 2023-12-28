#include "Sudoku.h"
#include "Game.h"
#include "Testing.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	// Check if at least two arguments (fileInput and fileOutput) are provided
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
		return 1; // Exit with an error code
	}

	std::string fileInput = argv[1]; // Argument 1 is input file
	std::string fileOutput = argv[2]; // Argument 2 is output file
	Sudoku sudoku;
	Game newGame(&sudoku, fileInput, fileOutput);
	while (newGame.startGame() == 1);
	//Testing::testAll();
}