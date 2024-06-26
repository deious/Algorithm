#include <iostream>

using namespace std;

int dp[101][101][2][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int w, h; cin >> w >> h;

	for (int i = 2; i <= h; i++)
	{
		dp[i][1][0][0] = 1;
	}

	for (int i = 2; i <= w; i++)
	{
		dp[1][i][0][1] = 1;
	}


	for (int i = 2; i <= h; i++)
	{
		for (int j = 2; j <= w; j++)
		{
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][1][0]) % 100000;
			dp[i][j][0][1] = (dp[i][j - 1][0][1] + dp[i][j - 1][1][1]) % 100000;
			dp[i][j][1][0] = (dp[i - 1][j][0][1]) % 100000;
			dp[i][j][1][1] = (dp[i][j - 1][0][0]) % 100000;
		}
	}

	cout << (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % 100000 << "\n";

	return 0;
}