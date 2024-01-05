#include <iostream>
#include <stack>

using namespace std;

int arr[10] = { 0, 1, 2, -1, -1, 5, 9, -1, 8, 6 };		// 뒤집혀진 숫자들에 대한 내용 3, 4, 7은 뒤집히면 숫자가 아니므로 -1로 처리

long long temp;

bool Calculate(long long num)
{
	if (num == 1)
	{
		return false;
	}
	if (num == 2)
	{
		return true;
	}

	for (long long i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

bool ReCalculate(long long N)	// 뒤집었을 때 정상적인 숫자로 변경이 가능한가 + 정상적일 경우 어떤 숫자가 나오는가
{
	stack<int> s;
	while (N != 0)
	{
		int t = N % 10;
		N /= 10;
		s.push(t);

		if (N == 0)
		{
			break;
		}
	}

	int len = s.size();
	long long tempNum = 1, check = 0;
	long long reverse = 0;
	for (int i = 0; i < len; i++)
	{
		check = arr[s.top()] * tempNum;
		s.pop();
		if (check < 0)
		{
			return false;
		}
		else
		{
			reverse += check;
			tempNum *= 10;
		}
	}
	
	temp = reverse;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long N;
	cin >> N;

	if (Calculate(N))				// 처음 숫자가 소수인가?
	{
		if (ReCalculate(N))			// 숫자를 거꾸로 할때 정상적인 숫자로 변환이 가능한가?
		{
			if (Calculate(temp))	// 뒤집힌 숫자가 소수인가?
			{
				cout << "yes";
				return 0;
			}
			else
			{
				cout << "no";
				return 0;
			}
		}
		else
		{
			cout << "no";
			return 0;
		}
	}
	else
	{
		cout << "no";
		return 0;
	}

	return 0;
}