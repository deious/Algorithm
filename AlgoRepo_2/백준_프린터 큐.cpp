#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N, M;
	cin >> T;

	while (T--)
	{
		cin >> N >> M;
		priority_queue<int> pq;
		queue<pair<int, int>> q;

		int a;
		for (int i = 0; i < N; i++)
		{
			cin >> a;
			q.push({ i, a });
			pq.push(a);
		}

		int answer = 0;
		while (!q.empty())
		{
			int index = q.front().first;
			int priority = q.front().second;

			if (pq.top() == priority)
			{
				pq.pop();
				q.pop();
				answer++;

				if (index == M)
				{
					cout << answer << "\n";
					break;
				}
			}
			else
			{
				q.pop();
				q.push({ index, priority });
			}
		}
	}

	return 0;
}