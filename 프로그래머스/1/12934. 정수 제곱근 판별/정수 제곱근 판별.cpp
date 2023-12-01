#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;    
    bool isPrimeNumber = false;
    
    for(long x = 1; x * x <= n; x++)
    {
        if(x * x == n)
        {
            isPrimeNumber = true;
            answer = x;
        }
    }

    if(isPrimeNumber)
    {
        answer = (answer + 1) * (answer + 1);
        return answer;
    }
    else
    {
        return -1;
    }
}