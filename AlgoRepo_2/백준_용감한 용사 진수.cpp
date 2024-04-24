#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<tuple<int, int, int>> v;
	int a, b, c;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		v.push_back({ a, b, c });
	}

	int ans = 2100000000;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				int cnt = 0;
				int str = get<0>(v[i]);
				int dex = get<1>(v[j]);
				int wise = get<2>(v[k]);

				for (int l = 0; l < N; l++)
				{
					if (get<0>(v[l]) <= str && get<1>(v[l]) <= dex && get<2>(v[l]) <= wise)
					{
						cnt++;
					}
				}

				if (cnt >= K)
				{
					ans = min(ans, str + dex + wise);
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}