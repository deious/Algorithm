#include <iostream>

using namespace std;

int loseHp[21];
int people[21];

int ans = 0;
int N;

void Calculate(int start, int happy, int hp)
{
	if (hp <= 0)
	{
		return;
	}
	
	if (start > N)
	{
		if (ans < happy)
		{
			ans = happy;
		}
		return;
	}

	Calculate(start + 1, happy, hp);
	Calculate(start + 1, happy + people[start], hp - loseHp[start]);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> loseHp[i];
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> people[i];
	}

	Calculate(0, 0, 100);

	cout << ans << "\n";

	return 0;
}