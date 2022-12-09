#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> connect[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
	vector<int> answer;
	vector<int> v(n + 1, -1);

	int len = roads.size();
	for (int i = 0; i < len; i++)
	{
		connect[roads[i][0]].push_back(roads[i][1]);
		connect[roads[i][1]].push_back(roads[i][0]);
	}

	queue<pair<int, int>> q;
	q.push({ destination, 0 });
	v[destination] = 0;

	while (!q.empty())
	{
		int curPos = q.front().first;
		int moveCnt = q.front().second;
		q.pop();

		for (int i = 0; i < connect[curPos].size(); i++)
		{
			int nextPos = connect[curPos][i];

			if (v[nextPos] == -1 || v[nextPos] > moveCnt + 1)
			{
				q.push({ nextPos, moveCnt + 1 });
				v[nextPos] = moveCnt + 1;
			}
		}
	}

	for (int i = 0; i < sources.size(); i++)
	{
		answer.push_back(v[sources[i]]);
	}

	return answer;
}