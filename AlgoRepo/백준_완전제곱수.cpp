#include <iostream>

using namespace std;

bool check[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	for (int i = 1; i * i <= N; i++)
	{
		check[i * i] = true;
	}

	int ans = 0, min = 0;
	bool minCheck = false;
	for (int i = M; i <= N; i++)
	{
		if (!minCheck && check[i])
		{
			minCheck = true;
			min = i;
		}

		if (check[i])
		{
			ans += i;
		}
	}

	if (!minCheck)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans << "\n" << min << "\n";
	}

	return 0;
}