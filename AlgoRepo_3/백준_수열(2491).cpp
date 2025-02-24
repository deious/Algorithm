#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	int ans = 1, inc = 1, dec = 1;

	for (int i = 1; i < N; i++)
	{
		if (arr[i] <= arr[i + 1])
		{
			inc++;
		}
		else
		{
			inc = 1;
		}

		if (arr[i] >= arr[i + 1])
		{
			dec++;
		}
		else
		{
			dec = 1;
		}

		int temp = max(inc, dec);
		ans = max(ans, temp);
	}

	cout << ans << "\n";

	return 0;
}