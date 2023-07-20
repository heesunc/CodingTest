#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
    for(int i=0; i<query.size(); i++)
    {
        if (i % 2 ==0) // 짝수 인덱스라면
        {
            // query[i]번 인덱스 뒷부분 잘라내기
            if(query[i]+1 < arr.size())
            {
                arr.erase(arr.begin() + query[i] + 1, arr.end());
            }
        }
        else
        {
            // 홀수에서는 query[i]번 인덱스 앞부분 잘라냄
            if(query[i] > 0)
            {
                arr.erase(arr.begin(), arr.begin() + query[i]);
            }
        }
    }
    answer = arr;
    return answer;
}