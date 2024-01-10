#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, L, H, maxH = 0, maxPos = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> L >> H;
		arr[L] = H;

		if (maxH < H)
		{
			maxPos = L;
			maxH = H;
		}
	}

	int ans = 0, tempH = 0;
	for (int i = 0; i < maxPos; i++)
	{
		tempH = max(tempH, arr[i]);
		ans += tempH;
	}

	tempH = 0;
	for (int i = 1000; i >= maxPos; i--)
	{
		tempH = max(tempH, arr[i]);
		ans += tempH;
	}

	cout << ans << "\n";

	return 0;
}