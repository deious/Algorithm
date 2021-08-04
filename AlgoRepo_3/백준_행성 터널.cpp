#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int parent[100001];

struct planet
{
	int x, y, z, index;
};

struct edge
{
	int from, to, cost;
};

bool CompareX(planet x, planet y)
{
	return x.x < y.x;
}

bool CompareY(planet x, planet y)
{
	return x.y < y.y;
}

bool CompareZ(planet x, planet y)
{
	return x.z < y.z;
}

bool CompareCost(edge x, edge y)
{
	return x.cost < y.cost;
}

int Find(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;
	parent[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<planet> p(N + 1);
	vector<edge> e;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		p[i].index = i;
		cin >> p[i].x >> p[i].y >> p[i].z;
	}

	sort(p.begin() + 1, p.end(), CompareX);
	for (int i = 1; i <= N - 1; i++)
		e.push_back({ p[i].index, p[i + 1].index, abs(p[i].x - p[i + 1].x) });

	sort(p.begin() + 1, p.end(), CompareY);
	for (int i = 1; i <= N - 1; i++)
		e.push_back({ p[i].index, p[i + 1].index, abs(p[i].y - p[i + 1].y) });

	sort(p.begin() + 1, p.end(), CompareZ);
	for (int i = 1; i <= N - 1; i++)
		e.push_back({ p[i].index, p[i + 1].index, abs(p[i].z - p[i + 1].z) });

	sort(e.begin(), e.end(), CompareCost);

	int ans = 0;
	int eCount = 0;
	int len = e.size();
	for (int i = 0; i < len; i++)
	{
		if (Find(e[i].from) != Find(e[i].to))
		{
			eCount++;
			ans += e[i].cost;
			Union(e[i].from, e[i].to);
		}

		if (eCount == N - 1)
			break;
	}

	cout << ans << "\n";

	return 0;
}