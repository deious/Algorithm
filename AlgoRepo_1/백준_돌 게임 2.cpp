#include <iostream>

using namespace std;

int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;

	for (int i = 4; i <= N; i++)
	{
		if (!dp[i - 1] || !dp[i - 3])
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 0;
		}
	}

	if (dp[N])
	{
		cout << "SK\n";
	}
	else
	{
		cout << "CY\n";
	}

	return 0;
}