#include <iostream>
#include <cstring>

using namespace std;

int dp[1001];

int Calculate(int num)
{
	if (num <= 0)
	{
		return 0;
	}

	if (dp[num] != -1)
	{
		return dp[num];
	}

	int cnt = Calculate(num - 1) + Calculate(num - 3) + Calculate(num - 4);

	if (cnt > 0)
	{
		return dp[num] = 0;
	}
	else
	{
		return dp[num] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	memset(dp, -1, sizeof(dp));

	if (!Calculate(N))
	{
		cout << "SK\n";
	}
	else
	{
		cout << "CY\n";
	}

	return 0;
}