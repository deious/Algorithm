#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n;
int map[21][21];
bool visit[21][21];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

struct fish
{
	int x;
	int y;
	int dist;
};

struct compare
{
	bool operator()(fish a, fish b)
	{
		if (a.dist == b.dist)
		{
			if (a.y == b.y)
			{
				return a.x > b.x;
			}
			return a.y > b.y;
		}
		return a.dist > b.dist;
	}
};

queue<fish> q;

void bfs()
{
	int size = 2;
	int eat = 0;
	int time = 0;

	while (true)
	{
		priority_queue<fish, vector<fish>, compare> pq;

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (map[ny][nx] > size || visit[ny][nx])
					continue;
				q.push({ nx, ny, cur.dist + 1 });
				visit[ny][nx] = true;
				
				if (map[ny][nx] < size && map[ny][nx] != 0)
					pq.push({ nx, ny, cur.dist + 1 });
			}
		}
		
		memset(visit, false, sizeof(visit));
		
		if (!pq.empty())
		{
			auto cur = pq.top();
			pq.pop();
			map[cur.y][cur.x] = 0;
			eat++;
			time = cur.dist;
			q.push({ cur.x, cur.y, cur.dist });
			visit[cur.y][cur.x] = true;
		}
		else
		{
			cout << time << '\n';
			break;
		}
		
		if (eat == size)
		{
			size++;
			eat = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				q.push({ j, i, 0 });
				map[i][j] = 0;
				visit[i][j] = true;
			}
		}
	}

	bfs();

	return 0;
}