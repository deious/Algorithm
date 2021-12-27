#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int board[50][50];
int dp[50][50];
bool check[50][50];

int N, M;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int DFS(int x, int y)
{
	if (!InRange(x, y) || board[x][y] == 0)
		return 0;

	if (check[x][y])
	{
		cout << "-1\n";
		exit(0);
	}

	if (dp[x][y])
		return dp[x][y];

	check[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i] * board[x][y];
		int ny = y + dy[i] * board[x][y];
		dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
	}
	check[x][y] = false;

	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			if (s[j] == 'H')
				board[i][j] = 0;
			else
				board[i][j] = s[j] - '0';
		}
	}

	cout << DFS(0, 0) << "\n";

	return 0;
}