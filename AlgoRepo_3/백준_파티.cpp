#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v[1001];
int dist[1001];
int townDist[1001];
int N, M, X;

void Dijkstra(int town)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[town] = 0;
	pq.push({ 0, town });

	while (!pq.empty())
	{
		int curDist = pq.top().first;
		int curTown = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[curTown].size(); i++)
		{
			int nextDist = v[curTown][i].second;
			int nextTown = v[curTown][i].first;

			if (dist[nextTown] > curDist + nextDist)
			{
				dist[nextTown] = curDist + nextDist;
				pq.push({ dist[nextTown], nextTown });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> X;
	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dist[j] = 210000000;
		}
		Dijkstra(i);
		townDist[i] = dist[X];
	}

	for (int i = 1; i <= N; i++)
		dist[i] = 210000000;

	Dijkstra(X);
	for (int i = 1; i <= N; i++)
		townDist[i] += dist[i];

	sort(townDist + 1, townDist + N + 1);

	cout << townDist[N] << "\n";

	return 0;
}