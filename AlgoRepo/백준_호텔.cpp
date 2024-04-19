#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[21][1001];
vector<pair<int, int>> v(21);

int C, N;

int Calculate(int city, int customer)
{
	if (city > N)
	{
		return 210000000;
	}

	if (customer <= 0)
	{
		return 0;
	}

	int& ret = dp[city][customer];
	if (ret != 0)
	{
		return ret;
	}

	ret = 210000000;
	ret = min(ret, v[city].first + Calculate(city, customer - v[city].second));
	ret = min(ret, Calculate(city + 1, customer));

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> C >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	cout << Calculate(1, C) << "\n";

	return 0;
}