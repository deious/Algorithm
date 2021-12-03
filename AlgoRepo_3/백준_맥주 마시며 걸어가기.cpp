#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool check[102];

vector<int> graph[102];

bool Distance(pair<int, int> &a, pair<int, int> &b)
{
	int tx = 0, ty = 0, total = 0;
	tx = a.first - b.first;
	ty = a.second - b.second;

	if (tx < 0)
		tx *= -1;
	if (ty < 0)
		ty *= -1;

	total = tx + ty;

	if (total > 1000)
		return false;
	else
		return true;
}

void DFS(int num)
{
	check[num] = true;

	for (int i = 0; i < graph[num].size(); i++)
	{
		int nx = graph[num][i];
		if (!check[nx])
			DFS(nx);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		int x, y;
		for (int i = 0; i < n + 2; i++)
			graph[i].clear();
		memset(check, false, sizeof(check));
		vector<pair<int, int>> v;

		for (int i = 0; i < n + 2; i++)
		{
			cin >> x >> y;
			v.push_back({ x, y });
		}

		for (int i = 0; i < n + 2; i++)
		{
			for (int j = i + 1; j < n + 2; j++)
			{
				if (Distance(v[i], v[j]))
				{
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		DFS(0);

		if (check[n + 1])
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}