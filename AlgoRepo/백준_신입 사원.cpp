#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		vector<pair<int, int>> v(N);

		int a, b;
		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			v[i] = { a,b };
		}

		sort(v.begin(), v.end());
		int answer = 1, temp = v[0].second;

		for (int i = 1; i < N; i++)
		{
			if (temp > v[i].second)
			{
				answer++;
				temp = v[i].second;
			}
		}

		cout << answer << "\n";
	}

	return 0;
}