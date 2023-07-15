#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";    
    
    for(int i = 0; i < my_strings.size(); i++) {
        string str = my_strings[i];
        vector<int> part = parts[i];
        int start = part[0];
        int end = part[1];
        string substring = str.substr(start, end - start + 1);
        answer += substring;
    }
    
    
    return answer;
}