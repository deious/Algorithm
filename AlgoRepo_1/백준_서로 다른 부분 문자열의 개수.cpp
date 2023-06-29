#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s1;
	cin >> s1;

	set<string> s;
	string s2 = "";

	int len = s1.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			s2 += s1[j];
			s.insert(s2);
		}
		s2 = "";
	}
	
	cout << s.size() << "\n";

	return 0;
}