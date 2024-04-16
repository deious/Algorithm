#include <iostream>

using namespace std;

int dp[21][21][21];

int Calculate(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}

	if (a > 20 || b > 20 || c > 20)
	{
		return Calculate(20, 20, 20);
	}

	if (dp[a][b][c])
	{
		return dp[a][b][c];
	}

	if (a < b && b < c)
	{
		return dp[a][b][c] = Calculate(a, b, c - 1) + Calculate(a, b - 1, c - 1) - Calculate(a, b - 1, c);
	}

	return dp[a][b][c] = Calculate(a - 1, b, c) + Calculate(a - 1, b - 1, c) + Calculate(a - 1, b, c - 1) - Calculate(a - 1, b - 1, c - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;

	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << Calculate(a, b, c) << "\n";
	}

	return 0;
}