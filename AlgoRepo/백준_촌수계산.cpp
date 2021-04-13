#include <iostream>
#include <vector>

using namespace std;

int ans = -1;
vector<int> v[101];
bool check[101];

void dfs(int x, int y, int count)
{
	if (x == y)
		ans = count;
	check[x] = true;
	int len = v[x].size();

	for (int i = 0; i < len; i++)
	{
		if (!check[v[x][i]])
			dfs(v[x][i], y, count + 1);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, c, d, e;
	cin >> n >> a >> b >> c;
	

	for (int i = 0; i < c; i++)
	{
		cin >> d >> e;
		v[d].push_back(e);
		v[e].push_back(d);
	}

	dfs(a, b, 0);
	cout << ans << "\n";

	return 0;
}