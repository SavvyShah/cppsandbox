#include <bits/stdc++.h>
using namespace std;

//edit code below this line
class Solution{
  public:
    bool solution(int n){
      if(n % 2 == 0){
        return true;
      }else{
        return false;
      }
    }
};

typedef int test;
typedef bool solution;
constexpr int N = 5; //No of tests

vector<test> tests{1, 2, 3, 4, 5};
vector<solution> solutions{false, true, false, true, false};
//edit code above this line

int main() {
	Solution s;

	for (int i{0}; i < tests.size(); i++)
	{
		solution output{s.solution(tests[i])};

		if(output != solutions[i]){
			cout << "Test failed" << "\n";
			cout << "Test number" << i << "\n";
			cout << "Output" << output << "\n";
			cout << "Expected" << solutions[i] << "\n";
			return 0;
		} 
	}
	cout << "Tests passed" << "\n";
}
