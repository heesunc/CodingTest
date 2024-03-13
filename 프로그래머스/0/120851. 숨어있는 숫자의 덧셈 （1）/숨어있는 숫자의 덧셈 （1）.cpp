#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for (char c : my_string) {
        if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||
            c == '6' || c == '7' || c == '8' || c == '9')
        {
            answer += c - '0';
        }
    }
    
    return answer;
}