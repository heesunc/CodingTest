#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    for(int i=0; i<=n; i++)
    {
        if (i % 2 != 0) // 홀수라면
        {
            answer.push_back(i);
        }
    }
    
    // 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}