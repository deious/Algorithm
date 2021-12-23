#include <iostream>

using namespace std;

int dp[46];

int Fibo(int n)
{
	if (n <= 1)
		return n;

	if (dp[n] > 0)
		return dp[n];

	return dp[n] = Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = 1;

	int n;
	cin >> n;

	cout << Fibo(n) << "\n";

	return 0;
}