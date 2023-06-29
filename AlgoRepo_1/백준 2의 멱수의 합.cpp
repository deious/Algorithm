#include <iostream>

using namespace std;

int dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
		dp[i] = (dp[i - 2] + dp[i / 2]) % 1000000000;

	cout << dp[N] << "\n";

	return 0;
}