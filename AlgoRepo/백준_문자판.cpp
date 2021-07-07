#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dp[100][100][80];
string board[100];
string s;

int N, M, K;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int calculate(int x, int y, int index)
{
	int &res = dp[x][y][index];

	if (res != -1)
		return res;

	if (index == s.size())
		return 1;

	res = 0;

	for (int i = 0; i < 4; i++)
	{
		int tx = x;
		int ty = y;

		for (int j = 1; j <= K; j++)
		{
			int nx = tx + dx[i] * j;
			int ny = ty + dy[i] * j;

			if (InRange(nx, ny) && board[nx][ny] == s[index])
				res += calculate(nx, ny, index + 1);
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	cin >> s;

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == s[0])
				v.push_back(make_pair(i, j));
		}
	}

	memset(dp, -1, sizeof(dp));

	int len = v.size();
	int x, y, ans = 0;

	for (int i = 0; i < len; i++)
	{
		x = v[i].first;
		y = v[i].second;

		ans += calculate(x, y, 1);
	}

	cout << ans << "\n";

	return 0;
}