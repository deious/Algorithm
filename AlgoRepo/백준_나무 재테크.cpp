#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;

int tree[11][11];
int defaultEnergy[11][11];
int addEnergy[11][11];

vector<int> v[11][11];

bool InRange(int x, int y)
{
	return x > 0 && x <= N && y > 0 && y <= N;
}

void SpringSummer()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!v[i][j].size())
				continue;

			int deadTreeEnergy = 0;
			vector<int> v1;

			sort(v[i][j].begin(), v[i][j].end());
			int len = v[i][j].size();

			for (int k = 0; k < len; k++)
			{
				int age = v[i][j][k];

				if (defaultEnergy[i][j] >= age)
				{
					defaultEnergy[i][j] -= age;
					v1.push_back(age + 1);
				}
				else
					deadTreeEnergy += (age / 2);
			}

			v[i][j].clear();
			len = v1.size();
			for (int k = 0; k < len; k++)
				v[i][j].push_back(v1[k]);

			defaultEnergy[i][j] += deadTreeEnergy;
		}
	}
}

void Fall()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!v[i][j].size())
				continue;

			int len = v[i][j].size();
			for (int k = 0; k < len; k++)
			{
				int age = v[i][j][k];

				if (age % 5 == 0)
				{
					for (int l = 0; l < 8; l++)
					{
						int nx = i + dx[l];
						int ny = j + dy[l];

						if (InRange(nx, ny))
							v[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void Winter()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			defaultEnergy[i][j] += addEnergy[i][j];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> addEnergy[i][j];
			defaultEnergy[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> z;
		v[x][y].push_back(z);
	}

	for (int i = 0; i < K; i++)
	{
		SpringSummer();
		Fall();
		Winter();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ans += v[i][j].size();

	cout << ans << "\n";

	return 0;
}