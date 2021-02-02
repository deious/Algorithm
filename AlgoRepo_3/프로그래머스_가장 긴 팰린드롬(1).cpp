#include <string>
#include <algorithm>

using namespace std;

bool dp[2500][2500];

int solution(string s)
{
	int ans = 1;
	int len = s.size();

	for (int i = 0; i < len; i++) dp[i][i] = true;

	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = true;
			ans = 2;
		}
	}

	for (int i = 3; i <= len; i++)
	{
		for (int j = 0; j <= len - i; j++)
		{
			int k = i + j - 1;
			if (s[j] == s[k] && dp[j + 1][k - 1])
			{
				dp[j][k] = true;
				ans = max(ans, i);
			}
		}
	}

	return ans;
}