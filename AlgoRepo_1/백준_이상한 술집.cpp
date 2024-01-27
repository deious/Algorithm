#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	long long left = 1, right = v[N - 1];

	while (left <= right)
	{
		long long mid = (left + right) >> 1;
		long long temp = 0;

		for (int i = 0; i < N; i++)
		{
			temp += v[i] / mid;
		}

		if (temp >= K)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << right << "\n";

	return 0;
}