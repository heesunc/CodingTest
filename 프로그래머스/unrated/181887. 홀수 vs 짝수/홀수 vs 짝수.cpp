#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int size = num_list.size();
    int h = 0;
    int z = 0;
    
    for(int i=0; i<size; i+=2)
    {
        h += num_list[i];
    }
    
    for(int j=1; j<size; j+=2)
    {
        z += num_list[j];
    }
    
    if (h > z)
        answer = h;
    else 
        answer = z;
    
    return answer;
}