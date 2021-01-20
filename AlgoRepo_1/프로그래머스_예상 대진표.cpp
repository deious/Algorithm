int solution(int n, int a, int b)
{
	int answer = 0;

	while (a != b)
	{
		if (a % 2 == 0) a = a >> 1;
		else a = (a >> 1) + 1;

		if (b % 2 == 0) b = b >> 1;
		else b = (b >> 1) + 1;

		answer++;
	}
	return answer;
}