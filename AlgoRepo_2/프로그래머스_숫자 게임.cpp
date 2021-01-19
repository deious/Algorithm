#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int aIndex = 0, bIndex = 0;
	int len = A.size();

	if (A[0] >= B[B.size() - 1]) return answer;

	for (int i = 0; i < len; i++)
	{
		if (A[aIndex] < B[bIndex])
		{
			aIndex++;
			bIndex++;
			answer++;
		}
		else bIndex++;
	}

	return answer;
}