#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool check[1001];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
		
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N, M;
	cin >> T;

	int a, b;
	while (T--)
	{
		cin >> N >> M;
		memset(check, false, sizeof(check));
		vector<pair<int, int>> v;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			v.push_back({ a, b });
		}

		sort(v.begin(), v.end(), cmp);

		int answer = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = v[i].first; j <= v[i].second; j++)
			{
				if (!check[j])
				{
					check[j] = true;
					answer++;
					break;
				}
			}
		}

		cout << answer << "\n";
	}

	return 0;
}