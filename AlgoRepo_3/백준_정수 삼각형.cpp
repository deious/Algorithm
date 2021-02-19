#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501];
int tri[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int size, answer = 0;
	cin >> size;

	for (int i = 0; i < size; i++)
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];

	dp[0][0] = tri[0][0];

	for (int i = 1; i < size; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][0] = dp[i - 1][0] + tri[i][j];
			else if (i == j)
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		}

	for (int i = 0; i < size; i++)
	{
		if (dp[size - 1][i] > answer)
			answer = dp[size - 1][i];
	}

	cout << answer << "\n";

	return 0;
}