#include <iostream>
#include <algorithm>

using namespace std;

int dp[21][2];
int N, K;

pair<int, int> p[21];

int Calculate(int num, int useJump)
{
	if (num == N)
	{
		return 0;
	}

	if (num > N)
	{
		return 210000000;
	}

	int& ret = dp[num][useJump];

	if (ret != -1)
	{
		return ret;
	}

	ret = 210000000;
	ret = min(ret, Calculate(num + 1, useJump) + p[num].first);
	ret = min(ret, Calculate(num + 2, useJump) + p[num].second);

	if (!useJump)
	{
		ret = min(ret, Calculate(num + 3, 1) + K);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N - 1; i++)
	{
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	for (int i = 1; i <= N - 1; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	cin >> K;

	cout << Calculate(1, 0) << "\n";

	return 0;
}