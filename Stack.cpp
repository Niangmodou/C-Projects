#include <iostream>
#include <vector>

using namespace std;

//Implementation of a Stack using Ints
class IntStack{
private:
    int size;
    vector<int>stack;
public:
    int len(){
        return size;
    }
    
    bool is_empty(){
        return this->len() == 0;
    }
    
    int pop(){
        if (!this->is_empty()){
            int val = stack.at(size-1);
            stack.pop_back();
            size--;
            return val;
        }else{
            cout << "STACK IS EMPTY" << endl;
            return -1;
        }
    }
    
    void push(int elem){
        stack.push_back(elem);
        size++;
    }
    
    void print(){
        for (int i = size-1; i >= 0; i--){
            cout << stack.at(i) << endl;
        }
    }
};

//Implementation of a stack using Strings
class StringStack{
private:
    int size;
    vector<string>stack;
public:
    int len(){
        return size;
    }
    
    bool is_empty(){
        return this->len() == 0;
    }
    
    string pop(){
        if (!this->is_empty()){
            string val = stack.at(size-1);
            stack.pop_back();
            size--;
            return val;
        }else{
            cout << "STACK IS EMPTY" << endl;
            return "-1";
        }
    }
    
    void push(string elem){
        stack.push_back(elem);
        size++;
    }
    
    void print(){
        for (int i = size-1; i >= 0; i--){
            cout << stack.at(i) << endl;
        }
    }
};


int main(){
    
    StringStack s1;
    IntStack s2;
    
    cout << "String Stack -----------------------------------------" << endl << " "<<endl;
    s1.push("Chris");
    s1.push("James");
    s1.push("Wayne");
    s1.push("Keith");
    s1.push("Travis");
    s1.print();
    cout << ""<<endl;
    
    cout << "Integer Stack ----------------------------------------" << endl << " "<< endl;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    s2.push(40);
    s2.push(50);
    s2.print();
    
    
    return 0;
}
