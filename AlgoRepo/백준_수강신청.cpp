#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K, L;
	cin >> K >> L;

	string s;

	map<string, int> m;
	for (int i = 0; i < L; i++)
	{
		cin >> s;
		m[s] = i;
	}

	vector<pair<string, int>> v;
	for (auto iter = m.begin(); iter != m.end(); iter++)
		v.push_back({ iter->first, iter->second });

	sort(v.begin(), v.end(), cmp);

	int len = v.size();
	len = min(len, K);

	for (int i = 0; i < len; i++)
		cout << v[i].first << "\n";

	return 0;
}