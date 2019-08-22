#include <iostream>
#include <vector>

using namespace std;

//[45, 24, 35, 31, 40, 38, 11] -> 16
//g++ -std=c++11 filename.cpp
//./a.out

int max_price(vector<int>list){
	int buy_price = 99999999;
	int sell_price = 0;
	int max_profit = -1;

	for (int i = 0; i < list.size()-2; i++){
		int current_price = list.at(i);
		int next_price = list.at(i+1);

		if (next_price > current_price){

			if (current_price < buy_price)
				buy_price = current_price;

			max_profit = next_price - buy_price;
		}
	}
	return max_profit

}

int main(){

	vector<int>lst;

	lst.push_back(45);
	lst.push_back(24);
	lst.push_back(35);
	lst.push_back(31);
	lst.push_back(40);
	lst.push_back(38);
	lst.push_back(11);

	cout<<"Stock Prices: ";
	
	for (auto i : lst){
		cout << lst.at(i) << " ";
	}
	
	cout<<endl;
	cout << "Profit: " << max_price(lst) << endl;


	return 0;
}
