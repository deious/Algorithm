#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int save[502];

bool cmp(pair<double, int> &a, pair<double, int> &b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<double, int>> v;
	int len = stages.size();
	int player = len;
	sort(stages.begin(), stages.end());

	for (int i = 0; i < len; i++)
		save[stages[i]]++;

	for (int i = 1; i <= N; i++)
	{
		if (player == 0 || save[i] == 0)
			v.push_back({ 0, i });
		else
			v.push_back({ (double)save[i] / (double)player, i });
		player -= save[i];
	}

	sort(v.begin(), v.end(), cmp);
	for (auto au : v)
		answer.push_back(au.second);

	return answer;
}