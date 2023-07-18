#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) {
    string answer = "";
    vector<string> str;
    string strs = "";
    int index = code.length();
    
    for(int i=0; i<index; i++)
    {
        if (i % q == r) {
            strs += code[i];
            str.push_back(strs);
            strs = "";  // strs 초기화
        }
    }
    
    for(const string&s : str)
    {
        answer += s;
    }
    
    return answer;
}