#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int board[100002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) 
		cin >> board[i];

	stack<int> s;
	s.push(0);

	int answer = 0, temp = 0;
	for (int i = 1; i <= N + 1; i++)
	{
		while (!s.empty() && board[s.top()] > board[i])
		{
			temp = s.top();
			s.pop();
			answer = max(answer, board[temp] * (i - s.top() - 1));
		}

		s.push(i);
	}

	cout << answer << "\n";

	return 0;
}