#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int gob=1; int hob=0;
    
    for (int i=0; i<num_list.size(); i++)
    {
        gob *= num_list[i];
        hob += num_list[i];
    }
    
    if (gob < hob*hob)
    {
        answer = 1;
    }
    else
    {
        answer = 0;
    }
    
    return answer;
}