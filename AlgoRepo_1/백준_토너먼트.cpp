#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, kim, im;
	cin >> N >> kim >> im;

	int ans = 0;
	while (kim != im)
	{
		kim = (kim + 1) / 2;
		im = (im + 1) / 2;
		ans++;
	}

	cout << ans << "\n";

	return 0;
}