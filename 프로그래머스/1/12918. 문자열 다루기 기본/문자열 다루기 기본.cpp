#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    const size_t length = s.length();

    // s의 길이가 4 또는 6인지
    if (length == 4 || length == 6)
    {
        // 숫자로만 구성되어 있는지
        for (int i = 0; i < length; i++)
        {
            if (!isdigit(s[i])) {
                answer = false;
                break;  // 하나라도 숫자가 아니면 루프 탈출
            }
        }
    }
    else
        answer = false;

    return answer;
}