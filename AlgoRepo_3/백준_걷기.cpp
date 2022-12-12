#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long X, Y, W, S, smallXY, largeXY;
	cin >> X >> Y >> W >> S;

	if (W * 2 < S)
	{
		cout << (X + Y) * W;
		return 0;
	}

	if (X > Y)
	{
		smallXY = Y;
		largeXY = X;
	}
	else
	{
		smallXY = X;
		largeXY = Y;
	}

	long long absNum = abs(X - Y);
	long long answer = 0;
	if (absNum % 2 == 0)
	{
		if (W > S)
		{
			answer = largeXY * S;
		}
		else
		{
			answer = smallXY * S + absNum * W;
		}
	}
	else
	{
		if (W > S)
		{
			answer = smallXY * S + (absNum - 1) * S + W;
		}
		else
		{
			answer = smallXY * S + absNum * W;
		}
	}

	cout << answer << "\n";

	return 0;
}