#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	for (long long num : numbers)
	{
		long long bit = 1;
		while ((num & bit) > 0)
			bit <<= 1;
		answer.push_back(num + bit - (bit >> 1));
	}

	return answer;
}