#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[10000001];

int solution(string numbers) {
    int answer = 0;
    int len = numbers.size();
    check[0] = true;
    check[1] = true;
    
    for(int i = 2; i * i <= 10000000; i++)
    {
        if(!check[i])
        {
            for(int j = i * i; j <= 10000000; j += i)
            {
                check[j] = true;
            }
        }
    }
    
    vector<int> v(len), v1;
    
    for(int i = 0; i < len; i++)
    {
        v[i] = numbers[i] - '0';
    }
    
    sort(v.begin(), v.end());
    
    do
    {
        for(int i = 1; i <= len; i++)
        {
            int temp = 0;
            
            for(int j = 0; j < i; j++)
            {
                temp = temp * 10 + v[j];
                v1.push_back(temp);
            }
        }
    }while(next_permutation(v.begin(), v.end()));
    
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()),v1.end());
    
    for(int i = 0; i < v1.size(); i++)
    {
        if(!check[v1[i]]) answer++;
    }
    
    return answer;
}