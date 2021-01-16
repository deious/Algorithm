#include <string>
#include <vector>

using namespace std;

int dp[100001];

int fibo(int n)
{
	if (n < 3) return 1;

	if (dp[n] != 0) return dp[n] % 1234567;
	else
	{
		dp[n] = fibo(n - 1) + fibo(n - 2);
		return dp[n] % 1234567;
	}
}

int solution(int n) {
	dp[0] = 0;
	dp[1] = 1;
	return fibo(n);
}