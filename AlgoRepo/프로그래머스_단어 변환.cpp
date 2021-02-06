#include <string>
#include <vector>

using namespace std;

int wordsLen, wordSize, answer = 51;

void checkWord(string begin, string target, vector<string> words, int count, vector<bool> check)
{
	for (int i = 0; i < wordsLen; i++)
	{
		if (check[i]) continue;
		int wordCheck = 0;

		for (int j = 0; j < wordSize; j++)
		{
			if (begin[j] != words[i][j]) wordCheck++;
		}

		if (wordCheck == 1)
		{
			if (words[i] == target && answer > count + 1)
			{
				answer = count + 1;
				return;
			}

			check[i] = true;
			checkWord(words[i], target, words, count + 1, check);
			check[i] = false;
		}
	}
	return;
}

int solution(string begin, string target, vector<string> words) {
	wordsLen = words.size();
	wordSize = words[0].size();
	vector<bool> check(wordsLen, false);

	checkWord(begin, target, words, 0, check);

	if (answer > 50) return 0;
	else return answer;
}