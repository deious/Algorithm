#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, pair<string, int>> a, pair<string, pair<string, int>> b)
{
	if (a.first == b.first)
	{
		if (a.second.first == b.second.first)
			return a.second.second < b.second.second;
		return stoi(a.second.first) < stoi(b.second.first);
	}
	else
		return a.first < b.first;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	string head = "", number = "";
	bool headCheck = false, numberCheck = false;
	vector<pair<string, pair<string, int>>> v;

	int len = files.size();
	for (int i = 0; i < len; i++)
	{
		pair<string, int> p;

		for (int j = 0; j < files[i].size(); j++)
		{
			if (!headCheck)
			{
				if (files[i][j] >= '0' && files[i][j] <= '9')
				{
					headCheck = true;
					number += files[i][j];
				}
				else
					head += tolower(files[i][j]);
			}
			else if (headCheck && !numberCheck)
			{
				if (files[i][j] >= '0' && files[i][j] <= '9')
					number += files[i][j];
				else
					break;
			}
		}

		p = make_pair(number, i);
		v.push_back(make_pair(head, p));
		head = number = "";
		headCheck = false;
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (auto iter : v)
		answer.push_back(files[iter.second.second]);

	return answer;
}