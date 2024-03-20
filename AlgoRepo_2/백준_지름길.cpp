#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, D;
    cin >> N >> D;

    vector<pair<int, int>> v[10001];
    vector<int> v1(10001);

    int from, to, cost;
    for (int i = 0; i < N; i++) 
    {
        cin >> from >> to >> cost;
        if (to > D)
        {
            continue;
        }

        v[to].push_back({ from, cost });
    }

    for (int i = 1; i <= D; i++)
    {
        v1[i] = v1[i - 1] + 1;
        for (int j = 0; j < v[i].size(); j++)
        {
            v1[i] = min(v1[i], v1[v[i][j].first] + v[i][j].second);
        }

    }

    cout << v1[D] << "\n";

    return 0;
}