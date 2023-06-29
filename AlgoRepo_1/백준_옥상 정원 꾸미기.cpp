#include <iostream>
#include <stack>

using namespace std;

int building[80000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> building[i];

	stack<int> s;

	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && s.top() <= building[i])
			s.pop();

		s.push(building[i]);
		answer += (s.size() - 1);
	}

	cout << answer << "\n";

	return 0;
}