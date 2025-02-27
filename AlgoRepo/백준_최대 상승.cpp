#include <iostream>
#include <algorithm>

using namespace std;

int price[200000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> price[i];
	}

	int ans = 0, start = price[0];
	for (int i = 0; i < N; i++)
	{
		if (start > price[i])
		{
			start = price[i];
		}

		ans = max(ans, price[i] - start);
	}

	cout << ans << "\n";

	return 0;
}