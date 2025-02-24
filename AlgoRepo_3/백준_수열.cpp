#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int start, end, N, K, sum = 0, ans = -2100000000;
	cin >> N >> K;

	start = 0;
	end = K - 1;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i <= K - 1; i++)
	{
		sum += v[i];
	}
	for (int i = 0; i <= N - K; i++)
	{
		ans = max(ans, sum);

		if (end == N - 1)
		{
			break;
		}
		else 
		{
			sum -= v[start++];
			sum += v[++end];
		}
	}

	cout << ans << "\n";
}