#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v[101];
int item[101];
int Luck[101];
int n, m, r;

int Dijkstra(int start)
{
	for (int i = 1; i <= n; i++)
	{
		Luck[i] = 210000000;
	}

	Luck[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int roadLen = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nextRoad = v[cur][i].second;

			if (roadLen + nextRoad < Luck[next])
			{
				Luck[next] = roadLen + nextRoad;
				pq.push({roadLen + nextRoad , next });
			}
		}
	}

	int totalLen = 0;

	for (int i = 1; i <= n; i++)
	{
		if (Luck[i] <= m)
		{
			totalLen += item[i];
		}
	}

	return totalLen;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}

	int from, to, roadLen;
	for (int i = 0; i < r; i++)
	{
		cin >> from >> to >> roadLen;
		v[from].push_back({ to, roadLen });
		v[to].push_back({ from, roadLen });
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, Dijkstra(i));
	}

	cout << ans << "\n";

	return 0;
}