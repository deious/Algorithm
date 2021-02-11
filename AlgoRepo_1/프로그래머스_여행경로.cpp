#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

bool cmp(vector<string> a, vector<string> b) { return a[1] < b[1]; }

void dfs(string start, vector<bool> check, vector<vector<string>> tickets, vector<string> ans)
{
	ans.push_back(start);

	int len = tickets.size();
	if (!answer.empty()) return;

	if (ans.size() == len + 1)
	{
		answer = ans;
		return;
	}

	for (int i = 0; i < len; i++)
	{
		if (!check[i] && tickets[i][0] == start)
		{
			check[i] = true;
			dfs(tickets[i][1], check, tickets, ans);
			check[i] = false;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	int len = tickets.size();
	vector<string> ans;
	vector<bool> check(len, false);

	sort(tickets.begin(), tickets.end(), cmp);

	dfs("ICN", check, tickets, ans);

	return answer;
}