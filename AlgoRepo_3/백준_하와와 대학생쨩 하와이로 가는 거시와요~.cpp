#include <iostream>

using namespace std;

int dp[50001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	dp[0] = dp[1] = dp[2] = 1;
	
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 3]) % 1000000009;
	}

	cout << dp[n] << "\n";

	return 0;
}