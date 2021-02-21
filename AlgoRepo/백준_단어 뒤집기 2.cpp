#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	stack<char> sc;
	queue<char> q;
	string s;
	bool check = false;

	getline(cin, s);

	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '<')
		{
			check = true;

			while (!sc.empty())
			{
				cout << sc.top();
				sc.pop();
			}
		}

		if (s[i] == '>' && check)
		{
			q.push(s[i]);

			while (!q.empty())
			{
				cout << q.front();
				q.pop();
			}
			check = false;
			continue;
		}
		else if (check)
		{
			q.push(s[i]);
			continue;
		}

		if (s[i] != ' ' && !check)
			sc.push(s[i]);
		else if (s[i] == ' ' && !check)
		{
			while (!sc.empty())
			{
				cout << sc.top();
				sc.pop();
			}
			cout << " ";
		}
	}
	while (!sc.empty())
	{
		cout << sc.top();
		sc.pop();
	}

	return 0;
}