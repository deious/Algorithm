#include <vector>

using namespace std;

long long dp[21];
bool check[21];

vector<int> solution(int n, long long k) {
	vector<int> answer(n);

	dp[0] = 1;

	for (int i = 1; i < 21; i++) dp[i] = dp[i - 1] * i;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check[j]) continue;

			if (dp[n - i - 1] < k) k -= dp[n - i - 1];
			else
			{
				answer[i] = j;
				check[j] = true;
				break;
			}
		}
	}


	return answer;
}