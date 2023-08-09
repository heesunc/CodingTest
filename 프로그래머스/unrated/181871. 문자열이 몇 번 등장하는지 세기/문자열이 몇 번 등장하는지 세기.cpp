#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    int patSize = pat.size();
    
    for (int i=0; i<=myString.size() - patSize; ++i)
    {
        if (myString.substr(i, patSize) == pat)
        {
            ++answer;
        }
    }
    
    return answer;
}