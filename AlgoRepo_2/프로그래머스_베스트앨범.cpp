#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool secondCheck(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

bool secondCheck2(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
	return a.second.first > b.second.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m;
	vector<pair<string, int>> v;
	vector<pair<string, pair<int, int>>> v2;

	int len = genres.size();
	for (int i = 0; i < len; i++)
	{
		m[genres[i]] += plays[i];
		v2.push_back(make_pair(genres[i], make_pair(plays[i], i)));
	}

	sort(v2.begin(), v2.end(), secondCheck2);

	for (auto num : m) v.push_back(make_pair(num.first, num.second));

	sort(v.begin(), v.end(), secondCheck);

	len = v.size();
	int tempLen = plays.size();

	for (int i = 0; i < len; i++)
	{
		int maxCount = 0;

		for (int j = 0; j < tempLen; j++)
		{
			if (v[i].first == v2[j].first)
			{
				answer.push_back(v2[j].second.second);
				maxCount++;
				if (maxCount == 2) break;
			}
		}
	}
	return answer;
}