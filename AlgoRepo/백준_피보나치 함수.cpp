#include <cstdio>

using namespace std;

int dp[41];

int main()
{
	int t;
	scanf("%d", &t);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < 41; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	while (t--)
	{
		int num;
		scanf("%d", &num);
		if (num == 0)
		{
			printf("1 0\n");
		}
		else if (num == 1)
		{
			printf("0 1\n");
		}
		else printf("%d %d\n", dp[num - 2], dp[num - 1]);
	}

	return 0;
}