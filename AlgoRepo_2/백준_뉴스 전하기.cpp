#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v[51];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

int DFS(int index)
{
	int ans = 0;

	for (int i = 0; i < v[index].size(); i++)
	{
		int next = v[index][i].second;
		v[index][i].first = DFS(next) + 1;
	}

	sort(v[index].begin(), v[index].end(), cmp);

	for (int i = 0; i < v[index].size(); i++)
	{
		v[index][i].first += i;
		ans = max(ans, v[index][i].first);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num == -1)
			continue;

		v[num].push_back(make_pair(0, i));
	}

	cout << DFS(0) << "\n";

	return 0;
}