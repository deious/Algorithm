#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	if (next_permutation(s.begin(), s.end()))
	{
		cout << s << "\n";
	}
	else
	{
		cout << "0\n";
	}
}