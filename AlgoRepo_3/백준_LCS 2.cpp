#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];
string lcs[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s, s1;
	cin >> s >> s1;

	int sLen = s.size(), s1Len = s1.size();

	for (int i = 1; i <= sLen; i++)
	{
		for (int j = 1; j <= s1Len; j++)
		{
			if (s[i - 1] == s1[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				lcs[i][j] += lcs[i - 1][j - 1] + s[i - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

				if (lcs[i - 1][j].size() > lcs[i][j - 1].size())
					lcs[i][j] = lcs[i - 1][j];
				else
					lcs[i][j] = lcs[i][j - 1];
			}
		}
	}

	cout << dp[sLen][s1Len] << "\n" << lcs[sLen][s1Len] << "\n";

	return 0;
}