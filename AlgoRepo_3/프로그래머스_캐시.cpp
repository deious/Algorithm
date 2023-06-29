#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> v;

	int len = cities.size();
	if (!cacheSize)
		return len * 5;

	for (int i = 0; i < len; i++)
	{
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
		auto iter = find(v.begin(), v.end(), cities[i]);

		if (iter == v.end())
		{
			if (v.size() == cacheSize)
				v.erase(v.begin());

			answer += 5;
		}
		else
		{
			v.erase(iter);
			answer++;
		}

		v.push_back(cities[i]);
	}

	return answer;
}