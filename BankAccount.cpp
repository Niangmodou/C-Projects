#include <iostream>
using namespace std;

double deposit(string name,int balance)
{
    double amount;
    cout<<"Hello "<<name<<", How much would you like to deposit";
    cin>>amount;
    cout<<"You now have $"<<balance + amount<<" in your account \n";
    return balance + amount;

}
double withdrawl(string name,int balance)
{
    double amount, newbalance;
    cout<<"Hello "<<name<<", How much would you like to withdrawl";
    cin>>amount;
    newbalance = balance - amount;
    if(newbalance < 0){
        newbalance-=20;
        cout<<"You have been charged an overdraft fee \n";
    }
    cout<<"You now have $"<<newbalance<<" in your account \n";
    return newbalance;
}
int main()
{
    string name;
    cout<<"Hello, Please enter your name";
    getline(cin,name);
    int balance;
    cout<<"How much money do you have in your account: ";
    cin>>balance;
    cout<<"Press 1 for deposit/2 for withdrawl:";
    int choice;
    cin>>choice;
    if(choice == 1){
        deposit(name,balance);
    } else{
        withdrawl(name,balance);
    }
    cout<<"Thank you for banking with C++ Banking";
    return 0;
}
