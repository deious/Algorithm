#include <iostream>
#include <string>

using namespace std;

int board[8][8];
int N;

bool InRange(int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;
	int x1, y1, x2, y2;

	cin >> s1 >> s2;
	cin >> N;

	x1 = s1[1] - '0' - 1;
	y1 = s1[0] - 'A';

	x2 = s2[1] - '0' - 1;
	y2 = s2[0] - 'A';

	int nx1, ny1, nx2, ny2;

	while (N--)
	{
		cin >> s1;

		if (s1 == "R")
		{
			nx1 = x1;
			ny1 = y1 + 1;
			nx2 = x2;
			ny2 = y2 + 1;

			if (InRange(nx1, ny1))
			{
				if (nx1 == x2 && ny1 == y2 && InRange(nx2, ny2))
				{
					x1 = nx1;
					y1 = ny1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (nx1 == x2 && ny1 == y2 && !InRange(nx2, ny2))
					continue;
				else
				{
					x1 = nx1;
					y1 = ny1;
				}
			}
		}
		else if (s1 == "L")
		{
			nx1 = x1;
			ny1 = y1 - 1;
			nx2 = x2;
			ny2 = y2 - 1;

			if (InRange(nx1, ny1))
			{
				if (nx1 == x2 && ny1 == y2 && InRange(nx2, ny2))
				{
					x1 = nx1;
					y1 = ny1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (nx1 == x2 && ny1 == y2 && !InRange(nx2, ny2))
					continue;
				else
				{
					x1 = nx1;
					y1 = ny1;
				}
			}
		}
		else if (s1 == "B")
		{
			nx1 = x1 - 1;
			ny1 = y1;
			nx2 = x2 - 1;
			ny2 = y2;

			if (InRange(nx1, ny1))
			{
				if (nx1 == x2 && ny1 == y2 && InRange(nx2, ny2))
				{
					x1 = nx1;
					y1 = ny1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (nx1 == x2 && ny1 == y2 && !InRange(nx2, ny2))
					continue;
				else
				{
					x1 = nx1;
					y1 = ny1;
				}
			}
		}
		else if (s1 == "T")
		{
			nx1 = x1 + 1;
			ny1 = y1;
			nx2 = x2 + 1;
			ny2 = y2;

			if (InRange(nx1, ny1))
			{
				if (nx1 == x2 && ny1 == y2 && InRange(nx2, ny2))
				{
					x1 = nx1;
					y1 = ny1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (nx1 == x2 && ny1 == y2 && !InRange(nx2, ny2))
					continue;
				else
				{
					x1 = nx1;
					y1 = ny1;
				}
			}
		}
		else if (s1 == "RT")
		{
			nx1 = x1 + 1;
			ny1 = y1 + 1;
			nx2 = x2 + 1;
			ny2 = y2 + 1;

			if (InRange(nx1, ny1))
			{
				if (nx1 == x2 && ny1 == y2 && InRange(nx2, ny2))
				{
					x1 = nx1;
					y1 = ny1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (nx1 == x2 && ny1 == y2 && !InRange(nx2, ny2))
					continue;
				else
				{
					x1 = nx1;
					y1 = ny1;
				}
			}
		}
		else if (s1 == "LT")
		{
			nx1 = x1 + 1;
			ny1 = y1 - 1;
			nx2 = x2 + 1;
			ny2 = y2 - 1;

			if (InRange(nx1, ny1))
			{
				if (nx1 == x2 && ny1 == y2 && InRange(nx2, ny2))
				{
					x1 = nx1;
					y1 = ny1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (nx1 == x2 && ny1 == y2 && !InRange(nx2, ny2))
					continue;
				else
				{
					x1 = nx1;
					y1 = ny1;
				}
			}
		}
		else if (s1 == "RB")
		{
			nx1 = x1 - 1;
			ny1 = y1 + 1;
			nx2 = x2 - 1;
			ny2 = y2 + 1;

			if (InRange(nx1, ny1))
			{
				if (nx1 == x2 && ny1 == y2 && InRange(nx2, ny2))
				{
					x1 = nx1;
					y1 = ny1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (nx1 == x2 && ny1 == y2 && !InRange(nx2, ny2))
					continue;
				else
				{
					x1 = nx1;
					y1 = ny1;
				}
			}
		}
		else
		{
			nx1 = x1 - 1;
			ny1 = y1 - 1;
			nx2 = x2 - 1;
			ny2 = y2 - 1;

			if (InRange(nx1, ny1))
			{
				if (nx1 == x2 && ny1 == y2 && InRange(nx2, ny2))
				{
					x1 = nx1;
					y1 = ny1;
					x2 = nx2;
					y2 = ny2;
				}
				else if (nx1 == x2 && ny1 == y2 && !InRange(nx2, ny2))
					continue;
				else
				{
					x1 = nx1;
					y1 = ny1;
				}
			}
		}
	}

	char ans1, ans2;
	ans1 = y1 + 'A';
	ans2 = y2 + 'A';

	cout << ans1 << x1 + 1 << "\n";
	cout << ans2 << x2 + 1 << "\n";

	return 0;
}