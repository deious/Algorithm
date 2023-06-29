#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int len = arr.size();
    int temp = arr[0];
    int count = 0;

    for(int i = 1; i < len; i++)
    {
        if(temp == arr[i])
        {
            temp = arr[i];
            count++;
        }
        else
        {
            answer.push_back(temp);
            temp = arr[i];
            count = 0;
        }
    }
    
    answer.push_back(arr[len - 1]);
    
    return answer;
}