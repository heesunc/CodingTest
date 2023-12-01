#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int xx = x;
    int n =0;
    int sum=0;
    
    // x의 자릿수의 합으로 x가 나누어져야 하샤드 수    
    do
    {
        n = xx % 10;
        sum = sum + n;
        xx = xx / 10;
    } while (xx != 0);
    
    if (x % sum == 0)
        answer = true;
    else
        answer = false;
    
    return answer;
}