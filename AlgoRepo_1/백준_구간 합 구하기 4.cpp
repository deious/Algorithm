#include <iostream>

using namespace std;

int dp[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << "\n";
	}

	return 0;
}