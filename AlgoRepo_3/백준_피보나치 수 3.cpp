#include <iostream>

using namespace std;

long long dp[1500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= 1500000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;

	cout << dp[n % 1500000] << "\n";

	return 0;
}