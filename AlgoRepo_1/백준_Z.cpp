#include <iostream>

using namespace std;

int N, r, c, num = 0;

void DFS(int x, int y, int size)
{
	if (x == r && y == c)
	{
		cout << num << "\n";
		return;
	}

	if (x <= r && x + size > r && y <= c && y + size > c)
	{
		DFS(x, y, size / 2);
		DFS(x, y + size / 2, size / 2);
		DFS(x + size / 2, y, size / 2);
		DFS(x + size / 2, y + size / 2, size / 2);
	}
	else
		num += size * size;

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> r >> c;
	DFS(0, 0, 1 << N);

	return 0;
}