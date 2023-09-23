#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    unordered_map<int, int> lengthCounts;
    int answer = 0;
    
    for (const auto& str : strArr)
    {
        lengthCounts[str.size()]++;
    }
    
    for (const auto& pair : lengthCounts)
    {
        answer = max(answer, pair.second);
    }
    
    return answer;
}