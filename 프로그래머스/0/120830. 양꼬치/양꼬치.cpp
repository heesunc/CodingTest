#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    int sheep = 12000; int can = 2000;
    int service = 0;
    
    service = n / 10;
    
    // 양꼬치 n, 음료수 k
    answer = (n * sheep) + (k * can) - (service * can);
    
    return answer;
}