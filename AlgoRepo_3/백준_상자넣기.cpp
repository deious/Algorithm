#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";

	return 0;
}