#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
	int len = leave.size();
	vector<int> answer(len);

	int enterIndex = 0, leaveIndex = 0;

	set<int> room;
	map<pair<int, int>, bool> check;

	while (leaveIndex < len)
	{
		while (room.find(leave[leaveIndex]) == room.end())
		{
			int num = enter[enterIndex++];
			room.insert(num);

			for (auto au : room)
			{
				check[{au, num}] = true;
				check[{num, au}] = true;
			}
		}

		while (room.find(leave[leaveIndex]) != room.end())
			room.erase(leave[leaveIndex++]);
	}

	for (int i = 0; i < len; i++)
	{
		int cnt = 0;
		for (int j = 0; j < len; j++)
		{
			if (i == j)
				continue;

			if (check.count({ enter[i], enter[j] }))
				cnt++;
		}

		answer[enter[i] - 1] = cnt;
	}

	return answer;
}