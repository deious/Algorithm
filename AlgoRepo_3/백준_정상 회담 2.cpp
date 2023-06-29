#include <iostream>
#include <cstring>

using namespace std;

long dp[10001];

long calculate(int n)
{
	if (n == 0 || n == 2)
		return 1;

	long &ans = dp[n];

	if (ans != -1)
		return ans;

	ans = 0;
	for (int i = 0; i <= n - 2; i += 2)
	{
		ans += calculate(i) * calculate(n - 2 - i);
		ans %= 987654321;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;

	memset(dp, -1, sizeof(dp));
	cout << calculate(N) << "\n";

	return 0;
}