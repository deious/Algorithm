#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, K, R;

bool check[101][101];

vector<pair<int, int>> cowPos;
set<pair<int, int>> board[101][101];

bool InRange(int x, int y)
{
	return x > 0 && x <= N && y > 0 && y <= N;
}

void DFS(int x, int y)
{
	check[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !check[nx][ny] && !board[x][y].count({ nx, ny }))
			DFS(nx, ny);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K >> R;
	int a, b, c, d;
	for (int i = 0; i < R; i++)
	{
		cin >> a >> b >> c >> d;
		board[a][b].insert({ c, d });
		board[c][d].insert({ a, b });
	}

	for (int i = 0; i < K; i++)
	{
		cin >> a >> b;
		cowPos.push_back({ a, b });
	}

	int len = cowPos.size();
	int answer = 0;
	for (int i = 0; i < len; i++)
	{
		memset(check, false, sizeof(check));
		DFS(cowPos[i].first, cowPos[i].second);
		for (int j = i + 1; j < len; j++)
		{
			if (!check[cowPos[j].first][cowPos[j].second])
				answer++;
		}
	}

	cout << answer << "\n";

	return 0;
}