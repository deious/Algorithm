#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K, N;
	cin >> K >> N;

	vector<int> v(K);
	for (int i = 0; i < K; i++)
		cin >> v[i];

	long long left = 0, right = 2147483647, answer = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		int temp = 0;

		for (int i = 0; i < K; i++)
			temp += v[i] / mid;

		if (temp >= N)
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