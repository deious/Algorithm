#include <iostream>

using namespace std;

int arr[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K, sum = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	int start = 0;
	int end = sum;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int tempSum = 0, cnt = 0;
		for (int i = 0; i < N; i++)
		{
			tempSum += arr[i];
			if (tempSum >= mid)
			{
				cnt++;
				tempSum = 0;
			}
		}

		if (cnt >= K)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << end << "\n";

	return 0;
}