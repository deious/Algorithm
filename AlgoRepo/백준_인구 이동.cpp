#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N, L, R, aCount = 0, ans = 0, sum = 0;
int board[50][50];
bool check[50][50];
bool endCheck;

queue<pair<int, int>> q;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

bool InRange2(int x, int y)
{
	if (x > y)
	{
		int n = x - y;
		return n >= L && n <= R;
	}
	else
	{
		int n = y - x;
		return n >= L && n <= R;
	}
}

void DFS(int x, int y)
{
	aCount++;
	sum += board[x][y];
	q.push(make_pair(x, y));

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !check[nx][ny] && InRange2(board[x][y], board[nx][ny]))
		{
			check[nx][ny] = true;
			DFS(nx, ny);
		}
	}
}

void BoardChange(int x, int y)
{
	if (aCount == 1)
	{
		sum = 0;
		aCount = 0;
		while (!q.empty())
			q.pop();
		return;
	}

	sum /= aCount;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		board[x][y] = sum;
	}

	sum = 0;
	aCount = 0;
	endCheck = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	endCheck = false;

	while (!endCheck)
	{
		endCheck = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!check[i][j])
				{
					check[i][j] = true;
					DFS(i, j);
					BoardChange(i, j);
				}
			}
		}
		
		memset(check, false, sizeof(check));

		if (!endCheck)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}