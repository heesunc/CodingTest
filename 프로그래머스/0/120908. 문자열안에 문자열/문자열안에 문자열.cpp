#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;    
    
    int n = str1.find(str2); // 문자열 비교
    if (n != string::npos) // 문자열을 찾았는지 검사
        answer = 1;
    else
        answer = 2;
    
    return answer;
}