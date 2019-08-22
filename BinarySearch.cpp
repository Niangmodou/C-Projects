#include <iostream>
#include <vector>

using namespace std;

//Function Takes Integer and a sorted Vector as parameters
int binarySearch(int n, vector<int>lst);

int main() {
    
    vector<int>num = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,22};
    int ind = binarySearch(6,num);
    cout << "Index of 6: "<<ind<<endl;
    
    return 0;
}

int binarySearch(int n, vector<int>lst){
    //vector<int>num;
    int left = 0;
    int right = lst.size()-1;
    
    while (right > left){
        int mid = (right+left)/2;
        if (lst.at(mid) > n){
            right = mid--;
        }else if(lst.at(mid) < n){
            left = mid++;
        }else{
            return mid;
        }
    }
    return -1; //Not Found
}

