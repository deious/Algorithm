#include <string>
#include <vector>
#include <queue>
#include <algorithm>

int moveCnt[1000001];

using namespace std;

int solution(int x, int y, int n) {
	queue<int> q;
	fill_n(moveCnt, 1000001, -1);
	moveCnt[x] = 0;
	q.push(x);

	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		for (auto au : { a + n, a * 2, a * 3 })
		{
			if (au > y)
			{
				continue;
			}

			if (moveCnt[au] != -1)
			{
				continue;
			}

			moveCnt[au] = moveCnt[a] + 1;
			q.push(au);
		}
	}
	return moveCnt[y];
}