#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    int start = 0;
    
    for (int i = 0; i < myString.size(); ++i) {
        if (myString[i] == 'x') {
            if (start < i) {
                answer.push_back(myString.substr(start, i - start));
            }
            start = i + 1;
        }
    }
    
    if (start < myString.size()) {
        answer.push_back(myString.substr(start));
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
