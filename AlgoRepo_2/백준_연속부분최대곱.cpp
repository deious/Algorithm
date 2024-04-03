#include <iostream>
#include <algorithm>

using namespace std;

double dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> dp[i];
	}

	double ans = dp[0];

	for (int i = 1; i < N; i++)
	{
		if (dp[i - 1] * dp[i] >= dp[i])
		{
			dp[i] = dp[i - 1] * dp[i];
		}
		
		ans = max(ans, dp[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << ans << "\n";

	return 0;
}