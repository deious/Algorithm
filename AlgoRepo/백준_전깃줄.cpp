#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	vector<pair<int, int>> v;

	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[j].second < v[i].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << n - ans << "\n";

	return 0;
}