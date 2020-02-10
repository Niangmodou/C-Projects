#include <iostream>
#include <vector>

class Connect4{
	friend std::ostream& operator<<(std::ostream&,const Connect4&);
public:
	Connect4();

	//getter method to check current game status
	bool isGameOver();

	//getter metbod to retrieve current turn
	int getTurn();

	//retrives open row in a specific column
	int getOpenRow(int);

	//makes a move in a specified column
	void makeMove(int);

	//ensures a player move is valid
	bool validMove(int);

	//toggles turn between red an blue
	void toggleTurn();

	//checks for a winning move
	void checkForWin();

	//checks for a winning horizontal move
	bool horizontalWin(char);

	//checks for a winning vertical move
	bool verticalWin(char);

	//checks for a winning diagonal move
	bool diagonalWin(char);

	//checks whether the entire board has been filled
	bool boardFilled();

private:
	int currPlayerTurn; //toggles between 1 and 0 to signify turns
	bool gameOver;
	int rowSize,colSize;
	std::vector< std::vector<char>> board; //matrix is used for underlying data structure
};