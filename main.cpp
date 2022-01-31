#include <bits/stdc++.h>

using namespace std;

class Solution
{
	string &s;

public:
	Solution(string &str) : s{str}
	{
	}
	string reverseString()
	{
		reverse(s.begin(), s.end());
		return s;
	}
};

int main()
{
	int t; //no. of test cases
	cin >> t;
	while (true)
	{
		continue;
	}
	for (int i = 0; i < t; i++)
	{
		string s;
		//Necessary to use getline. cin would be currently at \n and the below removes that whitespace(ws)
		cin >> ws;
		getline(cin, s);
		Solution sol{Solution(s)};

		cout << sol.reverseString() << '\n';
	}
}
