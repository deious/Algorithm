#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, result = 0;
int arr[1000];
int dp[1000];

int maxDifference(int idx)
{
	if (idx == N)
		return 0;

	int &result = dp[idx];

	if (result != -1)
		return result;

	result = 0;
	int minNum = 2100000000, maxNum = -1;

	for (int i = idx; i < N; i++)
	{
		minNum = min(minNum, arr[i]);
		maxNum = max(maxNum, arr[i]);

		result = max(result, (maxNum - minNum) + maxDifference(i + 1));
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	cout << maxDifference(0) << "\n";

	return 0;
}