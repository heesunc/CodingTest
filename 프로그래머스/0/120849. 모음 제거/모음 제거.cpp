#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (char c : my_string) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            answer += c;
        }
    }
    return answer;
}