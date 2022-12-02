#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	int len = tangerine.size();

	map<int, int> m;
	vector<pair<int, int>> v;
	for (int i = 0; i < len; i++)
	{
		m[tangerine[i]]++;
	}

	for (auto au : m)
	{
		v.push_back(au);
	}

	sort(v.begin(), v.end(), cmp);

	int temp = 0;
	for (auto au : v)
	{
		if (temp >= k)
		{
			break;
		}
		else
		{
			temp += au.second;
			answer++;
		}
	}
	return answer;
}