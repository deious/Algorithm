#include <iostream>
#include <algorithm>

using namespace std;

long long N, K;

long long Calculate(long long mid)
{
	long long num = 0;
	for (int i = 1; i <= N; i++)
	{
		num += min((long long)N, mid / i);

		if (i > mid)
		{
			break;
		}
	}

	return num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	long long left = 1, right = N * N;
	int ans = 0;

	while (left <= right)
	{
		long long mid = (left + right) >> 1;

		if (Calculate(mid) < K)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}