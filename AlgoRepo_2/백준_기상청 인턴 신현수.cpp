#include <iostream>

using namespace std;

int dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	int maxNum = -21000000;
	for (int i = K; i <= N; i++)
	{
		maxNum = max(maxNum, dp[i] - dp[i - K]);
	}

	cout << maxNum << "\n";

	return 0;
}