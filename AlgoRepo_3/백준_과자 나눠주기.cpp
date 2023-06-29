#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int left = 1, mid = 0, right = v[N - 1];
	int answer = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		int temp = 0;
		for (int i = 0; i < N; i++)
			temp += v[i] / mid;

		if (temp >= M)
		{
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer << "\n";

	return 0;
}