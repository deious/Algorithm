#include <iostream>
#include <vector>

using namespace std;

bool PrimeCheck(int num)
{
	if (num == 0 || num == 1) return false;

	for (int i = 2; i < num / 2; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}

int solution(vector<int> nums) {
	int answer = 0;
	int len = nums.size();

	for (int i = 0; i < len - 2; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			for (int k = j + 1; k < len; k++)
			{
				if (PrimeCheck(nums[i] + nums[j] + nums[k])) answer++;
			}
		}
	}

	return answer;
}