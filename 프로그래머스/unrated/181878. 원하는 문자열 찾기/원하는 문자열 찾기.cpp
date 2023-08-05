#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    int myStringLen = myString.length();
    int patLen = pat.length();
    
    for(int i=0; i<=myStringLen - patLen; i++)
    {
        bool match = true;
        for(int j=0; j<patLen; j++)
        {
            if (tolower(myString[i+j]) != tolower(pat[j]))
            {
                match = false;
                break;
            }
        }
        if (match)
            answer = 1;
    }
    
    return answer;
}