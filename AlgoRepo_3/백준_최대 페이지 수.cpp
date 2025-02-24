#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> v;

int N, M;
int dp[201][21];

int Read(int day, int chapter)
{
	if (day <= 0 || chapter == M)
	{
		return 0;
	}

	if (dp[day][chapter] != -1)
	{
		return dp[day][chapter];
	}

	int ret = Read(day, chapter + 1);

	if (day >= v[chapter].first)
	{
		ret = max(ret, Read(day - v[chapter].first, chapter + 1) + v[chapter].second);
	}

	return dp[day][chapter] = ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	memset(dp, -1, sizeof(dp));

	int ans = Read(N, 0);

	cout << ans << "\n";

	return 0;
}