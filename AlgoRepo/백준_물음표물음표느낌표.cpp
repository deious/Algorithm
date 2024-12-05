#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	s += "??!";

	cout << s << "\n";

	return 0;
}