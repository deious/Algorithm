#include <iostream>
#include <algorithm>

using namespace std;

int arr[201];
int dp[201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	int maxCount = 0;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;

		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		maxCount = max(maxCount, dp[i]);
	}

	cout << N - maxCount << "\n";

	return 0;
}