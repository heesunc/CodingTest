#include <string>
#include <vector>

using namespace std;

int solution(int num)
{
    long n = num;
    int answer = 0;
    
    do
    {
        // 입력된 수가 짝수라면 2를 나눈다
        if (n % 2 == 0)
        {
            n = n / 2;
            answer++;
        }            
        // 입력된 수가 홀수라면 3을 곱하고 1을 더한다
        else if (n % 2 != 0)
        {
            n = n * 3 + 1;
            answer++;
        }
    } while (n != 1);
    
    if (answer >= 500)
    {
        answer = -1;
    }        
    else if (num == 1)
    {
        answer = 0;
    }        
    
    return answer;
}