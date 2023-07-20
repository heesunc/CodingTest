#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    int a1 = intervals[0][0];
    int b1 = intervals[0][1];
    int a2 = intervals[1][0];
    int b2 = intervals[1][1];
    
    for(int i=a1; i<=b1; i++)
    {
        answer.push_back(arr[i]);
    }
    
    for(int i=a2; i<=b2; i++)
    {
        answer.push_back(arr[i]);
    }
    
    return answer;
}