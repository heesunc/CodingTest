#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            answer++;
            if (i != n / i) // 중복 제거
                answer++;
        }
    }

    return answer;
}