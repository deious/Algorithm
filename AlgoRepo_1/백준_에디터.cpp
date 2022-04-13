#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	list<char> l;

	for (int i = 0; i < s.size(); i++)
		l.push_back(s[i]);

	list<char> ::iterator index = l.end();

	int M;
	cin >> M;

	char c;
	while (M--)
	{
		cin >> c;

		if (c == 'L')
		{
			if (index != l.begin())
				index--;
		}
		else if (c == 'D')
		{
			if (index != l.end())
				index++;
		}
		else if (c == 'B')
		{
			if (index != l.begin())
				index = l.erase(--index);
		}
		else
		{
			cin >> c;
			l.insert(index, c);
		}
	}

	for (auto au : l)
		cout << au;
	cout << "\n";

	return 0;
}