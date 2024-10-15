#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];

	sort(v.begin(), v.end());

	int ans = 0;
	if (v[0] == v[1] && v[1] == v[2])
	{
		ans += (10000 + v[0] * 1000);
	}
	else if (v[0] != v[1] && v[1] != v[2] && v[0] != v[2])
	{
		ans += v[2] * 100;
	}
	else
	{
		if (v[0] == v[1])
		{
			ans += 1000 + v[0] * 100;
		}
		else
		{
			ans += 1000 + v[1] * 100;
		}
	}

	cout << ans << "\n";

	return 0;
}