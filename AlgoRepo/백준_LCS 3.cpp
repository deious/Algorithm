#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[101][101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int n1, n2, n3;
	n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			for (int k = 1; k <= n3; k++)
			{
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });
				}
			}
		}
	}
	cout << dp[n1][n2][n3] << "\n";

	return 0;
}