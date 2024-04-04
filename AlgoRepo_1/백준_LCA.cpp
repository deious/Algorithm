#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> v(50001);
int parent[50001];
int depth[50001];
bool check[50001];

void DFS(int cur, int deep)
{
    check[cur] = 1;
    depth[cur] = deep;

    for (auto nxt : v[cur])
    {
        if (check[nxt])
        {
            continue;
        }
        parent[nxt] = cur;
        DFS(nxt, deep + 1);
    }
}

int LCA(int a, int b)
{
    while (depth[a] != depth[b])
    {
        if (depth[a] > depth[b])
        {
            a = parent[a];
        }
        else
        {
            b = parent[b];
        }
    }

    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1, 0);

    int m;
    cin >> m;

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        cout << LCA(x, y) << '\n';
    }

    return 0;
}