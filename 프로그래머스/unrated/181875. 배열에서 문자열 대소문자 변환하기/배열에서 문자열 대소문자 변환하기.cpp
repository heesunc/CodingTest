#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer = strArr;
    
    for(int i=0; i<answer.size(); i++)
    {
        if(i % 2 != 0) // 홀수면
        {
            for (int j=0; j<answer[i].length(); j++)
            {
                answer[i][j]=toupper(answer[i][j]);
            }
        }
        else
        {
            for (int j=0; j<answer[i].length(); j++)
            {
                answer[i][j]=tolower(answer[i][j]);
            }
        }
    }
    return answer;
}