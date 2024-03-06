#include <string>
#include <vector>

using namespace std;
string solution(string rsp) {
    string answer = "";

    // 가위 2, 바위 0, 보 5
    for (char ans : rsp)
    {
        if (ans == '2') // 가위
            answer += '0';
        else if (ans == '0') // 바위
            answer += '5';
        else if (ans == '5') // 보
            answer += '2';
    }

    return answer;
}