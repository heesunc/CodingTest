#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    int str = my_string.size();
    
    answer = my_string.substr(str-n, str);
    
    return answer;
}