#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	int a, b;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto au : v)
		cout << au.first << " " << au.second << "\n";

	return 0;
}