#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for (const string& str : intStrs)
    {
        string subStr = str.substr(s, l);
        int num = stoi(subStr);
        if (num > k)
            answer.push_back(num);
    }
    
    return answer;
}