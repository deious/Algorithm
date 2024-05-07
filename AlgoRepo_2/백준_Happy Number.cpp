#include <iostream>
#include <set>

using namespace std;

int CalculateSquare(int n)
{
    int sum = 0, temp = 0;
    while (n > 0)
    {
        temp = n % 10;
        sum += (temp * temp);
        n /= 10;
    }

    return sum;
}

bool IsHappy(int n) {

    set<int> duplication;
    while (n != 1)
    {
        if (!duplication.insert(n).second)
        {
            return false;
            break;
        }

        n = CalculateSquare(n);
    }

    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

    if (IsHappy(n))
    {
        cout << "HAPPY\n";
    }
    else
    {
        cout << "UNHAPPY\n";
    }

    return 0;
}