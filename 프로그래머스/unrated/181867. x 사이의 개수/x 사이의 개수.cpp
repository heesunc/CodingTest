#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int xpos;

    while ((xpos = myString.find('x')) != string::npos) {
        answer.push_back(xpos);
        myString = myString.substr(xpos + 1);
    }

    // 마지막 x 이후의 문자열 길이 추가
    answer.push_back(myString.size());

    return answer;
}
