#include <bits/stdc++.h>
#include "solution.h"
using namespace std;

//<-----------------------Edit below this line------------------------------------------->

using input = vector<int>; //Change the type of your input
using output = vector<int>; //Change the type of your output

//Custom tests and their corresponding answers as an array. 
//Eg. The below tests for the even numbers. 1 -> false, 2 -> true, and so on.
vector<input> inputArr{
						{},
						{1, 2, 2, 0, 3},
						{11, 222, 21, 311, 310},
						{ 155554, 155555, 155557, 155551, 155551, 145555}
					};
vector<output> answers{
						{},
						{ 0, 1, 2, 2, 3},
						{11, 21, 222, 310, 311},
						{  145555,155551,155551, 155554, 155555, 155557  }
					};

//<-----------------------Edit above this line------------------------------------------->

int main() {
	Solution s;

	for (int i{0}; i < inputArr.size(); i++)
	{
		cout << "STD-OUT for Test " << i << "\n";
		output processedAnswer{s.solution(inputArr[i])};
		cout << "=============" << "\n";

		if(processedAnswer != answers[i]){
			cout << "Test failed" << "\n";

			cout << "Test number " << i << "\n";
			cout << "Output"  "\n";
			for(auto a: processedAnswer){
				cout << a << " ";
			}
			cout << "\n";
			cout<< "Expected" << "\n";
			for(auto a: answers[i]){
				cout << a << " ";
			}
			cout << "\n";
			return 0;
		} 
	}
	cout << "Tests passed" << "\n";
}
