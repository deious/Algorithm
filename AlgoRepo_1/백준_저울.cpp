#include <iostream>

using namespace std;

int N, M;

bool board[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		board[a][b] = true;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (board[i][k] && board[k][j])
					board[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int ans = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;

			if (!board[i][j] && !board[j][i])
				ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}