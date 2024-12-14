#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	while (prev_permutation(s.begin(), s.end()));

	cout << s << "\n";

	return 0;
}