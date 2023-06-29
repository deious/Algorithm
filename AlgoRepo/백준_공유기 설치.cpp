#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, C;
	cin >> N >> C;

	vector<int> v;
	int a;
	
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	int answer = 0;
	int left = 0, right = v[N - 1];

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int prev = 0;
		int num = 1;

		for (int i = 1; i < N; i++)
		{
			if (v[i] - v[prev] >= mid)
			{
				prev = i;
				num++;
			}
		}

		if (num >= C)
			left = mid + 1;
		else
			right = mid - 1;

		if (answer < mid && num >= C)
			answer = mid;
	}

	cout << answer << "\n";

	return 0;
}