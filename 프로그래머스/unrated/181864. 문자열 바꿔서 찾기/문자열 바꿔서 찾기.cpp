#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    string newstr="";
    int patSize = pat.size();
    
    // myString에서 A를 찾고 B를 찾아서 replace해주어야함
    for (char& ch : myString)
    {
        if (ch == 'A')
            newstr += 'B';
        else if (ch == 'B')
            newstr += 'A';
        else
            newstr += ch;
    }
    
    int strSize = newstr.size();
    
    for (int i=0; i<=strSize - patSize; ++i)
    {
        if (newstr.substr(i, patSize) == pat)
            answer = 1;
    }
    
    return answer;
}