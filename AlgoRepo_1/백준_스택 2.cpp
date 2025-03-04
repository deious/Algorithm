#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<int> s;
	int N;
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == 1)
		{
			cin >> temp;
			s.push(temp);
		}
		else if (temp == 2)
		{
			if (s.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (temp == 3)
		{
			cout << s.size() << "\n";
		}
		else if (temp == 4)
		{
			if (s.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (temp == 5)
		{
			if (s.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << s.top() << "\n";
			}
		}
	}

	return 0;
}