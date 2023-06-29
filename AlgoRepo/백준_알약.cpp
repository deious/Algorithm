#include <iostream>

using namespace std;

long long dp[31][31];

long long search(int a, int b)
{
	if (a < 0) return 0;

	if (dp[a][b] > 0) return dp[a][b];

	if (a == 0 && b == 0) return 1;

	if (a > 0) dp[a][b] += search(a - 1, b + 1);

	if (b > 0) dp[a][b] += search(a, b - 1);

	return dp[a][b];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	search(30, 0);

	while (1)
	{
		cin >> n;

		if (n == 0) break;

		cout << dp[n][0] << "\n";
	}

	return 0;
}