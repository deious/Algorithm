#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	char c;
	for (int i = 1; i <= N; i++)
	{
		cin >> c;
		
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 1][2];

		if (c == 'H')
		{
			dp[i][0]++;
		}
		else if (c == 'P')
		{
			dp[i][1]++;
		}
		else
		{
			dp[i][2]++;
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		int a = dp[N][0] - dp[i][0];
		int b = dp[N][1] - dp[i][1];
		int c = dp[N][2] - dp[i][2];

		ans = max({ans, dp[i][0] + b, dp[i][0] + c, dp[i][1] + a, dp[i][1] + c, dp[i][2] + a, dp[i][2] + b });
	}

	cout << ans << "\n";

	return 0;
}