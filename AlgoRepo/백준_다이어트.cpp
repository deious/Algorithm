#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int N, mp, mf, ms, mv, answer = 210000000;
vector<int> vec, ans;
vector<tuple<int, int, int, int, int>> food;

void Calculate(int n, int p, int f, int s, int v, int c)
{
    if (n == N)
    {
        if (p >= mp && f >= mf && s >= ms && v >= mv) 
        {
            if (answer > c)
            {
                ans = vec;
                answer = c;
            }
            else if (answer == c && ans > vec)
            {
                ans = vec;
                answer = c;
            }
        }

        return;
    }
    Calculate(n + 1, p, f, s, v, c);
    vec.push_back(n);
    Calculate(n + 1, p + get<0>(food[n]), f + get<1>(food[n]), s + get<2>(food[n]), v + get<3>(food[n]), c + get<4>(food[n]));
    vec.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> mp >> mf >> ms >> mv;

    int a, b, c, d, e;
    for (int i = 0; i < N; i++) 
    {
        cin >> a >> b >> c >> d >> e;
        food.push_back({ a,b,c,d,e });
    }

    Calculate(0, 0, 0, 0, 0, 0);

    if (answer == 210000000)
    {
        cout << "-1\n";
        return 0;
    }

    cout << answer << "\n";

    int len = ans.size();
    for (int i = 0; i < len; i++)
    {
        cout << ans[i] + 1 << " ";
    }

    return 0;
}