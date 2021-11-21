#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H, answer = 4;
int ladder[31][11];

bool Move() 
{
	for (int i = 1; i <= N; i++)
	{
		int move = i;;
		for (int j = 1; j <= H; j++)
		{
			if (ladder[j][move] == 1)
				move++;
			else if (ladder[j][move - 1] == 1)
				move--;
		}
		if (move != i)
			return false;
	}
	return true;
}

void DFS(int x, int y, int addCount) 
{
	if (addCount > 3 || addCount >= answer)
		return;
	
	if (Move())
	{
		answer = addCount;
		return;
	}

	for (int i = x; i <= H; i++)
	{
		for (int j = y; j <= N; j++)
		{
			if (ladder[i][j - 1] == 0 && ladder[i][j] == 0 && ladder[i][j + 1] == 0)
			{
				ladder[i][j] = 1;
				DFS(i, j, addCount + 1);
				ladder[i][j] = 0;
			}
		}
		y = 1;
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> H;
	int a, b;
	for (int i = 0; i < M; i++) 
	{
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	DFS(1, 1, 0);
	if (answer < 4)
		cout << answer << "\n";
	else
		cout << "-1\n";
}