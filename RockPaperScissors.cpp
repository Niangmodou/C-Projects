#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
//rock = 1
//paper = 2
//scissors = 3
void computerguess(int guess)
{
  //This Function is called to check the users choice
    if(guess == 1){
        cout<<"Computer selected: Rock \n";
    } else if(guess == 2){
        cout<<"Computer selected: Paper \n";
    } else if(guess == 3){
        cout<<"Computer selected: Scissors \n";
    }
}
void rockfunc(int guess)
{
  //This Function is called whenever the user selects rock
    if(guess == 1){
        cout<<"Game was a tie";
    } else if(guess == 2){
        cout<<"You Lost";
    } else if(guess ==3){
        cout<<"You Won";
    }
}
void paperfunc(int guess)
{
  //This Function is called whenever the user selects paper
    if(guess == 2){
        cout<<"Game was tie";
    } else if(guess == 1){
        cout<<"You Won";
    } else if(guess ==3){
        cout<<"You Lost";
    }
}
void scissorsfunc(int guess)
{
  //This Function is called whenever the user selects scissors
    if(guess == 3){
        cout<<"Game was a tie";
    } else if(guess == 1){
        cout<<"You Won";
    } else if(guess ==2){
        cout<<"You Lost";
    }
}

int main()
{
    //Computer Guess
    int guess;
    srand(time(0));
    guess = rand() % 3 + 1;
    //User Input
    string choice;
    cout<<"Choose Rock/Paper/Scissors: ";
    cin>>choice;
    computerguess(guess);
    if(choice == "Rock"){
        rockfunc(guess);
    } else if(choice == "Paper"){
        paperfunc(guess);
    } else if(choice == "Scissors"){
        scissorsfunc(guess);
    }
    return 0;
}
