#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    istringstream ss(my_string);
    string token;
    
    while (ss >> token) // ss에서 공백 기준으로 단어읽음
    {
        answer.push_back(token);
    }  
    
    return answer;
}