#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

double CCW(double a, double b, double c, double d, double e, double f) 
{
	double ans = a * e + b * f + c * d;
	ans += (-d * b - e * c - f * a);

	return ans / 2;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; 
	cin >> n;
	vector<pair<double, double>> v(n);

	double a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v[i].first = a;
		v[i].second = b;
	}

	double ans = 0;
	for (int i = 1; i < n; i++)
		ans += CCW(v[0].first, v[i - 1].first, v[i].first, v[0].second, v[i - 1].second, v[i].second);

	cout << fixed;
	cout.precision(1);
	cout << abs(ans) << "\n";

	return 0;
}