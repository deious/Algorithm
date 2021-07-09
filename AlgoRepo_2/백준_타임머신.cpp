#include <iostream>
#include <vector>

using namespace std;

int N, M;
long long cityDistance[501];
vector<pair<pair<int, int>, int>> graph;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cityDistance[i] = 2100000000;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		graph.push_back(make_pair(make_pair(a, b), c));
	}

	cityDistance[1] = 0;
	int len = graph.size();

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < len; j++)
		{
			a = graph[j].first.first;
			b = graph[j].first.second;
			c = graph[j].second;

			if (cityDistance[a] == 2100000000)
				continue;

			if (cityDistance[a] + c < cityDistance[b])
				cityDistance[b] = cityDistance[a] + c;
		}
	}

	for (int i = 0; i < len; i++)
	{
		a = graph[i].first.first;
		b = graph[i].first.second;
		c = graph[i].second;

		if (cityDistance[a] == 2100000000)
			continue;

		if (cityDistance[a] + c < cityDistance[b])
		{
			cout << "-1\n";
			return 0;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (cityDistance[i] == 2100000000)
			cout << "-1\n";
		else
			cout << cityDistance[i] << "\n";
	}

	return 0;
}