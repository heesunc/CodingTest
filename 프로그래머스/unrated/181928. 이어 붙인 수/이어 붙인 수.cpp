#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int oddsum=0;
    int evensum=0;
    
    for (int num : num_list)
    {
        if (num % 2 == 0)
        {
            evensum = evensum * 10 + num;
        }
        else
        {
            oddsum = oddsum * 10 + num;
        }
    }
    answer = oddsum + evensum;  
    return answer;
}