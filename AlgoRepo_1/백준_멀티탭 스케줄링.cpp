#include <iostream>
#include <algorithm>

using namespace std;

int multiTab[101];
int useCount[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < K; i++)
		cin >> useCount[i];

	bool check = false;
	int answer = 0;

	for (int i = 0; i < K; i++)
	{
		int use = useCount[i];
		check = false;

		for (int j = 0; j < N; j++)
		{
			if (multiTab[j] == use)
			{
				check = true;
				break;
			}
		}

		if (check)
			continue;

		for (int j = 0; j < N; j++)
		{
			if (multiTab[j] == 0)
			{
				multiTab[j] = use;
				check = true;
				break;
			}
		}

		if (check)
			continue;

		int index = -1, tempIndex = -1;

		for (int j = 0; j < N; j++)
		{
			int last = 0;
			for (int k = i + 1; k < K; k++)
			{
				if (multiTab[j] == useCount[k])
					break;
				last++;
			}

			if (last > tempIndex)
			{
				index = j;
				tempIndex = last;
			}
		}

		answer++;
		multiTab[index] = use;
	}

	cout << answer << "\n";

	return 0;
}