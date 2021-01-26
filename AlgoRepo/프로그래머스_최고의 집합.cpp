#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer(1);

	if (n > s)
	{
		answer[0] = -1;
		return answer;
	}

	int q = s / n;
	int r = s % n;
	int index = n - 1;

	vector<int> answer2(n, q);

	for (int i = r; i > 0; i--) answer2[index--]++;

	return answer2;
}