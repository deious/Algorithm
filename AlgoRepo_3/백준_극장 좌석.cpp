#include <iostream>

using namespace std;

int dp[41];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, num, index = 0, ans = 1;
	cin >> N >> M;

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		ans *= dp[num - index - 1];
		index = num;
	}
	ans *= dp[N - index];

	cout << ans << "\n";

	return 0;
}