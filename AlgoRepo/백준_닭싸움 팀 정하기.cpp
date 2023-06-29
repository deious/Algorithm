#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool team[1001];

vector<int> rFriend[1001], rEnemy[1001];

void DFS(int index)
{
	team[index] = true;
	for (int i = 0; i < rFriend[index].size(); i++)
	{
		int next = rFriend[index][i];
		if (!team[next])
			DFS(next);
	}

	for (int i = 0; i < rEnemy[index].size(); i++)
	{
		int next = rEnemy[index][i];
		for (int j = 0; j < rEnemy[next].size(); j++)
		{
			int nNext = rEnemy[next][j];
			if (!team[nNext])
				DFS(nNext);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int p, q;
	char c;

	for (int i = 0; i < M; i++)
	{
		cin >> c >> p >> q;
		if (c == 'F')
		{
			rFriend[p].push_back(q);
			rFriend[q].push_back(p);
		}
		else
		{
			rEnemy[p].push_back(q);
			rEnemy[q].push_back(p);
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!team[i])
		{
			DFS(i);
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}