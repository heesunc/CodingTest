#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    int d = 0;
    
    for(char c : my_string)
    {
        if (isdigit(c)) // c가 숫자형인지 확인
            answer.push_back(c - '0'); // int로 바꿔서 push
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}