#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int sum = 0;
    
    do{
        answer = n%10;
        sum=sum+answer;
        n=n/10;
    }
    while(n!=0);

    return sum;
}