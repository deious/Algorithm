#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph(501);
bool check[501];

int answer = 0;

void BFS(int num)
{
	queue<pair<int, int>> q;
	q.push({ num, 0 });
	check[1] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (depth == 1)
			answer++;
		else if (depth == 2)
		{
			answer++;
			continue;
		}

		for (int i = 0; i < graph[x].size(); i++)
		{
			int n = graph[x][i];
			if (!check[n])
			{
				check[n] = true;
				q.push({ n, depth + 1 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	BFS(1);

	cout << answer << "\n";

	return 0;
}