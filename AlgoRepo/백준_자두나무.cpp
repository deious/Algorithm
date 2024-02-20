#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][31][2];
int time[1001];

int T, W;

int Calculate(int t, int w, int pos)
{
	if (w < 0 || t >= T)
	{
		return 0;
	}

	if (dp[t][w][pos])
	{
		return dp[t][w][pos];
	}

	if (!pos)
	{
		dp[t][w][0] += max(Calculate(t + 1, w, pos), Calculate(t + 1, w - 1, 1));
	}
	else
	{
		dp[t][w][1] += max(Calculate(t + 1, w, pos), Calculate(t + 1, w - 1, 0));
	}

	if (time[t] == pos + 1)
	{
		dp[t][w][pos]++;
	}

	return max(dp[t][w][0], dp[t][w][1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T >> W;

	for (int i = 0; i < T; i++)
	{
		cin >> time[i];
	}

	cout << max(Calculate(0, W, 0), Calculate(0, W - 1, 1));

	return 0;
}