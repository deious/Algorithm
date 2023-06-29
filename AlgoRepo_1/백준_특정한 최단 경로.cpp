#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> graph[801];

int dist[801];

int N, E;

void Dijkstra(int num)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, num });

	for (int i = 1; i <= N; i++)
		dist[i] = 210000000;

	dist[num] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (dist[pos] < cost)
			continue;

		for (int i = 0; i < graph[pos].size(); i++)
		{
			int nextCost = graph[pos][i].second;
			int nextPos = graph[pos][i].first;

			if (dist[nextPos] > cost + nextCost)
			{
				dist[nextPos] = cost + nextCost;
				pq.push({ dist[nextPos], nextPos });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> E;
	int a, b, c;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	int toV1, toV2, v1v2, toN, toN1;
	Dijkstra(1);
	toV1 = dist[v1];
	toV2 = dist[v2];

	Dijkstra(v1);
	v1v2 = dist[v2];
	toN = dist[N];

	Dijkstra(v2);
	toN1 = dist[N];

	int temp, temp1;
	temp = toV1 + v1v2 + toN1;
	temp1 = toV2 + v1v2 + toN;
	int answer = 210000000;

	answer = min({ answer, temp, temp1 });

	if (answer == 210000000)
		answer = -1;

	cout << answer << "\n";

	return 0;
}