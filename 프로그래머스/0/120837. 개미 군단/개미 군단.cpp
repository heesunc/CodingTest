#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    const int antTypes[] = {5, 3, 1};
    int totalAnts = 0;
    
    // 각 개미 유형에 대해 해당 유형의 개미 수를 사용할 수 있는지 계산
    for (int i = 0; i < sizeof(antTypes) / sizeof(antTypes[0]); ++i) {
        // 총 개미 수에 추가하고 남은 체력 포인트(hp)를 업데이트
        totalAnts += hp / antTypes[i];
        // 그 개미를 사용한 후 남은 것
        hp %= antTypes[i];
    }

    return totalAnts;
}