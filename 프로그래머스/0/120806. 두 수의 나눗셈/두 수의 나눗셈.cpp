#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    double ans = (double)num1 / num2;
    answer = ans * 1000;
    return answer;
}