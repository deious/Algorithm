#include <string>
#include <vector>

using namespace std;

int dp[15];

int solution(int n) {
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] += dp[i - j] * dp[j - 1];

	return dp[n];
}