#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(char& ch : myString)
    {
        if(ch=='a')
            answer += toupper(ch);
        else if(ch!='A')
            answer += tolower(ch);
        else
            answer += ch;
    }
    
    return answer;
}