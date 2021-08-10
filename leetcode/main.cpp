#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

//<-----------------------Edit below this line------------------------------------------->

using input = int; //Change the type of your input
using output = bool; //Change the type of your output

//Custom tests and their corresponding answers as an array. 
//Eg. The below tests for the even numbers. 1 -> false, 2 -> true, and so on.
vector<input> inputArr{1, 2, 3, 4, 5};
vector<output> answers{false, true, false, true, false};

//<-----------------------Edit above this line------------------------------------------->

int main() {
	Solution s;

	for (int i{0}; i < inputArr.size(); i++)
	{
		output processedAnswer{s.solution(inputArr[i])};

		if(processedAnswer != answers[i]){
			cout << "Test failed" << "\n";
			cout << "Test number" << i << "\n";
			cout << "Output" << processedAnswer << "\n";
			cout << "Expected" << answers[i] << "\n";
			return 0;
		} 
	}
	cout << "Tests passed" << "\n";
}
