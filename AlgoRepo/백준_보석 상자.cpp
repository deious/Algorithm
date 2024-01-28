#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> v(M);
	for (int i = 0; i < M; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int left = 1, right = v[M - 1], ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < M; i++)
		{
			cnt += v[i] / mid;
			if (v[i] % mid != 0)
			{
				cnt++;
			}
		}

		if (cnt <= N)
		{
			right = mid - 1;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ans;

	return 0;
}