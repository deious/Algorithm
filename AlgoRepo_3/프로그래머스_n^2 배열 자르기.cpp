#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;

	for (long long i = left; i <= right; i++)
	{
		long long div = i / n;
		long long mod = i % n;

		answer.push_back(div < mod ? mod + 1 : div + 1);
	}

	return answer;
}