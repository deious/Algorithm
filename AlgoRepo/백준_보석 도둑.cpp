#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long k;
	cin >> k;

	vector<long long> v;

	int mod = 2;
	while (k != 1)
	{
		if (mod > 1000000)
		{
			v.push_back(k);
			break;
		}

		if (k % mod == 0)
		{
			k /= mod;
			v.push_back(mod);
		}
		else
		{
			mod++;
		}
	}

	cout << v.size() << "\n";

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	
	return 0;
}