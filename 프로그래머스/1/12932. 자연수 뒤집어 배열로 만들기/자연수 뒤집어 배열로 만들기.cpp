#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int a = 0;
    
    do
    {
        a = n % 10;
        answer.push_back(a);
        n = n / 10;
    }
    while (n!=0);
    
    return answer;
}