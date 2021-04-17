#include <iostream>

using namespace std;

long long dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N;
	cin >> T;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 100; i++)
		dp[i] = dp[i - 2] + dp[i - 3];

	while (T--)
	{
		cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}