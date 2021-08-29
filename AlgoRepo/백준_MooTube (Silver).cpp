#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

int N, Q;
bool check[5001];

vector<pair<int, int>> v[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> Q;

	int a, b, c;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	int K, V;
	for (int i = 0; i < Q; i++)
	{
		cin >> K >> V;

		memset(check, false, sizeof(check));
		queue<int> q;
		q.push(V);
		check[V] = true;

		int ans = 0;

		while (!q.empty())
		{
			int cur = q.front();
			int len = v[cur].size();
			q.pop();

			for (int i = 0; i < len; i++)
			{
				int next = v[cur][i].first;
				int count = v[cur][i].second;

				if (check[next])
					continue;

				if (count >= K)
				{
					ans++;
					check[next] = true;
					q.push(next);
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}