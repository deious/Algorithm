#include <iostream>

using namespace std;

int arr[100001];
int dp[100002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, a, b, k;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> k;
		dp[a] += k;
		dp[b + 1] -= k;
	}

	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += dp[i];
		arr[i] += sum;
		cout << arr[i] << " ";
	}

	return 0;
}