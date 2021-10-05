#include <string>

using namespace std;

string solution(int n, int t, int m, int p) {
	string answer = "";
	string number[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

	int aLen = 0;
	int maxLen = t * m;
	int index = 0;

	string tempString = "";
	while (aLen < maxLen)
	{
		string temp = "";
		int num = index;
		bool check = false;
		while (!check)
		{
			if (num / n == 0)
				check = true;
			temp.insert(0, number[num % n]);
			num /= n;
		}

		aLen += temp.size();
		tempString += temp;
		index++;
	}

	int playCount = 0;
	for (int i = p - 1; playCount < t; i += m)
	{
		answer += tempString[i];
		playCount++;
	}

	return answer;
}