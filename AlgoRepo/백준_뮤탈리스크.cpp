#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int scv[61][61][61];
int hp[3];

int checkHp(int x, int y, int z)
{
	if (x < 0)
		return checkHp(0, y, z);
	if (y < 0)
		return checkHp(x, 0, z);
	if (z < 0)
		return checkHp(x, y, 0);

	
	if (x == 0 && y == 0 && z == 0)
		return 0;
	
	if (scv[x][y][z] != -1)
		return scv[x][y][z];

	scv[x][y][z] = 99999999;
	scv[x][y][z] = min(scv[x][y][z], checkHp(x - 9, y - 3, z - 1) + 1);
	scv[x][y][z] = min(scv[x][y][z], checkHp(x - 9, y - 1, z - 3) + 1);
	scv[x][y][z] = min(scv[x][y][z], checkHp(x - 3, y - 9, z - 1) + 1);
	scv[x][y][z] = min(scv[x][y][z], checkHp(x - 1, y - 9, z - 3) + 1);
	scv[x][y][z] = min(scv[x][y][z], checkHp(x - 3, y - 1, z - 9) + 1);
	scv[x][y][z] = min(scv[x][y][z], checkHp(x - 1, y - 3, z - 9) + 1);

	return scv[x][y][z];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> hp[i];

	memset(scv, -1, sizeof(scv));

	cout << checkHp(hp[0], hp[1], hp[2]) << "\n";

	return 0;
}