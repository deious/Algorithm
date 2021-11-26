#include <iostream>

using namespace std;

int tree[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> tree[i];

	int left = 0, right = 1000000000;
	int answer = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		long long sum = 0;

		for (int i = 1; i <= N; i++)
			if (tree[i] - mid >= 0)
				sum += (tree[i] - mid);

		if (sum >= M)
		{
			if (answer < mid)
				answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer << "\n";

	return 0;
}