#include <iostream>

using namespace std;

long long CCW(long long x1, long long x2, long long x3, long long y1, long long y2, long long y3)
{
	long long num = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);

	if (num > 0)
		return 1;
	else
		return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long x1, x2, y1, y2, x3, y3, x4, y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	if (CCW(x1, x2, x3, y1, y2, y3) * CCW(x1, x2, x4, y1, y2, y4) < 0 && CCW(x3, x4, x1, y3, y4, y1) * CCW(x3, x4, x2, y3, y4, y2) < 0)
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}