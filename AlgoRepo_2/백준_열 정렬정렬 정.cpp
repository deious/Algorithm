#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> arr(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int swapCount = 0;

    for (int i = 0; i < N; i++)
    {
        if (visited[i] || arr[i].second == i)
        {
            continue;
        }

        int cycleSize = 0;
        int j = i;

        while (!visited[j]) 
        {
            visited[j] = true;
            j = arr[j].second;
            cycleSize++;
        }

        if (cycleSize > 1) 
        {
            swapCount += (cycleSize - 1);
        }
    }

    cout << swapCount << "\n";

    return 0;
}