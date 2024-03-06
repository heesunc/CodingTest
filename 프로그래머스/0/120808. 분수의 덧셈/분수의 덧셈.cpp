#include <string>
#include <vector>

using namespace std;

// 프로토타입(함수 선언) 추가
int gcd(int a, int b);

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    // 두 분수의 분모를 서로 곱하여 분모를 통일한 뒤 각각의 분자끼리 더해주면 하나의 분수가 됩니다.
    int numer = numer1 * denom2 + numer2 * denom1;
    int denom = denom1 * denom2;
    
    int gcd1 = gcd(numer, denom);
    
    // 구한 최대공약수를 각각 나눠줌
    numer /= gcd1;
    denom /= gcd1;
    
    answer.push_back(numer);
    answer.push_back(denom);
    
    return answer;
}

// 이렇게 더한 분수를 최대공약수를 별도로 구함
int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}