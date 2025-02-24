#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int board[101][101];
bool check[101][101];

int N, M, K;

bool InRange(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= M;
}

int DFS(int x, int y)
{
	if (!InRange(x, y))
	{
		return 0;
	}

	if (board[x][y] == 0 || check[x][y])
	{
		return 0;
	}

	check[x][y] = true;
	int ans = 0;

	if (board[x][y])
	{
		ans++;
	}

	for (int i = 0; i < 4; i++)
	{
		ans += DFS(x + dx[i], y + dy[i]);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	int a, b;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b;
		board[a][b] = 1;
	}

	int ans = 0, tempAns = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			ans = max(ans, DFS(i, j));
		}
	}

	cout << ans << "\n";

	return 0;
}