#include <iostream>
#include <algorithm>

using namespace std;

int dp[1500051];
int t[1500001];
int p[1500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;


	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		dp[i + 1] = max(dp[i], dp[i + 1]);
	}

	cout << dp[n + 1];

	return 0;
}