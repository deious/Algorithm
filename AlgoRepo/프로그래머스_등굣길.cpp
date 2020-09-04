#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[101][101];
bool water[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int len = puddles.size();
    
    for(int i = 1; i <= 100; i++)
    {
        dp[1][i] = 1;
        dp[i][1] = 1;
    }
    
    for(int i = 0; i < len; i++)
    {
        water[puddles[i][1]][puddles[i][0]] = true;
    }
    
    int start = 0;
    for(int i = 1; i <= m; i++)
    {
        if (water[1][i])
        {
            for (; i <= m; i++)
            {
                dp[1][i] = 0;
            }
        }
    }
    
    start = 0;
    for(int i = 1; i <= n; i++)
    {
        if (water[i][1])
        {
            for (; i <= n; i++)
            {
                dp[i][1] = 0;
            }
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        for(int j = 2; j <= m; j++)
        {
            if(!water[i][j])
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
            }
        }
    }

    return answer = dp[n][m];
}