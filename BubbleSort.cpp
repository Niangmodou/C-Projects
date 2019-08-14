#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &vec);

void printVec(vector<int> vec);

//Lambda Expression Sort
void lambdaSort(vector<int> &vec);

int main(){
	vector<int> myVec{50,20,100,5,6,7,2};

	cout << "Before Bubble Sort: ";
	printVec(myVec);

	bubbleSort(myVec);

	cout<<"After Bubbble Sort: ";
	printVec(myVec);


	return 0;
}

void bubbleSort(vector<int> &vec){
	int right = vec.size()-1;
	while(right >= 1){
		int left = 0;

		while(left < right){
			if(vec[left] > vec[left+1]){
				//Swap
				int temp = vec[left];
				vec[left] = vec[left+1];
				vec[left+1] = temp;
			}
			left++;

		}
		right--;
	}
}

void lambdaSort(vector<int> &vec){
	sort(vec.begin(),vec.end(),[](int x, int y){return x < y;});
}
void printVec(vector<int> vec){
	cout << "< ";
	for(auto i: vec){
		cout << i << " , ";
	}
	cout << ">"<<endl<<endl;
}
