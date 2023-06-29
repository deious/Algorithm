#include <math.h>

int Calculate(int cur, int plus)
{
	int result = 0;

	if (cur < 1 || 2 * log(cur) / log(3) < plus)
		return 0;

	if (cur == 3 && plus == 2)
		return 1;

	if (cur % 3 == 0 && plus >= 2)
		result += Calculate(cur / 3, plus - 2);

	result += Calculate(cur - 1, plus + 1);

	return result;
}

int solution(int n) {
	return Calculate(n - 2, 2);
}
