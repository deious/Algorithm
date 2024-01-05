#include <iostream>
#include <stack>

using namespace std;

int arr[10] = { 0, 1, 2, -1, -1, 5, 9, -1, 8, 6 };		// �������� ���ڵ鿡 ���� ���� 3, 4, 7�� �������� ���ڰ� �ƴϹǷ� -1�� ó��

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

bool ReCalculate(long long N)	// �������� �� �������� ���ڷ� ������ �����Ѱ� + �������� ��� � ���ڰ� �����°�
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

	if (Calculate(N))				// ó�� ���ڰ� �Ҽ��ΰ�?
	{
		if (ReCalculate(N))			// ���ڸ� �Ųٷ� �Ҷ� �������� ���ڷ� ��ȯ�� �����Ѱ�?
		{
			if (Calculate(temp))	// ������ ���ڰ� �Ҽ��ΰ�?
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