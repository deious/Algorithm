#include <iostream>
#include <cstring>

using namespace std;

int T, n, cycleCount = 0;

int student[100001];
bool check[100001];
bool cycle[100001];

void DFS(int num)
{
	check[num] = true;
	int nextNum = student[num];

	if (!check[nextNum])
		DFS(nextNum);
	else if (!cycle[nextNum])
	{
		for (int i = nextNum; i != num; i = student[i])
			cycleCount++;
		cycleCount++;
	}

	cycle[num] = true;

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> student[i];

		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
				DFS(i);
		}

		cout << n - cycleCount << "\n";
		cycleCount = 0;
		memset(check, false, sizeof(check));
		memset(cycle, false, sizeof(cycle));
	}

	return 0;
}