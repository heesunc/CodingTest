#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    
    // 나머지 문자열 처리
    int len = my_str.size();
    int i = 0;
    while (i < len) {
        string s = my_str.substr(i, n);
        answer.push_back(s);
        i += n;
    }
    
    return answer;
}