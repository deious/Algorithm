#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[10001];
bool check[10001];

int n, r, totalLen = 0;

void DFS(int pos, int len)
{
	check[pos] = true;

	if (len > totalLen)
	{
		totalLen = len;
		r = pos;
	}

	for (int i = 0; i < tree[pos].size(); i++)
	{
		int nextPos = tree[pos][i].first;
		int nextLen = tree[pos][i].second;

		if (!check[nextPos])
			DFS(nextPos, len + nextLen);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}

	DFS(a, 0);
	memset(check, false, sizeof(check));
	totalLen = 0;
	DFS(r, 0);

	cout << totalLen << "\n";

	return 0;
}