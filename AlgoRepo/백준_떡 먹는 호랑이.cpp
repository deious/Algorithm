#include <iostream>

using namespace std;

int dp[31][2];					// [일자][0] = a의 수, [일자][1] = b의 수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int D, K;
	cin >> D >> K;

	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[2][0] = 0;
	dp[2][1] = 1;

	for (int i = 3; i <= D; i++)
	{
		dp[i][0] += (dp[i - 1][0] + dp[i - 2][0]);
		dp[i][1] += (dp[i - 1][1] + dp[i - 2][1]);
	}

	for (int i = 1; dp[D][0] * i <= K; i++)
	{
		for (int j = 1; (dp[D][0] * i) + (dp[D][1] * j) <= K; j++)
		{
			if (dp[D][0] * i + dp[D][1] * j == K)
			{
				cout << i << "\n" << j << "\n";
				return 0;
			}
		}
	}

	return 0;
}