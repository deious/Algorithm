#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
	int answer = 0;
	int len = money.size();
	vector<int> dp(len);
	vector<int> dp1(len);
	dp[0] = money[0];
	dp[1] = money[0];
	dp1[1] = money[1];

	for (int i = 2; i < len - 1; i++)
	{
		dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
	}

	for (int i = 2; i < len; i++)
	{
		dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
	}

	return answer = max(dp[len - 2], dp1[len - 1]);
}