#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<char> sc;
	int T;
	cin >> T;
	cin.ignore();

	while (T--)
	{
		string s;

		getline(cin, s);
		s += "\n";

		int len = s.size();
		for (int i = 0; i < len; i++)
		{
			if (s[i] != '\n' && s[i] != ' ')
				sc.push(s[i]);
			else if (s[i] == ' ')
			{
				while (!sc.empty())
				{
					cout << sc.top();
					sc.pop();
				}
				cout << " ";
			}
			else
			{
				while (!sc.empty())
				{
					cout << sc.top();
					sc.pop();
				}
				cout << "\n";
			}
		}
	}

	return 0;
}