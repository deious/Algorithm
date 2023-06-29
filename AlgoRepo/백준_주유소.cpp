#include <iostream>

using namespace std;

int road[99999];
int cost[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
		cin >> road[i];

	for (int i = 0; i < N; i++)
		cin >> cost[i];

	long long curCost = cost[0];
	long long answer = curCost * road[0];

	for (int i = 1; i < N; i++)
	{
		if (curCost > cost[i])
			curCost = cost[i];

		answer += curCost * (long long)road[i];
	}

	cout << answer << "\n";

	return 0;
}