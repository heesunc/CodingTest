#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (auto c : my_string)
    {
        if (islower(c)) // 소문자라면
            answer += toupper(c);
        else if (isupper(c)) // 대문자라면
            answer += tolower(c);             
    }    
    
    return answer;
}