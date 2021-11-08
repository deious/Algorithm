#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;
	vector<int> v;

	int len = dungeons.size();
	for (int i = 0; i < len; i++)
		v.push_back(i);

	do
	{
		int moveCount = 0;
		int fatigue = k;

		for (int i = 0; i < len; i++)
		{
			int minFatigue = dungeons[v[i]][0];
			int useFatigue = dungeons[v[i]][1];

			if (fatigue >= minFatigue)
			{
				fatigue -= useFatigue;
				moveCount++;
			}
			else
				break;
		}

		answer = max(answer, moveCount);
	} while (next_permutation(v.begin(), v.end()));

	return answer;
}