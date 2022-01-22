#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y;
  string s;
	cin >> x;
	cin >> y;
  //cin would currently be at a \n character so flush that.
  //This is useful when using getline
  cin >> ws;
  //getline is needed to read strings as input
  getline(cin, s);
	cout << x + y << "\n";
  cout << x + y + 1 << "\n";
  cout << s << '\n';
}
