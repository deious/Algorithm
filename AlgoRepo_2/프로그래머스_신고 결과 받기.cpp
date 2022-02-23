#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, int> reportCount;
map<string, set<string>> reportLog;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;

	for (string s : report)
	{
		int space = s.find(' ');
		string from = s.substr(0, space);
		string to = s.substr(space + 1);

		if (reportLog[from].find(to) == reportLog[from].end())
		{
			reportCount[to]++;
			reportLog[from].insert(to);
		}
	}

	for (string s : id_list)
	{
		int rCount = 0;

		for (string str : reportLog[s])
			if (reportCount[str] >= k)
				rCount++;

		answer.push_back(rCount);
	}

	return answer;
}