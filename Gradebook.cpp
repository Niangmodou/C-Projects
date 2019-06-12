//
//  main.cpp
//  Gradebook
//
//  Created by Modou Niang on 6/11/19.
//  Copyright © 2019 modouniang. All rights reserved.
//
#include <iostream>

using namespace std;

class Student{
private:
    int scores[5];
    int avgScore;
    string name;
    
public:
    void input(){
        cout << "Please enter your name" << endl;
        string aname;
        cin >> aname;
        
        name = aname;
        
        
        cout << "Please Enter 5 exam scores" << endl;
        int score1,score2,score3,score4,score5;
        cin >> score1 >> score2 >> score3 >> score4 >> score5;
        
        scores[0] = score1;
        scores[1] = score2;
        scores[2] = score3;
        scores[3] = score4;
        scores[4] = score5;
    }
    
    int calculateAverageScore(){
        int acc = 0;
        
        for (int i = 0; i < 5; i++){
            acc += scores[i];
        }
        int avgScore = acc/5;
        return avgScore;
    }
    
    string getName(){
        return name;
    }
    
    void setName(string aname){
        name = aname;
    }
    
};

void addInfo(Student* s){
    s->input();
    cout << "" <<endl;
}

void displayInfo(Student s){
    string name = s.getName();
    int avg = s.calculateAverageScore();
    
    cout << "Name of Student: "<<name<<endl;
    cout << "Average Score of Exams: "<<avg<<endl;
    cout << "" << endl;
}

void intro(){
    cout << "Welcome to Gradebook" << endl;
    cout << "I will help you determine which student has the higest grade in the class"<<endl;
    cout << "" <<endl;
}

int main() {
    intro();
    
    cout << "Please Enter the number of students in the class"<< endl;
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    cout << "" << endl;
    
    //Adds Name and Grades to System
    for(int i = 0; i < n; i++){
        addInfo(&s[i]);
    }
    cout << "----------------------------------------------------"<< endl;
    
    //Display Average Score for each student
    for (int i = 0; i < n ; i++){
        displayInfo(s[i]);
    }
    
    cout << "----------------------------------------------------"<<endl;
    
    int highest = 0;
    string nameHighest;
    for(int i = 0; i < n; i++){
        if (s[i].calculateAverageScore() > highest){
            highest = s[i].calculateAverageScore();
            nameHighest = s[i].getName();
        }
    }
    // print result
    cout << nameHighest << " has the highest grade in the class"<<endl;
    cout << nameHighest <<": "<<highest<<endl;
    
    return 0;
}
