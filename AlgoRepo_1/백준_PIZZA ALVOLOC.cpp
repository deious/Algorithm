#include <iostream>

using namespace std;

int CCW(int x1, int x2, int x3, int y1, int y2, int y3)
{
	int num = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);

	if (num > 0)
		return 1;
	else if (num == 0)
		return 0;
	else
		return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x1, x2, x3, x4, y1, y2, y3, y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	if (CCW(x1, x2, x3, y1, y2, y3) * CCW(x1, x2, x4, y1, y2, y4) < 0)
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}