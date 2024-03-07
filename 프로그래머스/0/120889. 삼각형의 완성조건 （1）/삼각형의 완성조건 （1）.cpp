#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {    
    // 가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 합니다.
    // 세 변으로 삼각형을 만들 수 있다면 1, 만들 수 없다면 2를 return
    int max = *max_element(sides.begin(), sides.end());
    sides.erase(remove(sides.begin(), sides.end(), max), sides.end());
    
    int sum = sides[0] + sides[1];
    
    if (max < sum)
        return 1;
    else
        return 2;
}