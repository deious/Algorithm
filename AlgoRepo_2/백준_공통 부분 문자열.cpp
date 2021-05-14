#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[4001][4001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int s1Len = s1.size(), s2Len = s2.size();
	int ans = 0;

	for (int i = 1; i <= s1Len; i++)
	{
		for (int j = 1; j <= s2Len; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}