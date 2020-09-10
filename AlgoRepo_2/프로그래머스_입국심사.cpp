#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    int len = times.size();
    
    sort(times.begin(), times.end());
    
    long long left = 1;
    long long right = (long long)times[len - 1] * n;
    answer = right;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = 0;
        
        for(int i = 0; i < len; i++)
        {
            count += (mid / times[i]);
        }
        
        if(count < n) left = mid + 1;
        else
        {
            if(answer >= mid) answer = mid;
            right = mid - 1;
        }
    }
    
    return answer;
}