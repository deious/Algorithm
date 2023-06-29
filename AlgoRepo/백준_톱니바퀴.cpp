#include <cstdio>
#include <deque>
#include <cstring>

using namespace std;

bool check[4];

deque<deque<int>> dq(4, deque<int>(8));

void GearControll(int gear, int rotation)
{
	int realGear = gear - 1;
	if (check[realGear]) return;

	int tempLeft = dq[realGear][6], tempRight = dq[realGear][2];

	check[realGear] = true;

	if (rotation == 1)
	{
		int temp = dq[realGear].back();
		dq[realGear].pop_back();
		dq[realGear].push_front(temp);
	}
	else if (rotation == -1)
	{
		int temp = dq[realGear].front();
		dq[realGear].pop_front();
		dq[realGear].push_back(temp);
	}

	if (gear != 1 && tempLeft != dq[realGear - 1][2])
	{
		GearControll(gear - 1, rotation * -1);
	}

	if (gear != 4 && tempRight != dq[gear][6])
	{
		GearControll(gear + 1, rotation * -1);
	}

	return;
}

int main()
{
	int k, ans = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &dq[i][j]);
		}
	}

	scanf("%d", &k);

	while (k--)
	{
		int gear, gearRotation;
		scanf("%d %d", &gear, &gearRotation);

		GearControll(gear, gearRotation);

		memset(check, false, sizeof(check));
	}

	int n = 1;

	for (int i = 0; i < 4; i++)
	{
		if (dq[i][0] == 1) ans += n;
		n *= 2;
	}

	printf("%d", ans);

	return 0;
}