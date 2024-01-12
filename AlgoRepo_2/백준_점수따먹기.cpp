#include <iostream>
#include <algorithm>

using namespace std;

int board[201][201];
int sumArr[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			sumArr[i][j] = sumArr[i - 1][j] + sumArr[i][j - 1] + board[i][j] - sumArr[i - 1][j - 1];
		}
	}

	int ans = -2100000000;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = i; k <= N; k++)
			{
				for (int l = j; l <= M; l++)
				{
					ans = max(ans, sumArr[k][l] - sumArr[k][j - 1] - sumArr[i - 1][l] + sumArr[i - 1][j - 1]);
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}