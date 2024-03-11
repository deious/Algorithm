#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v[100001];
bool check[100001];

int E, ans;

void DFS(int num, int maxNum, int sum)
{
	check[num] = true;

	if (num == E)
	{
		ans = sum - maxNum;
		return;
	}

	for (int i = 0; i < v[num].size(); i++)
	{
		if (!check[v[num][i].first])
		{
			if (v[num][i].second > maxNum)
			{
				DFS(v[num][i].first, v[num][i].second, sum + v[num][i].second);
			}
			else
			{
				DFS(v[num][i].first, maxNum, sum + v[num][i].second);
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, S;
	cin >> N >> S >> E;

	int a, b, c;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	DFS(S, 0, 0);

	cout << ans << "\n";
}