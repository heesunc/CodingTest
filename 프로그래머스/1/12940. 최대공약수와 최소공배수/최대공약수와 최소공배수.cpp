#include <string>
#include <vector>

using namespace std;

vector<int> solution(int a, int b) {
    vector<int> answer;
    
    int aa = a;
    int bb = b;
    int gcd;
    // 최대공약수
    while (b != 0)
    {
        gcd = a % b;
        a = b;
        b = gcd;
    }
    gcd = a;
    answer.push_back(gcd);

    // 최소공배수
    int lcm = abs(aa * bb) / gcd;
    answer.push_back(lcm);

    return answer;
}