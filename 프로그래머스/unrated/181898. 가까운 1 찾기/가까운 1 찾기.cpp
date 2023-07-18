#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
    int answer = -1;
    
    for (int i=0; i<arr.size(); i++)
    {
        if(arr[i] == 1 && i >= idx)
        {
            answer = i;            
            break;
        }
    }
    
    return answer;
}