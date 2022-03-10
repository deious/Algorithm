#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, maxNum;
	cin >> N;
	vector<int> v(N);

	int right = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		right = max(right, v[i]);
	}

	cin >> maxNum;

	int left = 0, mid = 0, answer = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;

		int temp = 0;
		for (int i = 0; i < N; i++)
			temp += min(v[i], mid);

		if (temp > maxNum)
			right = mid - 1;
		else
		{
			answer = mid;
			left = mid + 1;
		}
	}

	cout << answer << "\n";

	return 0;
}