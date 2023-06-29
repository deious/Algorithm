#include <iostream>
#include <vector>

using namespace std;

bool iceCream[201][201];
bool check[201];
int N, M, a, b, ans = 0;

vector<int> pick;

void DFS(int n, int pickCount)
{
	if (pickCount == 3)
	{
		int pickLen = pick.size();
		for (int i = 0; i < pickLen; i++)
		{
			for (int j = 0; j < pickLen; j++)
			{
				if (i == j)
					continue;
				if (iceCream[pick[i]][pick[j]])
					return;
			}
		}

		ans++;
		return;
	}
	
	for (int i = n; i <= N; i++)
	{
		if (!check[i])
		{
			pick.push_back(i);
			check[i] = true;
			DFS(i + 1, pickCount + 1);
			check[i] = false;
			pick.pop_back();
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		iceCream[a][b] = true;
		iceCream[b][a] = true;
	}

	DFS(1, 0);

	cout << ans << "\n";

	return 0;
}