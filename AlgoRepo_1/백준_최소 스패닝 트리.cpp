#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];

int Find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y)
		parent[y] = x;
}

bool SameParent(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int V, E, A, B, C, ans = 0;
	cin >> V >> E;

	vector<pair<int, pair<int, int>>> graph;
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		graph.push_back(make_pair(C, make_pair(A, B)));
	}

	sort(graph.begin(), graph.end());

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	for (int i = 0; i < E; i++)
	{
		if (!SameParent(graph[i].second.first, graph[i].second.second))
		{
			Union(graph[i].second.first, graph[i].second.second);
			ans += graph[i].first;
		}
	}

	cout << ans << "\n";

	return 0;
}