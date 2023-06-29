#include <iostream>

using namespace std;

int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	
	for (int i = 4; i <= N; i++)
		for (int j = 1; j <= K; j++)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;

	cout << dp[N][K] << "\n";

	return 0;
}