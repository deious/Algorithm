#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, num;
	cin >> N;

	string s;
	deque<int> dq;

	while (N--)
	{
		cin >> s;
		if (s == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}
		else if (s == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}
		else if (s == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (s == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (s == "size")
			cout << dq.size() << "\n";
		else if (s == "empty")
		{
			if (!dq.empty())
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (s == "front")
		{
			if (!dq.empty())
				cout << dq.front() << "\n";
			else
				cout << "-1\n";
		}
		else
		{
			if (!dq.empty())
				cout << dq.back() << "\n";
			else
				cout << "-1\n";
		}
	}

	return 0;
}