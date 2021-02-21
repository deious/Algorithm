#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<int> si;

	int a, N;
	cin >> N;

	while (N--)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			cin >> a;
			si.push(a);
		}
		else if (s == "pop")
		{
			if (!si.empty())
			{
				a = si.top();
				cout << a << "\n";
				si.pop();
			}
			else
				cout << "-1\n";
		}
		else if (s == "size")
			cout << si.size() << "\n";
		else if (s == "top")
		{
			if (!si.empty())
				cout << si.top() << "\n";
			else
				cout << "-1\n";
		}
		else
		{
			if (si.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}