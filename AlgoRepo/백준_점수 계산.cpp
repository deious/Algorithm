#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<int, int>> v(8);
	int temp;

	for (int i = 0; i < 8; i++)
	{
		cin >> temp;
		v[i] = { temp, i + 1 };
	}

	sort(v.begin(), v.end());
	int sum = 0;

	for (int i = 3; i < 8; i++)
	{
		sum += v[i].first;
	}

	sort(v.begin() + 3, v.end(), cmp);
	cout << sum << "\n";

	for (int i = 3; i < 8; i++)
	{
		cout << v[i].second << " ";
	}

	return 0;
}