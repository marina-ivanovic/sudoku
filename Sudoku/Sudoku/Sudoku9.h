const int N = 9;
const int EMPTY = 0;

class Sudoku {
private:
	int matrix[N][N];
	int correctInput;
	int incorrectInput;
	int gamesPlayed;

public:
	//Constructors
	Sudoku(): correctInput(0), incorrectInput(0), gamesPlayed(0) {};
	Sudoku(int m[N][N]) : correctInput(0), incorrectInput(0), gamesPlayed(0) {};

	//Getters and setters
	const int(&getMatrix() const)[9][9];
	void setValue(int row, int col, int value);
	int getCorrectInput() const;
	int getIncorrectInput() const;
	int getGamesPlayed() const;

    //Validation (input checking) methods
    const bool validateBoard();
    const bool checkRow(int row);
    const bool checkColumn(int col);
    const bool checkBlock(int startRow, int startCol);

	//Generative functions
	void eraseSudoku();
	void generateSudoku();
};