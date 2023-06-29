#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, d, c, a, b, s;

int networkDistance[10001];
vector<pair<int, int>> computer[10001];

void Dijkstra()
{
	networkDistance[c] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, c));

	int cost, cur, len, next, nextCost;
	while (!pq.empty())
	{
		cost = pq.top().first;
		cur = pq.top().second;
		pq.pop();

		if (networkDistance[cur] < cost)
			continue;

		len = computer[cur].size();
		for (int i = 0; i < len; i++)
		{
			next = computer[cur][i].first;
			nextCost = computer[cur][i].second + cost;

			if (networkDistance[next] > nextCost)
			{
				networkDistance[next] = nextCost;
				pq.push(make_pair(nextCost, next));
			}
		}
	}

	int connectCount = 0;
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		if (networkDistance[i] != 2100000000)
		{
			connectCount++;
			answer = max(answer, networkDistance[i]);
		}
	}

	cout << connectCount << " " << answer << "\n";

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n >> d >> c;

		for (int i = 1; i <= n; i++)
			computer[i].clear();

		for (int i = 0; i < d; i++)
		{
			cin >> a >> b >> s;
			computer[b].push_back(make_pair(a, s));
		}

		fill_n(networkDistance, 10001, 2100000000);
		Dijkstra();
	}

	return 0;
}