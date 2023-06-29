#include <iostream>
#include <algorithm>

using namespace std;

long long time[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	long long right = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> time[i];
		right = max(right, time[i]);
	}

	right *= M;

	long long left = 0, answer = 0, sum = 0, mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;

		sum = 0;
		for (int i = 0; i < N; i++)
			sum += (mid / time[i]);

		if (sum >= M)
		{
			answer = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << answer << "\n";

	return 0;
}