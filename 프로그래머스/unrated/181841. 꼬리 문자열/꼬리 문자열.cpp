#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    
    for(const auto& str : str_list)
    {
        // ex에 해당하는 값을 찾지 못했을 때
        if(str.find(ex) == string::npos) 
            answer += str;
    }
    
    return answer;
}