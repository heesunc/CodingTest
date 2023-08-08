#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(char& ch : myString)
    {
        answer += tolower(ch);
    }
    
    return answer;
}