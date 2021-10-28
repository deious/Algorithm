#include <string>
#include <vector>

using namespace std;

bool pillar[101][101];
bool cBeam[101][101];

int N = 0;

bool CheckPillar(int x, int y)
{
	if (!y)
		return true;
	else if (pillar[x][y - 1])
		return true;
	else if (x > 0 && cBeam[x - 1][y])
		return true;
	else if (x < N && cBeam[x][y])
		return true;
	else
		return false;
}

bool CheckCBeam(int x, int y)
{
	if (pillar[x][y - 1])
		return true;
	else if (x < N && pillar[x + 1][y - 1])
		return true;
	else if (x > 0 && x < N && cBeam[x + 1][y] && cBeam[x - 1][y])
		return true;
	else
		return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	N = n;

	int len = build_frame.size();
	for (int i = 0; i < len; i++)
	{
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int a = build_frame[i][2];
		int b = build_frame[i][3];

		if (b == 1)
		{
			if (a == 0)
			{
				if (CheckPillar(x, y))
					pillar[x][y] = 1;
			}
			else
			{
				if (CheckCBeam(x, y))
					cBeam[x][y] = 1;
			}
		}
		else
		{
			if (a == 0)
			{
				pillar[x][y] = 0;
				if (y < n && pillar[x][y + 1] && !CheckPillar(x, y + 1))
					pillar[x][y] = 1;
				else if (y < n && cBeam[x][y + 1] && !CheckCBeam(x, y + 1))
					pillar[x][y] = 1;
				else if (x > 0 && cBeam[x - 1][y + 1] && y < n && !CheckCBeam(x - 1, y + 1))
					pillar[x][y] = 1;
			}
			else
			{
				cBeam[x][y] = 0;
				if (pillar[x][y] && !CheckPillar(x, y))
					cBeam[x][y] = 1;
				else if (x < n && pillar[x + 1][y] && !CheckPillar(x + 1, y))
					cBeam[x][y] = 1;
				else if (x > 0 && cBeam[x - 1][y] && !CheckCBeam(x - 1, y))
					cBeam[x][y] = 1;
				else if (x < n && cBeam[x + 1][y] && !CheckCBeam(x + 1, y))
					cBeam[x][y] = 1;
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (pillar[i][j])
				answer.push_back({ i, j, 0 });
			if (cBeam[i][j])
				answer.push_back({ i, j, 1 });
		}
	}

	return answer;
}