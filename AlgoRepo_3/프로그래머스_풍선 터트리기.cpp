#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
	int answer = 2;
	int len = a.size();

	if (len < 3)
		return len;

	vector<int> rMin = a;
	int lMin = a[0];
	int rLen = rMin.size();

	for (int i = rLen - 2; i > 0; i--)
		rMin[i] = min(rMin[i], rMin[i + 1]);

	for (int i = 1; i < len - 1; i++)
	{
		if (!(a[i] > lMin && rMin[i + 1] < a[i]))
			answer++;

		lMin = min(lMin, a[i]);
	}

	return answer;
}