#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, string>> v(N);
	int num;
	string s;

	for (int i = 0; i < N; i++)
	{
		cin >> num >> s;
		v[i] = { num, s };
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}