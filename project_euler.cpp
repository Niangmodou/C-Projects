#include <iostream>
#include <vector>

using namespace std;

//Problem 1
//Find the sum of all the multiples of 3 or 5 below 1000.
int multiples_3_5(int n){
	vector<int>values;

	for (int i = 0; i < n; i++){
		if (i%3 == 0|| i%5 == 0){
			values.push_back(i);
		}
	}
	int acc = 0;

	for (int i = 0; i < values.size();i++){
		acc+=values[i];
	}
	return acc;

}

//Problem 2
//By considering the terms in the Fibonacci sequence whose 
//values do not exceed four million, find the sum of the even-valued terms.
long even_fibonacci(){
	vector<int>values;

	int first_num = 0;
	int second_num = 1;
	long acc = 0;

	while (true){
		long val = first_num+second_num;
		if (val >= 4000000){
			break;
		}

		if (val%2 == 0){
			acc+=val;
		}

		first_num = second_num;
		second_num = val;
	}
	return acc;
}

//Problem 3
//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?
long prime_factors(long n){
	vector<int>values;

	for (int i = 2; i < n; i++){
		if (n%i == 0){
			bool is_prime = false;

			for (int j = 2; j < i; j++){
				if (i%j == 0){
					is_prime = true;
				};
			}
			if (!is_prime){
				values.push_back(i);
			}
		}
	}

	return values[values.size()-1];
}


int main(){

	cout << prime_factors(13195) << endl;

	return 0;
}