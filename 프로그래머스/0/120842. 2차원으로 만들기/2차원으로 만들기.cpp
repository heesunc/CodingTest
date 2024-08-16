#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> result;
    
    for (int i = 0; i < num_list.size(); i += n) {
        // i부터 n개의 원소를 가져와서 새로운 vector를 만든다.
        vector<int> row(num_list.begin() + i, num_list.begin() + i + n);
        result.push_back(row);
    }
    
    return result;
}