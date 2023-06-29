#include <string>

using namespace std;

string word;
int len, answer = 0;

void pell(int index, bool even)
{
	int left = index - 1;
	int right = index + 1;
	int tempAns = 1;

	while (left >= 0 && right < len)
	{
		if (word[left--] == word[right++]) tempAns += 2;
		else break;
	}

	if (tempAns > answer) answer = tempAns;

	if (even)
	{
		left = index - 1;
		right = index + 1;
		tempAns = 0;

		if (word[left] != word[index] && word[index] != word[right]) return;

		while (left >= 0 && right < len)
		{
			if (word[left--] == word[index++]) tempAns += 2;
			else break;
		}

		if (tempAns > answer) answer = tempAns;

		left = index - 1;
		right = index + 1;
		tempAns = 0;

		while (left >= 0 && right < len)
		{
			if (word[index--] == word[right++]) tempAns += 2;
			else break;
		}

		if (tempAns > answer) answer = tempAns;
	}
}

int solution(string s)
{
	word = s;
	len = s.size();
	bool evenCheck = true;

	if (len % 2) evenCheck = false;

	for (int i = 0; i < len; i++) pell(i, evenCheck);

	return answer;
}