#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for(int i=l; i<=r; i++) // i를 l로 정의해서, r 이하이기만 하면 됨
    {
        string str = to_string(i); // int를 str로 변경
        bool isZeroFive = true; // bool 변수 선언
        
        for (char c : str) // c가
        {
            if (c != '0' && c != '5') // 0이나 5가 아니면
            {
                isZeroFive = false; // false
                break;
            }
        }
        if (isZeroFive) // true면
        {
            answer.push_back(i); // 배열에 넣음
        }
    }
    if (answer.empty()) // 배열이 비어있으면
    {
        answer.push_back(-1); // -1
    }
    
    return answer;
}