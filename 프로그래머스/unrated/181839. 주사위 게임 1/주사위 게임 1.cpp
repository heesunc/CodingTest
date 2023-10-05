#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    // a와 b가 모두 홀수라면 a^2 + b^2
    if(a % 2 != 0 && b % 2 != 0)
    {
        answer = pow(a, 2) + pow(b, 2);
    }
    // a와 b중 하나만 홀수라면 2*(a+b)
    else if (a % 2 != 0 || b % 2 != 0)
    {
        answer = 2 * (a + b);
    }
    // a와 b 모두 홀수가 아니라면 |a-b|
    else
    {
        answer = abs(a-b);
    }
    return answer;
}