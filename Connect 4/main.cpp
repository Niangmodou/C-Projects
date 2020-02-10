/*
Connect4
MADE WITH LOVE BY MODOU NIANG
*/
#include <iostream>
#include "Connect4.h"

using namespace std;

//prompts user for input
int getInput();

int main(){

	Connect4 game = Connect4();

	cout << "Welcome to Modou's Connect Four! " << endl << endl <<
		"There are two players - RED(R) and BLUE(R) " << endl << 
		"Choose a column from 0 to 6." << "Have Fun!" << endl;
	cout << endl << game << endl;

	while(!game.isGameOver()){
		int currChoice;

		if(game.boardFilled()){
			cout << "This game has ended in a draw :(" << endl;
			continue;
		}

		if(game.getTurn() == 1){ //Player Red
			cout << "It's your turn Player RED, Which column would you like to choose? ";
			currChoice = getInput();

			if(game.validMove(currChoice)){
				game.makeMove(currChoice);
			}

		}else{ //Player Blue
			cout << "It's your turn Player BLUE, Which column would you like to choose? ";
			currChoice = getInput();

			if(game.validMove(currChoice)){
				game.makeMove(currChoice);
			}
		}
		cout << endl << game << endl;
		game.checkForWin();
	}
}

int getInput() {

    while (true) {
        int number;
        cin >> number;

        if (cin.eof()) {
            cout << "Unexpected end of file.\n";
            cin.clear();
            continue;
        }

        if (cin.bad() || cin.fail()) {
            cout << "Invalid input! Enter another number: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (number > 6 || number < 0) {
            cout << "Invalid input! Enter another number: ";
            continue;
        }
        return number;
    }
    return 0;
}









