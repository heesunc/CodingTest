#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    
    for(int i=0; i<flag.size(); i++)
    {
        // X의 뒤에 arr[i]를 arr[i]x2 추가
        if(flag[i] == true)
        {
            for(int j=0; j<arr[i]*2; j++)
            {
                answer.push_back(arr[i]);
            }                
        }
        else if (flag[i] == false)
        {
            for(int j=0; j<arr[i]; j++)
            {
                 answer.pop_back();
            }             
        }
    }
    
    return answer;
}