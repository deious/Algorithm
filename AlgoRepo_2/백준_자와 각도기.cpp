#include <iostream>

using namespace std;

int arr[10];
bool dp[10][361];
bool check[361];

int N, K;

void CheckNum(int index, int sum)
{
	if (index >= N || dp[index][sum])
		return;

	check[sum] = true;
	dp[index][sum] = true;

	CheckNum(index, (sum + arr[index]) % 360);
	CheckNum(index + 1, sum);
	CheckNum(index, (360 + sum - arr[index]) % 360);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	CheckNum(0, arr[0]);

	int num;
	for (int i = 0; i < K; i++)
	{
		cin >> num;
		if (check[num])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}