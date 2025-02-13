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
		s.push(temp);
	}

	int topNum = s.top();
	int ans = 1;

	while (!s.empty())
	{
		if (s.top() > topNum)
		{
			topNum = s.top();
			ans++;
		}

		s.pop();
	}

	cout << ans << "\n";

	return 0;
}