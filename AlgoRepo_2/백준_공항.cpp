#include <iostream>
#include <vector>

using namespace std;

int G, P;
int parent[100001];

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

	cin >> G >> P;
	for (int i = 1; i <= G; i++)
		parent[i] = i;

	int ans = 0;
	int airplane = 0;

	for (int i = 0; i < P; i++)
	{
		cin >> airplane;
		if (!Find(airplane))
			break;
		else
		{
			ans++;
			Union(Find(airplane), Find(airplane) - 1);
		}
	}

	cout << ans << "\n";

	return 0;
}