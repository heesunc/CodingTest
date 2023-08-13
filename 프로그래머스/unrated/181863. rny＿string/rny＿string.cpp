#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    string rn = "rn";    
    
    for(char& ch : rny_string)
    {
        if (ch == 'm')
            answer += rn;
        else
            answer += ch;
    }
    
    return answer;
}