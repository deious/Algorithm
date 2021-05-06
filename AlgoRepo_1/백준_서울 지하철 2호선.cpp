#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dist[3001];
int check[3001];
bool checkCycle[3001];

vector<int> v[3001];
int N;

void DFS(int start, int next, int moveCount)
{
	check[next] = true;

	int len = v[next].size();
	for (int i = 0; i < len; i++)
	{
		int nx = v[next][i];

		if (!check[nx])
			DFS(start, nx, moveCount + 1);
		else if (start == nx && moveCount >= 2)
		{
			checkCycle[start] = true;
			return;
		}
	}
}

void BFS(int start)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		int s = q.front().first;
		int c = q.front().second;
		q.pop();
		check[s] = true;
		dist[s] = c;

		int len = v[s].size();
		for (int i = 0; i < len; i++)
		{
			if (!checkCycle[v[s][i]] && !check[v[s][i]])
			{
				check[v[s][i]] = true;
				q.push(make_pair(v[s][i], c + 1));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int a, b;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(check, false, sizeof(check));
		DFS(i, i, 0);
	}

	memset(check, false, sizeof(check));

	for (int i = 1; i <= N; i++)
	{
		if (checkCycle[i])
			BFS(i);
	}

	for (int i = 1; i <= N; i++)
		cout << dist[i] << " ";
	cout << "\n";

	return 0;
}