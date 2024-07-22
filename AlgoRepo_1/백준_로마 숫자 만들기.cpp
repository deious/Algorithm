#include <iostream>

using namespace std;

int number[] = { 1, 5, 10, 50 };
bool check[1001];
int N, ans = 0;

void DFS(int num, int cnt, int sum)
{
	if (cnt == N)
	{
		if (!check[sum])
		{
			check[sum] = true;
			ans++;
		}

		return;
	}

	for (int i = num; i < 4; i++)
	{
		DFS(i, cnt + 1, sum + number[i]);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	DFS(0, 0, 0);

	cout << ans << "\n";

	return 0;
}