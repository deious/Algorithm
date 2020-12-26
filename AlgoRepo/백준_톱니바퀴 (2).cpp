#include <cstdio>
#include <deque>
#include <queue>
#include <cstring>

using namespace std;

bool check[1000];
int t;

deque<deque<int>> dq(1000, deque<int>(8));

void GearControll(int gear, int rotation)
{
	int realGear = gear - 1;
	if (check[realGear]) return;

	int tempLeft = dq[realGear][6], tempRight = dq[realGear][2];

	if (gear == 1)
	{
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

		if (tempRight != dq[gear][6])
		{
			GearControll(gear + 1, rotation * -1);
		}
	}
	else if (gear == t)
	{
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

		if (tempLeft != dq[realGear - 1][2])
		{
			GearControll(gear - 1, rotation * -1);
		}
	}
	else
	{
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

		if (tempLeft != dq[realGear - 1][2])
		{
			GearControll(gear - 1, rotation * -1);
		}

		if (tempRight != dq[gear][6])
		{
			GearControll(gear + 1, rotation * -1);
		}
	}

	return;
}

int main()
{
	int k, ans = 0;
	queue<pair<int, int>> q;
	
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &dq[i][j]);
		}
	}

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		q.push(make_pair(a, b));
	}

	while (!q.empty())
	{
		int gear = q.front().first;
		int gearRotation = q.front().second;
		q.pop();

		GearControll(gear, gearRotation);

		memset(check, false, sizeof(check));
	}

	for (int i = 0; i < t; i++)
	{
		if (dq[i][0] == 1) ans ++;
	}

	printf("%d", ans);

	return 0;
}