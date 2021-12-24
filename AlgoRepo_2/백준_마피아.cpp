#include <iostream>

using namespace std;

int guiltyNum[16];
int board[16][16];
bool check[16];

int N, mafia, answer = 0;

int FindGuilty()
{
	int num = 0, maxGuilty = 0;

	for (int i = 0; i < N; i++)
	{
		if (!check[i])
		{
			if (guiltyNum[i] > maxGuilty)
			{
				num = i;
				maxGuilty = guiltyNum[i];
			}
		}
	}

	return num;
}

void DayNight(int peopleCount, int nightCount)
{
	if (peopleCount == 1 || check[mafia])
	{
		if (nightCount > answer)
			answer = nightCount;

		return;
	}

	if (peopleCount % 2 == 0)
	{
		for (int i = 0; i < N; i++)
		{
			if (!check[i])
			{
				check[i] = true;
				for (int j = 0; j < N; j++)
				{
					if (i == j)
						continue;
					guiltyNum[j] += board[i][j];
				}
				DayNight(peopleCount - 1, nightCount + 1);

				for (int j = 0; j < N; j++)
				{
					if (i == j)
						continue;
					guiltyNum[j] -= board[i][j];
				}
				check[i] = false;
			}
		}
	}
	else
	{
		int num = FindGuilty();
		check[num] = true;
		DayNight(peopleCount - 1, nightCount);
		check[num] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> guiltyNum[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cin >> mafia;

	if (N == 1)
	{
		cout << "0\n";
		return 0;
	}

	DayNight(N, 0);

	cout << answer << "\n";

	return 0;
}