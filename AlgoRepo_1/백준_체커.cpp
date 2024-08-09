#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

vector<pair<int, int>> checker[50];
set<pair<int, int>> s;

int N;
int ans = 210000000;

void Calculate(int num)
{
	for (auto au : s)
	{
		vector<int> distance;
		int temp = 0;

		for (int i = 0; i < N; i++)
		{
			int x = checker[i].front().first;
			int y = checker[i].front().second;
			int dist = abs(au.first - x) + abs(au.second - y);
			distance.push_back(dist);
		}

		sort(distance.begin(), distance.end());

		for (int i = 0; i < num; i++)
		{
			temp += distance[i];
		}

		if (temp < ans)
		{
			ans = temp;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		checker[i].push_back({ x, y });
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			s.insert({ checker[i].front().first, checker[j].front().first });
			s.insert({ checker[i].front().first, checker[j].front().second });
			s.insert({ checker[i].front().second, checker[j].front().first });
			s.insert({ checker[i].front().second, checker[j].front().second });
		}
	}

	cout << 0 << " ";
	for (int i = 2; i <= N; i++)
	{
		ans = 210000000;
		Calculate(i);
		cout << ans << " ";
	}

	return 0;
}