#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, x, y;
	cin >> A >> B;

	x = -1 * A - sqrt(A * A - B);
	y = -1 * A + sqrt(A * A - B);

	x == y ? cout << x : cout << x << " " << y << "\n";

	return 0;
}