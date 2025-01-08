#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int s = 0, e = N - 1;

	int ans = 0;
	while (s < e)
	{
		if (v[s] + v[e] == M)
		{
			ans++;
			s++;
			e--;
		}
		else if (v[s] + v[e] < M)
		{
			s++;
		}
		else
		{
			e--;
		}
	}

	cout << ans << "\n";

	return 0;
}