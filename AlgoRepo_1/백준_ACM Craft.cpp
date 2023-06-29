#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> graph[1001];

int time[1001];
int totalTime[1001];
int check[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	int N, K;
	while (T--)
	{
		memset(graph, 0, sizeof(graph));
		memset(totalTime, 0, sizeof(totalTime));
		memset(check, 0, sizeof(check));

		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> time[i];

		int a, b;
		for (int i = 1; i <= K; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			check[b]++;
		}

		int W;
		cin >> W;

		queue<int> q;
		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
			{
				q.push(i);
				totalTime[i] = time[i];
			}
		}

		while (!q.empty())
		{
			int pos = q.front();
			q.pop();

			if (pos == W)
				break;

			for (int i = 0; i < graph[pos].size(); i++)
			{
				int nextPos = graph[pos][i];
				if (--check[nextPos] == 0)
					q.push(graph[pos][i]);

				totalTime[nextPos] = max(totalTime[nextPos], totalTime[pos] + time[nextPos]);
			}
		}

		cout << totalTime[W] << "\n";
	}

	return 0;
}