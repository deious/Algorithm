#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int population[11];
int check[11];
bool tempCheck[11];

vector<int> v[11];

int DFS(int x, int team)
{
	if (check[x] != 0 && check[x] != team)
	{
		return 0;
	}

	check[x] = team;
	int sum = 0;
	sum += population[x];
	tempCheck[x] = true;

	int len = v[x].size();
	for (int i = 0; i < len; i++)
	{
		if (check[v[x][i]] == team)
		{
			if (x == v[x][i])
			{
				continue;
			}

			if (!tempCheck[v[x][i]])
			{
				sum += DFS(v[x][i], team);
			}
		}
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, temp, num, minNum = 2100000000;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> population[i];
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp; j++)
		{
			cin >> num;
			v[i].push_back(num);
		}
	}

	int dfsCnt = 0;
	bool endCheck = false;
	int minNum1, minNum2, index;
	for (int i = 1; i < N; i++)
	{
		vector<int> v1(N);
		for (int j = 0; j < i; j++)
		{
			v1[j] = 1;
		}

		do
		{
			memset(check, 0, sizeof(check));
			memset(tempCheck, false, sizeof(tempCheck));
			dfsCnt = 0;
			endCheck = false;
			minNum1 = 0, minNum2 = 0;

			for (int j = 0; j < N; j++)
			{
				if (v1[j] == 1)
				{
					check[j + 1] = 1;
					index = j + 1;
				}
			}

			minNum1 = DFS(index, 1);

			for (int j = 0; j < N; j++)
			{
				if (v1[j] == 1 && !tempCheck[j + 1])
				{
					endCheck = true;
					break;
				}
			}

			if (endCheck)
			{
				continue;
			}

			dfsCnt++;

			for (int j = 1; j <= N; j++)
			{
				if (!tempCheck[j])
				{
					dfsCnt++;
					if (dfsCnt > 2)
					{
						endCheck = true;
						break;
					}
					minNum2 = DFS(j, 0);
				}
			}

			if (!endCheck)
			{
				minNum1 = abs(minNum1 - minNum2);
				minNum = min(minNum, minNum1);
			}
		} while (prev_permutation(v1.begin(), v1.end()));
	}

	if (minNum == 2100000000)
	{
		cout << "-1\n";
		return 0;
	}

	cout << minNum << "\n";

	return 0;
}