#include <iostream>
#include <deque>

using namespace std;

deque<bool> conveyor;
deque<int> durability;

int N, K;

void Rotate()
{
	conveyor.push_front(conveyor.back());
	conveyor.pop_back();
	conveyor[N - 1] = false;

	durability.push_front(durability.back());
	durability.pop_back();
}

void MoveRobot()
{
	int start = N - 2;
	for (int i = start; i >= 0; i--)
	{
		if (conveyor[i] && !conveyor[i + 1] && durability[i + 1])
		{
			conveyor[i] = false;
			conveyor[i + 1] = true;
			durability[i + 1]--;
		}
	}
	conveyor[N - 1] = false;
}

void PutRobot()
{
	if (!conveyor[0] && durability[0])
	{
		conveyor[0] = true;
		durability[0]--;
	}
}

int DurabilityCheck()
{
	int count = 0;
	int len = N * 2;
	for (int i = 0; i < len; i++)
	{
		if (!durability[i])
			count++;
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	int len = N * 2;

	int num;
	for (int i = 0; i < len; i++)
	{
		cin >> num;
		durability.push_back(num);
		conveyor.push_back(false);
	}

	int ans = 0;

	while (1)
	{
		ans++;

		Rotate();
		MoveRobot();
		PutRobot();

		if (DurabilityCheck() >= K)
			break;
	}

	cout << ans << "\n";

	return 0;
}