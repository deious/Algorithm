#include <iostream>

using namespace std;

long long dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N;
	cin >> T;

	dp[0] = 1;
	dp[3] = 3;
	dp[6] = 13;

	for (int i = 9; i <= 10000; i += 3)
	{
		dp[i] = (((5 * dp[i - 3]) % 1000000007) + 1000000007 - ((3 * dp[i - 6]) % 1000000007) + dp[i - 9]) % 1000000007;
	}

	while (T--)
	{
		cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}