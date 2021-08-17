#include <iostream>
#include <vector>

using namespace std;

int parent[51];
int N, M;

vector<int> v;

int Find(int x)
{
	if (parent[x] == x)
		return x;

	return x = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	parent[x] = y;
}

bool UnionCheck(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int A;
	cin >> N >> M >> A;

	int ans = M;
	if (A == 0)
	{
		cout << ans << "\n";
		return 0;
	}

	int num;
	for (int i = 0; i < A; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	int total, people, prev;
	
	vector<int> v1[51];
	for (int i = 1; i <= M; i++)
	{
		cin >> total;
		for (int j = 0; j < total; j++)
		{
			if (j > 0)
			{
				prev = people;
				cin >> people;
				Union(prev, people);
			}
			else
				cin >> people;

			v1[i].push_back(people);
		}
	}

	for (int i = 1; i <= M; i++)
	{
		bool check = false;
		for (int j = 0; j < v1[i].size(); j++)
		{
			int x = v1[i][j];
			for (int k = 0; k < v.size(); k++)
			{
				int y = v[k];
				if (UnionCheck(x, y))
				{
					ans--;
					check = true;
					break;
				}
			}
			if (check)
				break;
		}
	}

	cout << ans << "\n";

	return 0;
}