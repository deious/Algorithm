#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int index = 0;
    string saveAlphabet = "";
    
    for(int i = 0; i < name.size(); i++)
    {
        saveAlphabet += 'A';
    }
    
    while(saveAlphabet != name)
    {
        if(name[index] != 'A' && name[index] != saveAlphabet[index])
        {
            if('N' - name[index] > 0)
            {
                answer += name[index] - 'A';
                saveAlphabet[index] = name[index];
            }
            else if('N' - name[index] < 0)
            {
                answer += 'Z' - name[index] + 1;
                saveAlphabet[index] = name[index];
            }
            else
            {
                answer += 13;
                saveAlphabet[index] = name[index];
            }
        }
        else
        {
            int leftIndex = index, rightIndex = index;
            int leftCount = 0, rightCount = 0;
            while(1)
            {
                rightIndex++, rightCount++;
                leftIndex--, leftCount++;
                
                if(rightIndex >= name.size()) rightIndex = 0;
                if(leftIndex < 0) leftIndex = name.size() - 1;
                
                if(name[rightIndex] != 'A'&& name[rightIndex] != saveAlphabet[rightIndex])
                {
                    index = rightIndex;
                    answer += rightCount;
                    break;
                }
                else if(name[leftIndex] != 'A' && name[leftIndex] != saveAlphabet[leftIndex])
                {
                    index = leftIndex;
                    answer += leftCount;
                    break;
                }
            }
        }
    }
    return answer;
}