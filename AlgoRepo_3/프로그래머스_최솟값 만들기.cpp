#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int len = A.size();
	int index = len - 1;
	for (int i = 0; i < len; i++)
		answer += (A[i] * B[index--]);

	return answer;
}