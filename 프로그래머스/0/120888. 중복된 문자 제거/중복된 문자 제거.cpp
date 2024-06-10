#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string my_string) {
    string answer = "";
    unordered_set<char> c;
    
    for(char ch : my_string)
    {
        if(c.find(ch) == c.end())
        {
            c.insert(ch);
            answer += ch;
        }
    }
    
    return answer;
}