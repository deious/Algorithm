#include <iostream>
#include <cstring>

using namespace std;

int dp[1001];
int arr[3] = { 1, 3, 4 };

bool Calculate(int n)
{
	if (n < 0)
	{
		return true;
	}

	if (n == 0)
	{
		return false;
	}

	if (dp[n] != -1)
	{
		return dp[n];
	}

	int cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		if (!Calculate(n - arr[i]))
		{
			cnt++;
		}
	}

	if (cnt > 0)
	{
		dp[n] = cnt;
		return dp[n];
	}
	else
	{
		dp[n] = cnt;
		return dp[n];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	memset(dp, -1, sizeof(dp));

	if (Calculate(N))
	{
		cout << "SK\n";
	}
	else
	{
		cout << "CY\n";
	}

	return 0;
}