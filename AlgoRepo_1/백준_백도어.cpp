#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int eyeSight[100000];
long long dist[100000];
vector<pair<int, long long>> road[100000];

int N, M;

void Dijkstra()
{
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({ 0, 0 });

	dist[0] = 0;

	while(!pq.empty())
	{
		int cur = pq.top().second;
		long long time = pq.top().first;

		pq.pop();

		if (dist[cur] < time)
		{
			continue;
		}

		for (int i = 0; i < road[cur].size(); i++)
		{
			int next = road[cur][i].first;
			long long nTime = time + road[cur][i].second;

			if (!eyeSight[next] || next == N - 1)
			{
				if (dist[next] > nTime)
				{
					dist[next] = nTime;
					pq.push({ nTime, next });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> eyeSight[i];
		dist[i] = 30000000000;
	}

	for (int i = 0; i < M; i++)
	{
		int from, to, time;
		cin >> from >> to >> time;

		if ((!eyeSight[from] && !eyeSight[to]) || (from == N - 1 || to == N - 1))
		{
			road[from].push_back({ to, (long long)time });
			road[to].push_back({ from, (long long)time });
		}
	}

	Dijkstra();

	cout << (dist[N - 1] == 30000000000 ? -1 : dist[N - 1]) << "\n";

	return 0;
}