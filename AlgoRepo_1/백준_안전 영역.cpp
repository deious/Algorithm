#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int board[100][100];
bool check[100][100];
int N;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

void dfs(int x, int y, int h)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] > h)
		{
			check[nx][ny] = true;
			dfs(nx, ny, h);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	int maxNum = 0, minNum = 101, ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] > maxNum)
				maxNum = board[i][j];
			if (board[i][j] < minNum)
				minNum = board[i][j];
		}
	}

	int answer = 0;

	if (minNum == maxNum)
	{
		cout << "1\n";
		return 0;
	}

	for (int i = minNum; i < maxNum; i++)
	{
		ans = 0;

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (!check[j][k] && board[j][k] > i)
				{
					ans++;
					check[j][k] = true;
					dfs(j, k, i);
				}
			}
		}
		answer = max(answer, ans);
		memset(check, false, sizeof(check));
	}

	cout << answer << "\n";

	return 0;
}