#include <iostream>
#include <string>

using namespace std;

long long dp[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int len;
	string s;
	cin >> len >> s;

	long long ans = 0;
	for (int i = 0; i < len; i++) 
	{
		if (s[i] == 'W')
		{
			dp[0]++;
			dp[0] %= 1000000007;
		}
		else if (s[i] == 'H')
		{
			dp[1] += dp[0];
			dp[1] %= 1000000007;
		}
		else if (s[i] == 'E')
		{
			ans += dp[2];
			dp[2] += dp[2] + dp[1];
			dp[2] %= 1000000007;
		}
		
		ans %= 1000000007;
	}

	cout << ans << "\n";

	return 0;
}