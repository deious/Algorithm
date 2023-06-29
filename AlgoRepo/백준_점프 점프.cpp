#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> dp(N + 1, 2100000000);

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[0] = 0;
	dp[1] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= i + arr[i]; j++)
		{
			if (j > N) 
				break;
			dp[j] = min(dp[j], dp[i] + 1);
		}
	}

	if (dp[N] == 2100000000)
		cout << -1 << "\n";
	else
		cout << dp[N] << "\n";

	return 0;
}