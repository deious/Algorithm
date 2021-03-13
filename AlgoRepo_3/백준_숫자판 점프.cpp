#include <iostream>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int num[6][6];
int ans;

bool check[1000000];

bool InRange(int x, int y)
{
	return x > 0 && x < 6 && y > 0 && y < 6;
}

void dfs(int x, int y, int sum, int count) 
{

	if (count == 6) 
	{
		if (!check[sum]) 
		{
			check[sum] = true;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) 
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny)) 
			dfs(nx, ny, sum * 10 + num[nx][ny], count + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			cin >> num[i][j];

	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			dfs(i, j, num[i][j], 1);

	cout << ans << "\n";

	return 0;
}