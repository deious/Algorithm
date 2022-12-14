#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[101][51];
int arr[101];

int N, M;

int calculate(int n, int m)
{
	if (m == 0)
	{
		return 0;
	}
	if (n <= 0)
	{
		return -2100000000;
	}

	if (dp[n][m] != -1)
	{
		return dp[n][m];
	}

	int sum = 0;
	dp[n][m] = calculate(n - 1, m);

	for (int i = n; i > 0; i--)
	{
		sum += arr[i];
		int temp = calculate(i - 2, m - 1) + sum;
		dp[n][m] = max(dp[n][m], temp);
	}

	return dp[n][m];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << calculate(N, M) << "\n";

	return 0;
}