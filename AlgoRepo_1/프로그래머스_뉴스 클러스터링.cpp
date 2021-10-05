#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	int sLen = str1.size(), s2Len = str2.size();

	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	vector<string> v1, v2;
	for (int i = 0; i < sLen - 1; i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i + 1] <= 'z')
			v1.push_back(str1.substr(i, 2));
	}

	for (int i = 0; i < s2Len - 1; i++)
	{
		if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z')
			v2.push_back(str2.substr(i, 2));
	}

	double unionCount = v1.size() + v2.size();
	int vLen = v1.size();
	double intersection = 0;

	for (int i = 0; i < vLen; i++)
	{
		auto iter = find(v2.begin(), v2.end(), v1[i]);
		if (iter != v2.end())
		{
			intersection++;
			v2.erase(iter);
		}
	}

	unionCount -= intersection;
	if (unionCount == intersection && !unionCount && !intersection)
		return 65536;

	answer = (int)((intersection / unionCount) * 65536);
	return answer;
}