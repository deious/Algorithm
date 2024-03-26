#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[300001];
int dist[300001];

void Calculate(int city)
{
	dist[city] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, city });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;

		pq.pop();

		if (dist[cur] < cost)
		{
			continue;
		}

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			int nCost = cost + 1;

			if (dist[next] > nCost)
			{
				dist[next] = nCost;
				pq.push({ nCost, next });
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	for (int i = 1; i <= N; i++)
	{
		dist[i] = 210000000;
	}

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}

	Calculate(X);

	bool check = false;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == K)
		{
			check = true;
			cout << i << "\n";
		}
	}

	if (!check)
	{
		cout << "-1\n";
	}

	return 0;
}