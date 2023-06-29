#include <string>

using namespace std;

int answer[3];

int solution(string dartResult) {
	int len = dartResult.size();
	int index = 0;
	int result = 0;
	int i = 0;
	while (index < len)
	{
		if (isdigit(dartResult[index]) != 0)
		{
			if (dartResult[index + 1] == '0')
			{
				answer[i] = 10;
				index += 2;
				i++;
			}
			else
			{
				answer[i] = dartResult[index] - '0';
				index++;
				i++;
			}
		}
		else
		{
			if (dartResult[index] == 'D')
				answer[i - 1] *= answer[i - 1];
			else if (dartResult[index] == 'T')
				answer[i - 1] *= answer[i - 1] * answer[i - 1];
			else if (dartResult[index] == '*')
			{
				if (i == 1)
					answer[0] *= 2;
				else
				{
					for (int j = i - 2; j < i; j++)
						answer[j] *= 2;
				}
			}
			else if (dartResult[index] == '#')
				answer[i - 1] *= -1;

			index++;

		}
	}

	for (int i = 0; i < 3; i++)
		result += answer[i];

	return result;
}