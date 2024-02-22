#include <iostream>
#include <cstring>

using namespace std;

int dp[501][501];
int arr[3];
int A, B;

bool Calculate(int a, int b)
{
	if (a < 0 || b < 0)
	{
		return true;
	}

	if (a < arr[0] && b < arr[0])
	{
		return false;
	}

	if (dp[a][b] != -1)
	{
		return dp[a][b];
	}

	int cnt = 0;

	for (int i = 0; i < 3; i++)
	{
		if (!Calculate(a - arr[i], b))
		{
			cnt++;
		}

		if (!Calculate(a, b - arr[i]))
		{
			cnt++;
		}
	}

	if (cnt > 0)
	{
		dp[a][b] = cnt;
		return dp[a][b];
	}
	else
	{
		dp[a][b] = 0;
		return dp[a][b];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> arr[0] >> arr[1] >> arr[2];
	
	for (int i = 0; i < 5; i++)
	{
		cin >> A >> B;
		memset(dp, -1, sizeof(dp));

		if (Calculate(A, B))
		{
			cout << "A\n";
		}
		else
		{
			cout << "B\n";
		}
	}

	return 0;
}