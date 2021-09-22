#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int num[100001];

vector<int> solution(string s) {
	vector<int> answer;
	memset(num, 0, sizeof(num));

	string str = "";
	for (auto au : s)
	{
		if (au - '0' >= 0 && au - '0' <= 9)
			str += au;
		else
		{
			if (str.size())
			{
				num[stoi(str)]++;
				str = "";
			}
		}
	}

	vector<pair<int, int>> v;
	for (int i = 1; i < 100001; i++)
	{
		if (num[i])
			v.push_back(make_pair(num[i], i));
	}

	sort(v.begin(), v.end(), greater<pair<int, int>>());

	int len = v.size();
	for (int i = 0; i < len; i++)
		answer.push_back(v[i].second);

	return answer;
}