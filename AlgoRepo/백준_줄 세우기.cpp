#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[32001];
int value[32001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, a, b;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		value[b]++;
	}

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (!value[i])
			q.push(i);
	}

	while (!q.empty())
	{
		int idx = q.front();
		q.pop();
		cout << idx << " ";
		int len = v[idx].size();

		for (int i = 0; i < len; i++)
		{
			value[v[idx][i]]--;
			if (!value[v[idx][i]])
				q.push(v[idx][i]);
		}
	}

	return 0;
}