#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	map<string, int> m;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		m[s]++;
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	cout << v[0].first << "\n";

	return 0;
}