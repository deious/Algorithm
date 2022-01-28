#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v[20001];
int dist[20001];

int V, E, startPos;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E >> startPos;
	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	for (int i = 1; i <= V; i++)
		dist[i] = 210000000;

	dist[startPos] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, startPos });

	while (!pq.empty())
	{
		int weight = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		int len = v[pos].size();
		for (int i = 0; i < len; i++)
		{
			int nextPos = v[pos][i].first;
			int nextWeight = v[pos][i].second;

			if (dist[nextPos] > weight + nextWeight)
			{
				dist[nextPos] = weight + nextWeight;
				pq.push({ dist[nextPos], nextPos });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] != 210000000)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
	}

	return 0;
}