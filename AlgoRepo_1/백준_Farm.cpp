#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, n, w, x, y;

	cin >> a >> b >> n >> w;

	int ansCnt = 0;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			if (a * i + b * j == w && i + j == n)
			{
				x = i;
				y = j;
				ansCnt++;
			}
		}
	}

	(ansCnt > 1  || ansCnt == 0)? cout << -1 : cout << x << " " << y << "\n";

	return 0;
}