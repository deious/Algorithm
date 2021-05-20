#include <iostream>
#include <string>

using namespace std;

int dp[5001];
int arr[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int len = s.size();

	for (int i = 1; i <= len; i++)
		arr[i] = s[i - 1] - '0';

	if (!arr[1] && len == 1)
	{
		cout << "0" << "\n";
		return 0;
	}

	dp[0] = 1;
	int checkNum = 0;

	for (int i = 1; i <= len; i++)
	{
		if (arr[i] > 0 && arr[i] < 10)
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;

		if (i == 1)
			continue;

		checkNum = arr[i - 1] * 10 + arr[i];
		if (checkNum > 9 && checkNum < 27)
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}

	cout << dp[len] << "\n";

	return 0;
}