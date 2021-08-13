#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int dp[501][501];
int dist[501][501];
int N, K;

vector<pair<int, int>> point(1000);

int Calculate(int n, int k)
{
	int &num = dp[n][k];

	if (num != -1)
		return num;
	if (n == 1)
		return 0;

	num = INT_MAX;

	for (int i = 0; i <= k; i++)
	{
		if (n - i - 1 >= 1)
			num = min(Calculate(n - i - 1, k - i) + dist[n - i - 1][n], num);
	}

	return num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	int x, y;
	for (int i = 1; i <= N; i++)
		cin >> point[i].first >> point[i].second;


	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N - 1; i++)
		for (int j = i + 1; j <= N; j++)
			dist[i][j] = abs(point[i].first - point[j].first) + abs(point[i].second - point[j].second);

	cout << Calculate(N, K) << "\n";

	return 0;
}