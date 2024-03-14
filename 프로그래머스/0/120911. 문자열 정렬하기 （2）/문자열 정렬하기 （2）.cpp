#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(char c : my_string)
    {
        c = tolower(c);
        answer += c;
    }  
    
    sort(answer.begin(), answer.end());
    
    return answer;
}