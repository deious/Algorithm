#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
	int answer = 45;
	int temp = 0;
	for (int num : numbers)
		temp += num;

	return answer - temp;
}