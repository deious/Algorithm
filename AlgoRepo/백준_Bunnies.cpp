#include <iostream>

using namespace std;

int dp[46];

int Recursive(int num)
{
	if (dp[num] != 0)
	{
		return dp[num];
	}

	return dp[num] = Recursive(num - 1) + Recursive(num - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;
	
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 0; i < x; i++)
	{
		int num;
		cin >> num;
		cout << Recursive(num) << "\n";
	}

	return 0;
}