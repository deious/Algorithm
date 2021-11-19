#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001];

int solution(vector<int> sticker)
{
	int answer = 0;
	int len = sticker.size();
	if (len == 1)
		return sticker[0];

	dp[0] = sticker[0];
	dp[1] = sticker[0];
	for (int i = 2; i < len - 1; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);

	answer = max(answer, dp[len - 2]);

	dp[0] = 0;
	dp[1] = sticker[1];
	for (int i = 2; i < len; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);

	answer = max(answer, dp[len - 1]);

	return answer;
}