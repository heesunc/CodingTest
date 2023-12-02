#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    const size_t length = s.length();
    
    if (length % 2 == 0) // 짝수
    {
        answer += s[length / 2 - 1];
        answer += s[length / 2];
    }
    else // 홀수
    {
        answer += s[length/2];
    }
    
    return answer;
}