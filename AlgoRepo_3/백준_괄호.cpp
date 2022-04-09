#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		stack<char> s, s1;
		string PS;
		cin >> PS;
		int len = PS.size();

		for (int i = 0; i < len; i++)
			s.push(PS[i]);

		for (int i = 0; i < len; i++)
		{
			if (!s1.empty())
			{
				if (s.top() != s1.top())
				{
					s.pop();
					s1.pop();
				}
				else
				{
					s1.push(s.top());
					s.pop();
				}
			}
			else
			{
				if (s.top() == '(')
				{
					s1.push('(');
					break;
				}
				else
				{
					s1.push(')');
					s.pop();
				}
			}
		}

		if (s1.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}