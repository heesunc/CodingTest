#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int arrsize = num_list.size();
    
    if (num_list[arrsize - 1] > num_list[arrsize - 2])
        num_list.push_back(num_list[arrsize - 1] - num_list[arrsize - 2]);
    else
        num_list.push_back(num_list[arrsize - 1] * 2);
    
    answer = num_list;
    return answer;
}
