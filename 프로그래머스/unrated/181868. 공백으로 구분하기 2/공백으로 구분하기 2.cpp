#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    istringstream iss(my_string);
    string token;
    
    while (iss >> token)
    {
        answer.push_back(token);
    }    
    
    return answer;
}