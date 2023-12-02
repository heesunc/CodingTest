#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int temp;
    
    if (arr.size() == 1)
    {
        answer.clear();
        answer.push_back(-1);
    }
    else
    {
        sort(arr.begin(), arr.end());
        
        temp = arr.front(); // temp에 제일 작은 거 넣기
        
        for(int i=0; answer.size(); i++)
        {
            if (temp == answer[i])
            {
                answer.erase(answer.begin() + i);
                break;
            }
        }
    }
    
    return answer;
}