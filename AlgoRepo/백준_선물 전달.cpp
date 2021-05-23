#include <iostream>

using namespace std;

long dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= N; i++)
		dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % 1000000000;

	cout << dp[N] << "\n";

	return 0;
}