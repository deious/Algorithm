#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<string> v(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		sort(v.begin(), v.end());
		bool check = false;

		for (int i = 0; i < n - 1; i++)
		{
			string s = v[i], ts = v[i + 1];
			int len = s.size();

			if (s == ts.substr(0, len))
			{
				cout << "NO\n";
				check = true;
				break;
			}
		}

		if (!check)
			cout << "YES\n";
	}

	return 0;
}