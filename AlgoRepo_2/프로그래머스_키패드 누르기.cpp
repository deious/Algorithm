#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";

	int len = numbers.size();
	int lPos = 10;
	int rPos = 12;
	for (int i = 0; i < len; i++)
	{
		if (numbers[i] == 0)
			numbers[i] = 11;

		if (numbers[i] % 3 == 0)
		{
			rPos = numbers[i];
			answer.push_back('R');
		}
		else if (numbers[i] % 3 == 1)
		{
			lPos = numbers[i];
			answer.push_back('L');
		}
		else
		{
			int lPosX = (lPos - 1) / 3;
			int lPosY = (lPos - 1) % 3;
			int rPosX = (rPos - 1) / 3;
			int rPosY = (rPos - 1) % 3;
			int nPosX = (numbers[i] - 1) / 3;
			int nPosY = (numbers[i] - 1) % 3;
			int lDis = abs(lPosX - nPosX) + abs(lPosY - nPosY);
			int rDis = abs(rPosX - nPosX) + abs(rPosY - nPosY);

			if (lDis > rDis)
			{
				rPos = numbers[i];
				answer.push_back('R');
			}
			else if (lDis < rDis)
			{
				lPos = numbers[i];
				answer.push_back('L');
			}
			else
			{
				if (hand == "left")
				{
					lPos = numbers[i];
					answer.push_back('L');
				}
				else
				{
					rPos = numbers[i];
					answer.push_back('R');
				}
			}
		}
	}
	return answer;
}