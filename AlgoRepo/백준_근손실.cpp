#include <iostream>

using namespace std;

int kit[50];
bool check[50];

int N, K, answer = 0;

void DFS(int kitNum, int sum)
{
	int tSum = sum - K + kit[kitNum];
	if (tSum < 500)
		return;

	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		if (!check[i])
		{
			flag = true;
			check[i] = true;
			DFS(i, tSum);
			check[i] = false;
		}
	}

	if (!flag)
		answer++;

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> kit[i];

	for (int i = 0; i < N; i++)
	{
		check[i] = true;
		DFS(i, 500);
		check[i] = false;
	}

	cout << answer << "\n";
	
	return 0;
}