#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, l = 0, r = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		r += arr[i];

		if (l < arr[i])
		{
			l = arr[i];
		}
	}

	while (l <= r)
	{
		int mid = (l + r) / 2;
		int sum = 0, cnt = 0;

		for (int i = 0; i < N; i++) 
		{
			if (sum + arr[i] > mid) 
			{
				sum = 0;
				cnt++;
			}

			sum += arr[i];
		}

		if (sum != 0)
		{
			cnt++;
		}

		if (cnt > M) 
		{
			l = mid + 1;
		}
		else 
		{
			r = mid - 1;
		}
	}

	cout << l << "\n";

	return 0;
}