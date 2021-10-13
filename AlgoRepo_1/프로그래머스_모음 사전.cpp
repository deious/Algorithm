#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
	int answer = 0;
	map<char, int> m = { { 'A', 0 },{ 'E', 1 },{ 'I', 2 },{ 'O', 3 },{ 'U', 4 } };
	int num[5] = { 781, 156, 31, 6, 1 };

	int len = word.size();
	for (int i = 0; i < len; i++)
		answer += (m[word[i]] * num[i] + 1);

	return answer;
}