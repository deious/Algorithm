#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, H;
	cin >> N >> H;

	vector<int> bottom(H + 1);
	vector<int> top(H + 1);

	int len;
	for (int i = 0; i < N; i++)
	{
		cin >> len;
		if (i % 2 == 0)
		{
			bottom[len]++;
		}
		else
		{
			top[H - len + 1]++;
		}
	}
	for (int i = 1; i <= H; i++)
	{
		top[i] += top[i - 1];
		bottom[H - i] += bottom[H - i + 1];
	}

	long long ans = 100000000000;
	int cnt = 0;

	for (int i = 1; i <= H; i++)
	{
		if (top[i] + bottom[i] < ans)
		{
			cnt = 1;
			ans = top[i] + bottom[i];
		}
		else if (top[i] + bottom[i] == ans)
		{
			cnt++;
		}
	}

	cout << ans << " " << cnt;

	return 0;
}