#ifndef COMPUTER_H
#define COMPUTER_H
class Computer{
private:
	Sudoku* sudoku;
private:
	const bool solveSudoku(int row, int col);
	const bool isEmpty(int row, int col);
	void fillSudoku();
	void fillDiagonalBoxes();
	bool fillRemainingBoxes(int row, int col);
	void fillBox(int startRow, int startCol);
	void eraseSudoku();
public:
	Computer(Sudoku* sudokuObj);

	void generateSudoku(); //generates a new puzzle
	//function that calls protected function solveSudoku(int row, int col);
	const bool solveSudoku();
};
#endif // COMPUTER_H