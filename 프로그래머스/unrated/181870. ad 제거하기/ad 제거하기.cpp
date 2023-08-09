#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
   
    for (const string& str : strArr)
    {
        // -1은 패턴을 찾지 못했다는 의미
        if (str.find("ad") == -1)
            answer.push_back(str);
    }
    return answer;
}