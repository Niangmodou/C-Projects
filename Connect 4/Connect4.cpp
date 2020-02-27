#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include "Connect4.h"

using namespace std;

Connect4::Connect4() : rowSize(6),colSize(7),gameOver(false),currPlayerTurn(1){
	for (int r = 0; r < rowSize; r++) {                     
    	vector<char> aRow;  
        for (int c = 0; c < colSize; c++) { 
            aRow.push_back('E'); 
        }
    	board.push_back(aRow);
	}
}

bool Connect4::isGameOver() {return gameOver == true;}

int Connect4::getTurn(){return currPlayerTurn;}

int Connect4::getOpenRow(int column){ //retrives open row in a specific column
	//backwards loop to retrive open row
	int currRow = rowSize-1;
	while(currRow >= 0){
		if(board[currRow][column]== 'E'){
			return currRow;
		}
		currRow--;
	}
	return -1;
}

void Connect4::makeMove(int column){
	int row = getOpenRow(column);
	if(currPlayerTurn == 1){
		board[row][column] = 'R';
	}else{
		board[row][column] = 'B';
	}
	toggleTurn();
}

bool Connect4::validMove(int column){
	return board[0][column] == 'E';
}

void Connect4::toggleTurn(){
	currPlayerTurn = !currPlayerTurn;
}

void Connect4::checkForWin(){
	char player;
	if(currPlayerTurn == 1){
		player = 'R';
	}else{
		player = 'B';
	}

	//Check for Horizontal
	if(horizontalWin(player) || verticalWin(player) || diagonalWin(player)){
		gameOver = true;
	}

	if(gameOver == true){
		cout << "We have a winner: ";
		if(currPlayerTurn == 0){
			cout << "BLUE Player!!!!!!!!!" << endl;
		}else{
			cout << "RED Player!!!!!!!!!" << endl;
		} 
	}
}

bool Connect4::horizontalWin(char player){
	for(int i = 0;i < rowSize; ++i){
		for(int j = 0; j < colSize-3; ++j){
			if(board[i][j] == player && board[i][j+1] == player
				&& board[i][j+2] == player && board[i][j+3] == player){
				return true;
			}
		}
	}
	return false;
}

bool Connect4::verticalWin(char player){
	for(int i = 0;i < rowSize-3; ++i){
		for(int j = 0; j < colSize; ++j){
			if(board[i][j] == player && board[i+1][j] == player
				&& board[i+2][j] == player && board[i+3][j] == player){
				return true;
			}
		}
	}
	return false;
}

bool Connect4::diagonalWin(char player){
	//check for Positive Diagonal
	for(int i = 0;i < rowSize-3; ++i){
		for(int j = 0; j < colSize-3; ++j){
			if(board[i][j] == player && board[i+1][j+1] == player
				&& board[i+2][j+2] == player && board[i+3][j+3] == player){
				return true;
			}
		}
	}

	//check for Negative Diagonal
	for(int i = 3;i < rowSize; ++i){
		for(int j = 0; j < colSize-3; ++j){
			if(board[i][j] == player && board[i-1][j+1] == player
				&& board[i-2][j+2] == player && board[i-3][j+3] == player){
				return true;
			}
		}
	}
	return false;
}

bool Connect4::boardFilled(){
	for(vector<char> each : board){
		if(find(each.begin(),each.end(),'E') != each.end()){
			return false;
		}
	}
	gameOver = true;
	return true;
}

ostream& operator<<(ostream& os,const Connect4& game){
	for(int i = 0; i < game.rowSize; i++){
		for(int j = 0; j < game.colSize; j++){
			os << game.board[i][j] << "	";
		}
		os << endl;
	}
	return os;	
}
