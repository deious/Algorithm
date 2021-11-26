#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dist[1001];
int n, p, k;
vector<vector<pair<int, int>>> graph(1001);

bool Dijkstra(int mid)
{
	for (int i = 1; i <= n; i++)
		dist[i] = 210000000;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;

	while (!pq.empty())
	{
		int current = pq.top().second;
		int pass = pq.top().first;
		pq.pop();

		if (dist[current] > pass)
			continue;

		for (int i = 0; i < graph[current].size(); i++)
		{
			int next = graph[current][i].first;
			int nextPass = pass + (graph[current][i].second > mid);

			if (nextPass < dist[next])
			{
				dist[next] = nextPass;
				pq.push({ nextPass, next });
			}
		}
	}

	return dist[n] <= k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, P, K, answer = -1;
	cin >> N >> P >> K;
	n = N, p = P, k = K;

	int a, b, c, maxNum = 0;
	for (int i = 0; i < p; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
		maxNum = max(maxNum, c);
	}

	int left = 0, mid = 0, right = maxNum;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (Dijkstra(mid))
		{
			right = mid - 1;
			answer = mid;
		}
		else
			left = mid + 1;
	}

	cout << answer << "\n";

	return 0;
}