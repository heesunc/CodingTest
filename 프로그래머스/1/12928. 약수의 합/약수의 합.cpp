#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int i=1;
    while(i<=n) // i가 n보다 작거나 같을 때까지
    {
        if(n % i == 0) // n를 i로 나눈 나머지가 0일때
        {
            answer += i; // answer에 i값을 더해감
        }
        i++;
    }
    return answer;
}