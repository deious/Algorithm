#include <string>
#include <vector>

long long dp[5001];

using namespace std;

int solution(int n) {
    dp[0] = 1;
    dp[2] = 3;
    
    for(int i = 4; i <= n; i ++)
    {
        if(i % 2 == 0)
        {
            dp[i] = dp[i - 2] * 3;
            
            for(int j = i - 4; j >= 0; j -= 2)
            {
                dp[i] += dp[j] * 2;
            }
            
            dp[i] %= 1000000007;
        }
        else dp[i] = 0;       
    }
    
    return dp[n];
}