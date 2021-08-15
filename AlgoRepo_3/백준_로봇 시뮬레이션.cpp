#include <iostream>
#include <vector>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0 , -1 };

int A, B, N, M;

int board[101][101];

struct info
{
	int x, y, dir;
};

struct orderInfo
{
	int robotNumber, times;
	char order;
};

vector<info> robot[101];
vector<orderInfo> order[101];

bool InRange(int x, int y)
{
	return x > 0 && x <= A && y > 0 && y <= B;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B >> N >> M;
	int x, y;
	char c;

	info in;
	orderInfo ord;

	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y >> c;

		in.x = x;
		in.y = y;

		if (c == 'W')
			in.dir = 0;
		else if (c == 'N')
			in.dir = 1;
		else if (c == 'E')
			in.dir = 2;
		else
			in.dir = 3;

		robot[i].push_back(in);
		board[x][y] = i;
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> x >> c >> y;
		ord.robotNumber = x;
		ord.order = c;
		ord.times = y;

		order[i].push_back(ord);
	}

	int index = 1;
	bool check = false;
	bool breakCheck = false;

	while (M--)
	{
		int robotNum = order[index][0].robotNumber;
		char moveOrder = order[index][0].order;
		int moveTime = order[index][0].times;

		int x = robot[robotNum][0].x;
		int y = robot[robotNum][0].y;
		int dir = robot[robotNum][0].dir;

		if (moveOrder == 'L')
		{
			for (int i = 0; i < moveTime; i++)
			{
				if (!dir)
					dir = 3;
				else
					dir -= 1;
			}

			robot[robotNum][0].dir = dir;
		}
		else if (moveOrder == 'R')
		{
			dir += moveTime;
			dir %= 4;

			robot[robotNum][0].dir = dir;
		}
		else
		{
			int nx = x;
			int ny = y;
			int tempX;
			int tempY;

			for (int i = 0; i < moveTime; i++)
			{
				tempX = nx;
				tempY = ny;

				dir = robot[robotNum][0].dir;
				nx += dx[dir];
				ny += dy[dir];

				if (!InRange(nx, ny))
				{
					cout << "Robot " << robotNum << " crashes into the wall";
					check = true;
					breakCheck = true;
					break;
				}

				if (board[nx][ny])
				{
					cout << "Robot " << robotNum << " crashes into robot " << board[nx][ny];
					check = true;
					breakCheck = true;
					break;
				}

				robot[robotNum][0].x = nx;
				robot[robotNum][0].y = ny;
				
				board[tempX][tempY] = 0;
				board[nx][ny] = robotNum;
			}
		}

		if (breakCheck)
			break;

		index++;
	}

	if (!check)
		cout << "OK\n";

	return 0;
}