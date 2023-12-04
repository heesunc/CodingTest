#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    
    // 공백 기준으로 나누고
    for(int i=0; i<s.length(); i++)
    {
        if (s[i] == ' ')
        {
            index = 0;
            continue;
        }
        // 짝홀수 나누고 짝->대, 홀->수 변환
        if (index % 2 == 1)
        {
            if ('A' <= s[i] && s[i] <= 'Z')
            {
                s[i] += 32;
            } 
        }
        else
        {
            if ('a' <= s[i] && s[i] <= 'z')
            {
                s[i] -= 32;
            }
        }
        index++;
    }
    
    return answer = s;
}