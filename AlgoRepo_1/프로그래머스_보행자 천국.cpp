#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int right[501][501];
    int down[501][501];
    
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            right[i][j] = 0;
            down[i][j] = 0;
        }
    }
    
    right[1][1] = 1;
    down[1][1] = 1;
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 && j == 1) continue;
            
            int data = city_map[i - 1][j - 1];
            
            if(data == 0)
            {
                right[i][j] = (right[i][j - 1] + down[i - 1][j]) % MOD;
                down[i][j] = (right[i][j - 1] + down[i - 1][j]) % MOD;
            }
            else if(data == 1)
            {
                right[i][j] = 0;
                down[i][j] = 0;
            }
            else
            {
                right[i][j] = right[i][j -1];
                down[i][j] = down[i - 1][j];
            }
        }
    }
    
    return right[m][n];
}