#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int c, d, n;
	cin >> c;

	while (c--)
	{
		cin >> d >> n;

		vector<long long> check(1000001);
		int sum = 0;

		check[sum]++;

		for (int i = 1; i <= n; i++)
		{
			int temp = 0;
			cin >> temp;

			sum = (sum + temp) % d;
			check[sum]++;
		}

		long long ans = 0;
		for (int i = 0; i < d; i++)
		{
			ans += check[i] * (check[i] - 1) * 0.5;
		}

		cout << ans << "\n";
	}

	return 0;

}