#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	stack<pair<int, int>> s;
	int a;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		while (!s.empty())
		{
			if (s.top().first > a)
			{
				cout << s.top().second << " ";
				break;
			}

			s.pop();
		}

		if (s.empty())
			cout << "0 ";

		s.push({ a, i });
	}

	return 0;
}