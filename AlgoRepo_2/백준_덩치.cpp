#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, x, y;
    cin >> N;

    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }

    int cnt;
    for (int i = 0; i < N; i++)
    {
        cnt = 1;
        for (int j = 0; j < N; j++)
        {
            if (v[i].first < v[j].first && v[i].second < v[j].second)
            {
                cnt++;
            }
        }
        cout << cnt << " ";
    }

    return 0;
}