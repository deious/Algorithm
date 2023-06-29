#include <iostream>
#include <algorithm>

using namespace std;

int nArr[101];
int mArr[101];
int dp[101][10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, ans = 2100000000;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> nArr[i];

	for (int i = 1; i <= N; i++)
		cin >> mArr[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (mArr[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - mArr[i]] + nArr[i]);
			else
				dp[i][j] = dp[i - 1][j];

			if (dp[i][j] >= M)
				ans = min(ans, j);
		}
	}

	cout << ans << "\n";

	return 0;
}