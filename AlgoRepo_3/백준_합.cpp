#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += i;
	}

	cout << ans << "\n";

	return 0;
}