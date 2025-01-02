#include <iostream>
#include <algorithm>

using namespace std;

int arr[250001];
int sum[250001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, X;
	cin >> N >> X;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}

	int ans = 0;
	int temp = 0;
	int cnt = 1;
	for (int i = X; i <= N; i++)
	{
		temp = sum[i] - sum[i - X];
		if (temp >= ans)
		{
			if (temp == ans)
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}
		}

		ans = max(ans, sum[i] - sum[i - X]);
	}

	if (!ans)
	{
		cout << "SAD\n";
	}
	else
	{
		cout << ans << "\n" << cnt << "\n";
	}

	return 0;
}