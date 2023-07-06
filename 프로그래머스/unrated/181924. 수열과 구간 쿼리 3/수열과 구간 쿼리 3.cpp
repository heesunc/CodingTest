#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {    
    for(const auto& query : queries)
    {
        int i = query[0];
        int j = query[1];
        
        // 임시변수 temp 사용
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    return arr;
}