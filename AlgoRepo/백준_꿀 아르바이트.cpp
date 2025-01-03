#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100001];
long long sum[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}

	long long ans = 0;
	for (int i = m; i <= n; i++)
	{
		ans = max(ans, sum[i] - sum[i - m]);
	}

	cout << ans << "\n";

	return 0;
}