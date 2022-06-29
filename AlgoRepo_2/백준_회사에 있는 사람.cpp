#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	set<string> s;

	string s1, s2;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;

		if (s2 == "enter")
			s.insert(s1);
		else
			s.erase(s1);
	}

	for (auto iter = s.rbegin(); iter != s.rend(); iter++)
		cout << *iter << "\n";

	return 0;
}