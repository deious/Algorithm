#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string Convert(int n, int k)
{
	string s = "";
	while (n != 0)
	{
		s.push_back((n % k) + '0');
		n /= k;
	}

	reverse(s.begin(), s.end());

	return s;
}

bool PrimeCheck(long long n)
{
	if (n < 2)
		return false;

	for (long long i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int solution(int n, int k) {
	int answer = 0;
	string s = Convert(n, k);
	int len = s.size();
	string temp = "";
	long long lln = 0;

	for (int i = 0; i < len; i++)
	{
		if (s[i] == '0' && !temp.empty())
		{
			lln = stoll(temp);
			if (PrimeCheck(lln))
				answer++;
			temp = "";
		}
		else
			temp.push_back(s[i]);
	}

	if (!temp.empty())
	{
		lln = stoll(temp);
		if (PrimeCheck(lln))
			answer++;
	}

	return answer;
}