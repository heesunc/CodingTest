#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    int z=0;
    for(int i=0; i<n; i++)
    {
        z = z + x;
        answer.push_back(z);
    }
    
    return answer;
}