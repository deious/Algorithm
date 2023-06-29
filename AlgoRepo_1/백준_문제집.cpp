#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[32001];
int information[100001];

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
		information[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= N; i++)
	{
		if (!information[i])
			pq.push(i);
	}

	while (!pq.empty())
	{
		int idx = pq.top();
		pq.pop();
		cout << idx << " ";
		int len = v[idx].size();

		for (int i = 0; i < len; i++)
		{
			if (!--information[v[idx][i]])
				pq.push(v[idx][i]);
		}
	}

	return 0;
}