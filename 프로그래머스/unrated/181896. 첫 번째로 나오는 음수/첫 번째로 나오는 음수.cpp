#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    for (int i=0; i<=num_list.size(); i++)
    {
        if (num_list[i] < 0) // 0보다 작으면 음수니까..
        {
            return answer = i;
        }
    }
    
    return answer = -1;
}