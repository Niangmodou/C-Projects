#include <iostream>
#include <vector>

using namespace std;

//[2,0,0,1,2,1] -> [0,0,1,1,2,2]
void dutch_sort(vector<int>list){
	int left = 0;
	int right = list.size()-1;

	while (right > left){
		if (list.at(left)!=0 && list.at(right)==0){
		swap(list.at(left),list.at(right));
		}
		left++;
		right--;

	}

}

void print_vector(vector<int>list){
	for (int i = 0; i <list.size();i++){
		cout << list[i] << " ";
	}
}

int main(){
	vector<int>list;
	list.push_back(2);
	list.push_back(0);
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(1);

	swap(list[1],list[5]);


	cout<<"Current Array:"<<list<<endl;
	dutch_sort(list);
	cout<<"Sorted Array: "<<list<<endl;

	return 0;
}