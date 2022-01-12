#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct room
{
	char type;
	int cost;
};

room Room[1001];
vector<int> v[1001];
bool check[1001];

int n;
bool flag = false;

void DFS(int roomNum, int cost)
{
	char c = Room[roomNum].type;
	int cCost = Room[roomNum].cost;

	if (c == 'L')
	{
		if (cCost > cost)
			cost = cCost;
	}
	else if (c == 'T')
	{
		cost -= cCost;
		if (cost < 0)
		{
			check[roomNum] = false;
			return;
		}
	}

	if (n == roomNum)
	{
		flag = true;
		return;
	}

	check[roomNum] = true;

	for (int i = 0; i < v[roomNum].size(); i++)
	{
		if (!check[v[roomNum][i]])
		{
			check[v[roomNum][i]] = true;
			DFS(v[roomNum][i], cost);
			check[v[roomNum][i]] = false;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		cin >> n;
		if (!n)
			break;

		memset(check, false, sizeof(check));
		flag = false;
		for (int i = 1; i <= 1000; i++)
			v[i].clear();

		char c;
		int cost, num;
		for (int i = 1; i <= n; i++)
		{
			cin >> c >> cost;
			Room[i] = { c, cost };

			while (true)
			{
				cin >> num;
				if (!num)
					break;

				v[i].push_back(num);
			}
		}

		DFS(1, 0);

		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}