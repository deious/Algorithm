#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, last;

vector<pair<int, int>> graph[1001];

int Dijkstra(int start, int route)
{
	vector<int> distance(route + 1, 2100000000);
	distance[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	int cost, cur, len, next, nextCost;
	while (!pq.empty())
	{
		cost = pq.top().first;
		cur = pq.top().second;
		pq.pop();

		if (distance[cur] < cost)
			continue;

		len = graph[cur].size();
		for (int i = 0; i < len; i++)
		{
			next = graph[cur][i].first;
			nextCost = graph[cur][i].second + cost;

			if (distance[next] > nextCost)
			{
				distance[next] = nextCost;
				pq.push(make_pair(nextCost, next));
			}
		}
	}

	return distance[last];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	int start;
	cin >> start >> last;

	cout << Dijkstra(start, N) << "\n";

	return 0;
}