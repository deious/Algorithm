#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

char board[101][101];
bool check[101][101];

int N, M;

bool InRange(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}

int DFS(int x, int y, char c)
{
	if (!InRange(x, y))
	{
		return 0;
	}

	if (board[x][y] != c || check[x][y])
	{
		return 0;
	}

	check[x][y] = true;
	int ans = 0;

	if (board[x][y] == c)
	{
		ans++;
	}

	for (int i = 0; i < 4; i++)
	{
		ans += DFS(x + dx[i], y + dy[i], c);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> board[i];
	}

	int ansW = 0, ansB = 0, tempAns = 0;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 'W')
			{
				tempAns = DFS(i, j, board[i][j]);
				ansW += tempAns * tempAns;
			}
			else
			{
				tempAns = DFS(i, j, board[i][j]);
				ansB += tempAns * tempAns;
			}
		}
	}

	cout << ansW << " " << ansB << "\n";

	return 0;
}