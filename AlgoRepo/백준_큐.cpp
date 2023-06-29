#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, num;
	cin >> N;

	string s;
	queue<int> q;

	while (N--)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (s == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else
				cout << "-1\n";
		}
		else if (s == "size")
			cout << q.size() << "\n";
		else if (s == "empty")
		{
			if (!q.empty())
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (s == "front")
		{
			if (!q.empty())
				cout << q.front() << "\n";
			else
				cout << "-1\n";
		}
		else
		{
			if (!q.empty())
				cout << q.back() << "\n";
			else
				cout << "-1\n";
		}
	}

	return 0;
}