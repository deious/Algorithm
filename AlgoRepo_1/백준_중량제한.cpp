#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

bool check[100001];

vector<pair<int, int>> v[100001];

int N, M, startPoint, endPoint;

bool BFS(int w)
{
	queue<int> q;
	q.push(startPoint);
	check[startPoint] = true;

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		if (pos == endPoint)
			return true;

		for (int i = 0; i < v[pos].size(); i++)
		{
			int nextPos = v[pos][i].first;
			int nextWeight = v[pos][i].second;

			if (!check[nextPos] && nextWeight >= w)
			{
				q.push(nextPos);
				check[nextPos] = true;
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int a, b, c, maxNum = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		maxNum = max(maxNum, c);
	}

	cin >> startPoint >> endPoint;

	int left = 0, mid = 0, right = maxNum;
	while (left <= right)
	{
		memset(check, false, sizeof(check));

		mid = (left + right) / 2;

		if (BFS(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}

	cout << right << "\n";

	return 0;
}