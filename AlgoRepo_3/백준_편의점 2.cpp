#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y)
{
	return x.second < y.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	int a, b;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v[i] = { a,b };
	}

	sort(v.begin(), v.end());
	int left, right;
	if (n % 2 == 0)
	{
		left = v[(n - 1) / 2].first;
	}
	else
	{
		left = v[n / 2].first;
	}

	sort(v.begin(), v.end(), cmp);
	if (n % 2 == 0)
	{
		right = v[(n - 1) / 2].second;
	}
	else
	{
		right = v[n / 2].second;
	}
	
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (abs(left - v[i].first) + abs(right - v[i].second));
	}

	cout << ans << "\n";

	return 0;
}