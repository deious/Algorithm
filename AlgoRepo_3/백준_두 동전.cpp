#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char board[22][22];
bool moveCheck[22][22][22][22];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool countCheck = false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, count;
	cin >> N >> M;

	queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'o')
				q.push(make_pair(i, j));
		}

	int x1 = q.front().first;
	int y1 = q.front().second;
	q.pop();
	int x2 = q.front().first;
	int y2 = q.front().second;
	q.pop();

	queue<tuple<int, int ,int, int, int>> pq;

	pq.push(make_tuple(x1, y1, x2, y2, 0));

	while (!pq.empty())
	{
		x1 = get<0>(pq.front());
		y1 = get<1>(pq.front());
		x2 = get<2>(pq.front());
		y2 = get<3>(pq.front());
		count = get<4>(pq.front());
		pq.pop();
		bool check1 = false;
		bool check2 = false;

		if (count == 11)
			break;

		if (x1 == 0 || x1 == N + 1 || y1 == 0 || y1 == M + 1)
			check1 = true;
		if (x2 == 0 || x2 == N + 1 || y2 == 0 || y2 == M + 1)
			check2 = true;

		if (check1 ^ check2)
		{
			cout << count << "\n";
			countCheck = true;
			break;
		}
		else if (check1 || check2)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int nx1 = x1 + dx[i];
			int ny1 = y1 + dy[i];
			int nx2 = x2 + dx[i];
			int ny2 = y2 + dy[i];

			if (!moveCheck[nx1][ny1][nx2][ny2] && board[nx1][ny1] != '#' && board[nx2][ny2] != '#')
			{
				moveCheck[nx1][ny1][nx2][ny2] = true;
				pq.push(make_tuple(nx1, ny1, nx2, ny2, count + 1));
			}
			else if (!moveCheck[nx1][ny1][nx2][ny2] && board[nx1][ny1] == '#' && board[nx2][ny2] != '#')
			{
				moveCheck[x1][y1][nx2][ny2] = true;
				pq.push(make_tuple(x1, y1, nx2, ny2, count + 1));
			}
			else if (!moveCheck[nx1][ny1][nx2][ny2] && board[nx1][ny1] != '#' && board[nx2][ny2] == '#')
			{
				moveCheck[nx1][ny1][x2][y2] = true;
				pq.push(make_tuple(nx1, ny1, x2, y2, count + 1));
			}
		}
	}

	if (!countCheck)
		cout << "-1" << "\n";

	return 0;
}