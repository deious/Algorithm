#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool check[100001];
int V, length = 0, node = 0;

vector<pair<int, int>> graph[100001];

void DFS(int x, int distance)
{
	if (check[x])
		return;

	check[x] = true;

	if (length < distance)
	{
		length = distance;
		node = x;
	}

	int len = graph[x].size();
	for (int i = 0; i < len; i++)
		DFS(graph[x][i].first, graph[x][i].second + distance);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V;
	int a, b, c;

	for (int i = 0; i < V; i++)
	{
		cin >> a;

		while (1)
		{
			cin >> b;
			if (b == -1)
				break;
			cin >> c;

			graph[a].push_back(make_pair(b, c));
		}
	}

	DFS(1, 0);
	length = 0;

	memset(check, false, sizeof(check));
	DFS(node, 0);
	cout << length << "\n";

	return 0;
}