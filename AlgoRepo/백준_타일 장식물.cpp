#include <iostream>

using namespace std;

long long dp[81];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	dp[1] = 4;
	dp[2] = 6;
	dp[3] = 10;
	
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N] << "\n";

	return 0;
}