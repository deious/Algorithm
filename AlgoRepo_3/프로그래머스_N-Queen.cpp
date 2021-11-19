#include <string>
#include <vector>
#include <cstdlib>

int row[13];
int last = 0;
int answer = 0;

using namespace std;

bool MoveCheck(int r)
{
	for (int i = 0; i < r; i++)
	{
		if (row[i] == row[r] || abs(row[r] - row[i]) == (r - i))
			return false;
	}

	return true;
}

void QueenCheck(int r)
{
	if (r == last)
		answer++;
	else
	{
		for (int i = 0; i < last; i++)
		{
			row[r] = i;
			if (MoveCheck(r))
				QueenCheck(r + 1);
			row[r] = 0;
		}
	}

	return;
}

int solution(int n) {
	last = n;
	QueenCheck(0);
	return answer;
}