#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(std::vector<int> a) {
	int answer = 0;
	unordered_map<int, int> m;

	int len = a.size();
	for (int i = 0; i < len; i++)
		m[a[i]]++;

	for (auto iter : m)
	{
		if (iter.second * 2 <= answer)
			continue;

		int temp = 0;
		for (int j = 0; j < len - 1; j++)
		{
			if (a[j] == a[j + 1])
				continue;
			if (a[j] != iter.first && a[j + 1] != iter.first)
				continue;

			temp += 2;
			j++;
		}
		answer = max(answer, temp);
	}

	return answer;
}