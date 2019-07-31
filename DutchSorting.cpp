#include <iostream>
#include <vector>

using namespace std;

//[2,0,0,1,2,1] -> [0,0,1,1,2,2]
void dutch_sort(vector<int>list){
	int left = 0;
	int right = list.size()-1;

	while (right > left){
		
		if (list[left] != 0){
			right--;
		}

	}

}

void print_vector(vector<int>list){
	for (int i = 0; i <list.size();i++){
		cout << list[i] << " ";
	}
	cout<<endl;
}

int main(){
	vector<int>list;
	list.push_back(2);
	list.push_back(0);
	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(1);


	cout<<"Current Array:";
	print_vector(list);

	dutch_sort(list);

	cout<<"Sorted Array: ";
	print_vector(list);

	return 0;
}