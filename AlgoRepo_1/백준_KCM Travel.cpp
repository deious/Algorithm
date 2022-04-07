#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dp[101][10001];
int T, N, M, K;

vector<tuple<int, int, int>> graph[101];

void Dijkstra()
{
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push({ 0, 1, 0 });
	dp[1][0] = 0;

	while (!pq.empty())
	{
		int time = get<0>(pq.top());
		int start = get<1>(pq.top());
		int cost = get<2>(pq.top());
		pq.pop();

		if (dp[start][cost] < time)
			continue;

		int len = graph[start].size();

		for (int i = 0; i < len; i++)
		{
			int nt = time + get<0>(graph[start][i]);
			int ns = get<1>(graph[start][i]);
			int nc = cost + get<2>(graph[start][i]);

			if (nc > M || dp[ns][nc] <= nt)
				continue;

			for (int j = nc; j <= M; j++)
			{
				if (dp[ns][j] > nt)
					dp[ns][j] = nt;
			}

			pq.push({ nt, ns, nc });
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	int u, v, c, d;

	while (T--)
	{
		int ans = 200000000;
		cin >> N >> M >> K;

		for (int i = 1; i <= 100; i++)
		{
			graph[i].clear();

			for (int j = 0; j <= 10000; j++)
			{
				dp[i][j] = 200000000;
			}
		}

		for (int i = 0; i < K; i++)
		{
			cin >> u >> v >> c >> d;
			graph[u].push_back(make_tuple(d, v, c));
		}

		Dijkstra();

		for (int i = 1; i <= M; i++)
			ans = min(ans, dp[N][i]);

		if (ans == 200000000)
			cout << "Poor KCM\n";
		else
			cout << ans << "\n";
	}

	return 0;
}