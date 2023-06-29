#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	int N, M;
	while (T--)
	{
		cin >> N >> M;
		vector<int> v(N), v1(M);

		for (int i = 0; i < N; i++)
			cin >> v[i];

		for (int i = 0; i < M; i++)
			cin >> v1[i];

		sort(v.rbegin(), v.rend());
		sort(v1.rbegin(), v1.rend());

		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (v[i] > v1[j])
				{
					ans += M - j;
					break;
				}
			}
		}

		cout << ans << "\n";
 	}

	return 0;
}