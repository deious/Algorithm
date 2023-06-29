#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int board[100][100];
int group[100][100];
bool check[100][100];
int N, gCount = 0, minCount = 210000000;

int dx[] = { 0 ,0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(int x, int y)
{
	check[x][y] = true;
	group[x][y] = gCount;

	int nx, ny;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny])
			dfs(nx, ny);
	}
}

void bfs(int x, int y, int gNum, int moveCount)
{
	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(x, y, gNum, moveCount));
	
	while (!q.empty())
	{
		x = get<0>(q.front());
		y = get<1>(q.front());
		gNum = get<2>(q.front());
		moveCount = get<3>(q.front());
		int nx, ny;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (!InRange(nx, ny) || group[nx][ny] == gNum)
				continue;

			if (!check[nx][ny] && !group[nx][ny])
			{
				check[nx][ny] = true;
				q.push(make_tuple(nx, ny, gNum, moveCount + 1));
			}
			else if (!check[nx][ny] && group[nx][ny] != gNum)
			{
				if (moveCount < minCount)
					minCount = moveCount;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j] && board[i][j])
			{
				gCount++;
				dfs(i, j);
			}
		}
	}

	memset(check, false, sizeof(check));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (group[i][j])
			{
				check[i][j] = true;
				bfs(i, j, group[i][j], 0);
				memset(check, false, sizeof(check));
			}
		}
	}

	cout << minCount << "\n";

	return 0;
}