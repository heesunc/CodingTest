#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer = arr;
    // 최대값 구하기
    int max_size = max(arr.size(), arr[0].size());
    
    // 2차원 배열 값안에 넣어주기 위해 vector<int>
    // answer의 모든 행을 max_size만큼 0으로 채움
    for (vector<int>& row : answer)
    {
        // row를 max_size만큼 0을 넣어 resize 시켜줌
        row.resize(max_size, 0);
    }
    
    // 새로운 행을 추가
    while (answer.size() < max_size)
    {
        answer.push_back(vector<int>(max_size,0));
    }
    
    return answer;
}