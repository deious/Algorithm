#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

set<int> s[101];

int CalculateLength(int start, vector<vector<int>> &wires)
{
	int len = 0;
	queue<int> q;
	q.push(start);

	bool check[101] = { false, };
	check[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		len++;

		for (auto au : s[x])
		{
			if (check[au])
				continue;

			q.push(au);
			check[au] = true;
		}
	}

	return len;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = 2100000000;
	int len = wires.size();
	for (int i = 0; i < len; i++)
	{
		s[wires[i][0]].insert(wires[i][1]);
		s[wires[i][1]].insert(wires[i][0]);
	}

	for (int i = 0; i < len; i++)
	{
		s[wires[i][0]].erase(wires[i][1]);
		s[wires[i][1]].erase(wires[i][0]);

		answer = min(answer, abs(CalculateLength(wires[i][0], wires) - CalculateLength(wires[i][1], wires)));

		s[wires[i][0]].insert(wires[i][1]);
		s[wires[i][1]].insert(wires[i][0]);
	}

	return answer;
}