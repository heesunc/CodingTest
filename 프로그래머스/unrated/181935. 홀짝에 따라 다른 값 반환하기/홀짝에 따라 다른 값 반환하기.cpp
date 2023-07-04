#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if (n % 2 != 0) // n이 홀수가 아닐 경우에
    {
        // n 이하의 홀수인 모든 양의 정수의 합을 return
        for(int i=1; i<=n; i+=2)
            answer += i; // 1,3,5,7 ....
    }
    else // 짝수일 경우
    {
        // 모든 양의 정수의 제곱의 합을 return
        for(int i=2; i<=n; i+=2)
            answer += i*i; // 0,2,4 ...
    }
    
    return answer;
}