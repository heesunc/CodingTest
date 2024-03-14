#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // n명이 주문한 피자를 남기지 않고 모두 같은 수의 피자 조각을 먹어야 한다
    
    int pizza = 0;
    int cut = 6;
    
    while (cut % n != 0)
    {
        cut += 6;
    }
    
    pizza = cut / 6;
    
    return pizza;
}